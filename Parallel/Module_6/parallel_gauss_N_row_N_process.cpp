#include <mpi.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    MPI_Init(&argc,&argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    // =============================
    // Read N (only rank 0 needs it)
    // =============================
    int N = 4;  // default
    if (argc > 1 && rank == 0)
        N = atoi(argv[1]);

    // Broadcast N to all ranks
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Each row has (N+1) entries
    int ROWSIZE = N + 1;

    // Ensure number of processes = N
    if (size != N)
    {
        if (rank == 0)
            cerr << "Error: number of MPI processes must equal N.\n";
        MPI_Finalize();
        return 0;
    }

    // =============================
    // Allocate matrices
    // =============================
    vector<double> mat;             // only rank 0 fills this
    vector<double> B(ROWSIZE);      // local row
    vector<double> pivot_row(ROWSIZE);
    vector<double> new_mat;         // gathered matrix

    // =============================
    // Initialize matrix on ROOT
    // =============================
    if (rank == 0)
    {
        mat.resize(N * ROWSIZE);

        // default example for any N:
        // Identity matrix with RHS = index+1
        // (User can replace with input file easily)
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                mat[i*ROWSIZE + j] = (i == j ? 1 : 0);

            mat[i*ROWSIZE + N] = i + 1;  // RHS
        }
    }

    // User may override matrix manually for testing
    // For N=4, example from your original code:
    if (rank == 0 && N == 4)
    {
        mat = {
            2, 1, -1, 3,  8,
            1, 1,  1,-1, -2,
            3, 2, -1, 0,  6,
            0, 4,  3, 2, -8
        };
    }

    // =============================
    // Scatter rows
    // =============================
    MPI_Scatter(mat.data(), ROWSIZE, MPI_DOUBLE,
                B.data(), ROWSIZE, MPI_DOUBLE,
                0, MPI_COMM_WORLD);

    // =============================
    // Forward elimination using your logic
    // =============================
    for (int r = 0; r < N; r++)
    {
        // Rank r broadcasts its pivot row
        if (rank == r)
            pivot_row = B;

        MPI_Bcast(pivot_row.data(), ROWSIZE, MPI_DOUBLE, r, MPI_COMM_WORLD);

        // Eliminate rows with rank > r
        if (rank > r)
        {
            double pivot = pivot_row[r];
            double temp  = B[r];

            for (int j = 0; j < ROWSIZE; j++)
                B[j] = B[j] - (temp / pivot) * pivot_row[j];
        }
    }

    // =============================
    // Gather final upper-triangular matrix
    // =============================
    if (rank == 0)
        new_mat.resize(N * ROWSIZE);

    MPI_Gather(B.data(), ROWSIZE, MPI_DOUBLE,
               new_mat.data(), ROWSIZE, MPI_DOUBLE,
               0, MPI_COMM_WORLD);

    // =============================
    // Back substitution on ROOT
    // =============================
    if (rank == 0)
    {
        vector<double> ans(N);

        // Last variable:
        ans[N-1] =
            new_mat[(N-1)*ROWSIZE + N] /
            new_mat[(N-1)*ROWSIZE + (N-1)];

        // Remaining variables
        for (int i = N-2; i >= 0; i--)
        {
            double sum = new_mat[i*ROWSIZE + N]; // RHS

            for (int j = i+1; j < N; j++)
                sum -= new_mat[i*ROWSIZE + j] * ans[j];

            ans[i] = sum / new_mat[i*ROWSIZE + i];
        }

        // Output
        for (int i = 0; i < N; i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    MPI_Finalize();
    return 0;
}
