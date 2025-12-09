#include <mpi.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int N;
    vector<double> mat;
    vector<double> row;
    vector<double> pivot_row;
    vector<double> final_mat;

    // Read matrix from file (rank 0)
    if (rank == 0)
    {
        ifstream file("input.txt");
        if (!file)
        {
            cout << "Unable to open matrix.txt file\n";
            MPI_Finalize();
            return 0;
        }

        file >> N;
        int ROW = N + 1;

        mat.resize(N * ROW);

        for (int i = 0; i < N; i++){
            for (int j = 0; j < ROW; j++){
                file >> mat[i * ROW + j];
            }
        }

        file.close();
    }

    // Broadcast N to all processors
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int ROW = N + 1;

    if (size != N)
    {
        if (rank == 0){
            cout << "Please run program using N processes. Example: mpirun -np 4 ./a.out\n";
        }
        MPI_Finalize();
        return 0;
    }

    row.resize(ROW);
    pivot_row.resize(ROW);

    // Scatter rows to all processors
    MPI_Scatter(mat.data(), ROW, MPI_DOUBLE, row.data(), ROW, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Forward Elimination
    for (int k = 0; k < N; k++)
    {
        if (rank == k)
        {
            for (int j = 0; j < ROW; j++){
                pivot_row[j] = row[j];
            }
        }

        MPI_Bcast(pivot_row.data(), ROW, MPI_DOUBLE, k, MPI_COMM_WORLD);

        if (rank > k)
        {
            double pivot = pivot_row[k];
            double factor = row[k] / pivot;

            for (int j = 0; j < ROW; j++){
                row[j] -= factor * pivot_row[j];
            }
        }
    }

    // Gather all rows
    if (rank == 0){
        final_mat.resize(N * ROW);
    }

    MPI_Gather(row.data(), ROW, MPI_DOUBLE, final_mat.data(), ROW, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Back Substitution (Rank 0)
    if (rank == 0)
    {
        vector<double> x(N);

        x[N-1] = final_mat[(N-1)*ROW + N] /
                 final_mat[(N-1)*ROW + (N-1)];

        for (int i = N - 2; i >= 0; i--)
        {
            double sum = final_mat[i * ROW + N];
            for (int j = i + 1; j < N; j++){
                sum -= final_mat[i * ROW + j] * x[j];
            }
            x[i] = sum / final_mat[i * ROW + i];
        }

        // Write Solution to output.txt
        ofstream fout("output.txt");
        if (fout)
        {
            fout << "Solution: ";
            for (int i = 0; i < N; i++){
                fout << x[i] << " ";
            }
            fout << endl;
            fout.close();
        }

        // Also print on screen (you can remove)
        cout << "Solution: ";
        for (int i = 0; i < N; i++){
            cout << x[i] << " ";
        }
        cout << endl;
    }

    MPI_Finalize();
    return 0;
}
