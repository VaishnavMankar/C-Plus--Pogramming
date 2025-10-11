#include <iostream>
#include <vector> 
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int VECTOR_SIZE = 4;
    const int ROW_SIZE = 4;

    vector<int> local_row(ROW_SIZE);
    vector<int> vector_b(VECTOR_SIZE);

    vector<int> matrix_a;

    if (rank == 0) {
        matrix_a = {1, 2, 3, 4, 2, 4, 6, 8, 3, 6, 9, 12, 4, 8, 12, 16};
        vector_b = {10, 11, 12, 13};

        cout << "--- Initial Data on Processor 0 ---" << endl;
        cout << "Matrix A:" << endl;
        for (int i = 0; i < matrix_a.size(); i++) {
            cout << matrix_a[i] << "\t";
            if ((i + 1) % 4 == 0) {
                cout << endl;
            }
        }
        cout << "\nVector B:" << endl;
        for (int i = 0; i < vector_b.size(); i++) {
            cout << vector_b[i] << "\t";
        }
        cout << "\n\n--- Results ---" << endl;
    }

    MPI_Scatter(matrix_a.data(), ROW_SIZE, MPI_INT, local_row.data(), ROW_SIZE, MPI_INT,0, MPI_COMM_WORLD);

    MPI_Bcast(vector_b.data(), VECTOR_SIZE, MPI_INT, 0, MPI_COMM_WORLD);

    int local_result = 0;
    for (int i = 0; i < ROW_SIZE; i++) {
        local_result += local_row[i] * vector_b[i];
    }

    cout << "Processor " << rank << " calculated its result: " << local_result << endl;

    MPI_Finalize();
    return 0;
}