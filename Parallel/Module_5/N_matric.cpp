#include <iostream>
#include <vector>
#include <cstdlib> // For rand(), srand(), and atoi()
#include <ctime>   // For time()
#include <mpi.h>

// Use the standard namespace as requested
using namespace std;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Array to hold the dimensions [rows, cols]
    int dims[2];

    // --- Step 1: Root process reads dimensions from command line ---
    if (rank == 0) {
        if (argc < 3) {
            cerr << "Usage: mpirun -np <processes> " << argv[0] << " <rows> <cols>" << endl;
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        dims[0] = atoi(argv[1]); // Number of rows
        dims[1] = atoi(argv[2]); // Number of columns
    }

    // --- Step 2: Broadcast the dimensions to all processes ---
    // Now every process will know the number of rows and columns.
    MPI_Bcast(dims, 2, MPI_INT, 0, MPI_COMM_WORLD);

    int rows = dims[0];
    int cols = dims[1];

    // --- Step 3: Validation ---
    // Check if the rows can be divided evenly among the processes
    if (rows % size != 0) {
        if (rank == 0) {
            cerr << "Error: The number of rows (" << rows << ") must be evenly divisible by the number of processes (" << size << ")." << endl;
        }
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    // --- Step 4: Dynamically calculate workload ---
    // Each process "finds out" how many rows and elements it's responsible for
    int rows_per_proc = rows / size;
    int elements_per_proc = rows_per_proc * cols;

    // The full matrix only needs to be created on the root process
    vector<int> matrix;
    if (rank == 0) {
        matrix.resize(rows * cols);
        srand(time(NULL));
        
        // Fill the matrix with random-looking values
        for (int i = 0; i < rows * cols; ++i) {
            matrix[i] = rand() % 100; // Random values from 0-99
        }
        cout << "--- Initial " << rows << "x" << cols << " Matrix on Processor 0 (showing up to 6x6) ---" << endl;
        for (int i = 0; i < min(rows, 6); ++i) {
            for (int j = 0; j < min(cols, 6); ++j) {
                cout << matrix[i * cols + j] << "\t";
            }
            cout << endl;
        }
        cout << "\n--- Scattering Data ---" << endl;
    }

    // --- Step 5: Prepare receive buffer and scatter data ---
    vector<int> local_rows(elements_per_proc);
    MPI_Scatter(
        matrix.data(),
        elements_per_proc,
        MPI_INT,
        local_rows.data(),
        elements_per_proc,
        MPI_INT,
        0,
        MPI_COMM_WORLD);

    // --- Step 6: Print the data received by each process ---
    cout << "Processor " << rank << " received " << rows_per_proc << " row(s):" << endl;
    for (int i = 0; i < rows_per_proc; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << local_rows[i * cols + j] << "\t";
        }
        cout << endl;
    }

    MPI_Finalize();
    return 0;
};