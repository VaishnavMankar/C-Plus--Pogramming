#include <mpi.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int m = 0, n = 0;
    vector<int> A, x, y;

    if (rank == 0) 
    {
        // Read matrix file
        ifstream matFile("matrix.txt");
        if (!matFile) 
        {
            cerr << "Error: Cannot open matrix.txt\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        matFile >> m >> n; // first two numbers are dimensions
        A.resize(m * n);
        for (int i = 0; i < m * n; i++) 
        {
            matFile >> A[i];
        }
        matFile.close();

        // Read vector file
        ifstream vecFile("vector.txt");
        if (!vecFile)
        {
            cerr << "Error: Cannot open vector.txt\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        int vecSize;
        vecFile >> vecSize; // first number is vector size
        x.resize(vecSize);
        for (int i = 0; i < vecSize; i++) 
        {
            vecFile >> x[i];
        }
        vecFile.close();

        if (vecSize != n) 
        {
            cerr << "Error: Vector size and matrix columns don't match!\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        y.resize(m, 0);
    }

    // Broadcast m, n to all processes
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Broadcast vector x
    if (rank != 0)
    {
        x.resize(n);
    }
    MPI_Bcast(x.data(), n, MPI_INT, 0, MPI_COMM_WORLD);

    // Divide rows among processes
    int rows_per_proc = m / size;
    int remainder = m % size;
    int start_row = rank * rows_per_proc + min(rank, remainder);
    int local_rows = rows_per_proc + (rank < remainder ? 1 : 0);

    vector<int> localA(local_rows * n);
    vector<int> sendcounts(size), displs(size);

    if (rank == 0) 
    {
        int disp = 0;
        for (int i = 0; i < size; i++)
        {
            int rows = rows_per_proc + (i < remainder ? 1 : 0);
            sendcounts[i] = rows * n;
            displs[i] = disp;
            disp += rows * n;
        }
    }

    MPI_Scatterv(A.data(), sendcounts.data(), displs.data(), MPI_INT, localA.data(), local_rows * n, MPI_INT, 0, MPI_COMM_WORLD);

    // Local computation
    vector<int> localY(local_rows, 0);
    for (int i = 0; i < local_rows; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            localY[i] += localA[i * n + j] * x[j];
        }
    }

    // Gather results
    vector<int> recvcounts(size), rdispls(size);
    if (rank == 0) 
    {
        int disp = 0;
        for (int i = 0; i < size; i++) 
        {
            int rows = rows_per_proc + (i < remainder ? 1 : 0);
            recvcounts[i] = rows;
            rdispls[i] = disp;
            disp += rows;
        }
    }

    if (rank == 0) y.resize(m);
    MPI_Gatherv(localY.data(), local_rows, MPI_INT, y.data(), recvcounts.data(), rdispls.data(), MPI_INT, 0, MPI_COMM_WORLD);

    // Write output
    if (rank == 0) 
    {
        ofstream outFile("result.txt");
        for (int i = 0; i < m; i++)
        {
            outFile << y[i] << endl;
        }
        outFile.close();
        cout << "Result written to result.txt" << endl;
    }

    MPI_Finalize();
    return 0;
}

