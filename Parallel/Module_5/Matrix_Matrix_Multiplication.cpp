#include <iostream>
#include <vector>
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Define the dimensions
    const int N = 4; // A 4x4 matrix
    
    // --- Buffers needed by ALL processes ---
    // Each process will receive one row of matrix A
    vector<int> local_A_row(N);
    // Every process will have a full copy of matrix B
    vector<int> matrix_B(N * N);
    // Each process will calculate one row of the result matrix C
    vector<int> local_C_row(N);

    // Master Process (rank 0) will hold the full initial matrices
    vector<int> matrix_A;
    vector<int> final_C_matrix;

    if (rank == 0) {
        // Initialize matrices A and B with hardcoded values
        matrix_A = {
            4, 3, 2, 1,
            5, 3, 4, 5,
            2, 1, 3, 2,
            1, 4, 6, 8
        };
        matrix_B = {
            2, 3, 5, 8,
            8, 7, 3, 6,
            6, 4, 1, 7,
            9, 1, 9, 3
        }; 

        // Resize the final result matrix to be able to receive the data
        final_C_matrix.resize(N * N);

        cout << "--- Initial 4x4 Matrix A ---" << endl;
        for(int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j){
                cout << matrix_A[i*N+j] << "\t";
            }
            cout << endl;
        }
        cout << "\n--- Initial 4x4 Matrix B (Identity Matrix) ---" << endl;
        for(int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j){
                cout << matrix_B[i*N+j] << "\t";
            }
            cout << endl;
        }
    }

    // Step 1: Scatter the rows of matrix A to all processes
    MPI_Scatter(matrix_A.data(), N, MPI_INT,
                local_A_row.data(), N, MPI_INT,
                0, MPI_COMM_WORLD);

    // Step 2: Broadcast the entire matrix B to all processes
    MPI_Bcast(matrix_B.data(), N * N, MPI_INT, 0, MPI_COMM_WORLD);

    // Step 3: Each process calculates its own result row (local_C_row)
    for (int j = 0; j < N; ++j) {
        int sum = 0;
        for (int k = 0; k < N; ++k) {
            // C[i][j] = sum(A[i][k] * B[k][j])
            // local_A_row[k] corresponds to A[i][k]
            // matrix_B[k*N+j] corresponds to B[k][j]
            sum += local_A_row[k] * matrix_B[k * N + j];
        }
        local_C_row[j] = sum;
    }

    // Step 4: Gather all calculated rows (local_C_row) into the final_C_matrix on the master process
    MPI_Gather(local_C_row.data(), N, MPI_INT,
               final_C_matrix.data(), N, MPI_INT,
               0, MPI_COMM_WORLD);

    // Step 5: The master process prints the final result
    if (rank == 0) {
        cout << "\n--- Final Result Matrix C = A * B ---" << std::endl;
        for(int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                cout << final_C_matrix[i*N+j] << "\t";
            }
            cout << endl;
        }
    }

    MPI_Finalize();
    return 0;
}