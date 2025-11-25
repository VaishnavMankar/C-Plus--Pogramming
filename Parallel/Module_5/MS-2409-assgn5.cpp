#include <iostream>
#include <fstream>
#include <vector>
#include <mpi.h>
using namespace std;

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int N = 0; // Matrix dimension (NxN)
    vector<int> A, B, local_A_row, local_C_row, final_C;

    if (rank == 0) {
        // Read first matrix
        ifstream fileA("matrix1.txt");
        if (!fileA) {
            cerr << "Error: Cannot open matrix1.txt\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        fileA >> N; // first number is the dimension
        A.resize(N * N);
        for (int i = 0; i < N * N; i++) fileA >> A[i];
        fileA.close();

        // Read second matrix
        ifstream fileB("matrix2.txt");
        if (!fileB) {
            cerr << "Error: Cannot open matrix2.txt\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        int N2;
        fileB >> N2;
        if (N2 != N) {
            cerr << "Error: Matrix sizes do not match!\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        B.resize(N * N);
        for (int i = 0; i < N * N; i++) fileB >> B[i];
        fileB.close();

        final_C.resize(N * N, 0);

        cout << "Matrix A:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << A[i * N + j] << " ";
            cout << endl;
        }
        cout << "Matrix B:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << B[i * N + j] << " ";
            cout << endl;
        }
    }

    // Broadcast N to all
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Resize buffers for other processes
    if (rank != 0) B.resize(N * N);
    local_A_row.resize(N);
    local_C_row.resize(N, 0);

    // Broadcast full matrix B to everyone
    MPI_Bcast(B.data(), N * N, MPI_INT, 0, MPI_COMM_WORLD);

    // Scatter rows of matrix A
    if (rank == 0)
        MPI_Scatter(A.data(), N, MPI_INT, local_A_row.data(), N, MPI_INT, 0, MPI_COMM_WORLD);
    else
        MPI_Scatter(NULL, N, MPI_INT, local_A_row.data(), N, MPI_INT, 0, MPI_COMM_WORLD);

    // Local computation: each process computes one row of result
    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int k = 0; k < N; k++) {
            sum += local_A_row[k] * B[k * N + j];
        }
        local_C_row[j] = sum;
    }

    // Gather all rows back into final result
    if (rank == 0)
        MPI_Gather(local_C_row.data(), N, MPI_INT, final_C.data(), N, MPI_INT, 0, MPI_COMM_WORLD);
    else
        MPI_Gather(local_C_row.data(), N, MPI_INT, NULL, N, MPI_INT, 0, MPI_COMM_WORLD);

    // Master process writes output
    if (rank == 0) {
        ofstream out("result.txt");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) out << final_C[i * N + j] << " ";
            out << endl;
        }
        out.close();
        cout << "Result written to result.txt" << endl;
    }

    MPI_Finalize();
    return 0;
}
