#include <mpi.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // 1) Create 2D Cartesian grid
    int q;
    q = (int)sqrt(size);

    if (q*q != size)
    {
        if (rank == 0)
            cout << "Number of processes must be a perfect square.\n";
        MPI_Finalize();
        return 0;
    }

    int dims[2] = {q, q};
    int periodic[2] = {1, 1};
    int reorder = 0;

    MPI_Comm cart;
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periodic, reorder, &cart);

    int myRank;
    MPI_Comm_rank(cart, &myRank);

    int coords[2];
    MPI_Cart_coords(cart, myRank, 2, coords);

    // 2) Rank 0 reads matrices from input files
    int N;
    vector<int> A, B;

    if (rank == 0)
    {
        ifstream fa("matrixA.txt");
        ifstream fb("matrixB.txt");

        if (!fa || !fb)
        {
            cout << "Error opening input files!\n";
            MPI_Finalize();
            return 0;
        }

        fa >> N;
        fb >> N;

        A.resize(N*N);
        B.resize(N*N);

        for (int i = 0; i < N*N; i++) fa >> A[i];
        for (int i = 0; i < N*N; i++) fb >> B[i];

        fa.close();
        fb.close();
    }

    // Broadcast N to all ranks
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int block = N / q;   // block size per process

    // Local matrices
    vector<int> localA(block * block);
    vector<int> localB(block * block);
    vector<int> localC(block * block, 0);

    // 3) Scatter blocks of matrices
    // Prepare scatter buffers on root
    vector<int> sendA, sendB;

    if (rank == 0)
    {
        sendA.resize(size * block * block);
        sendB.resize(size * block * block);

        int id = 0;
        for (int pr = 0; pr < q; pr++)
        {
            for (int pc = 0; pc < q; pc++)
            {
                for (int i = 0; i < block; i++)
                {
                    for (int j = 0; j < block; j++)
                    {
                        sendA[id] = A[(pr*block + i)*N + (pc*block + j)];
                        sendB[id] = B[(pr*block + i)*N + (pc*block + j)];
                        id++;
                    }
                }
            }
        }
    }

    MPI_Scatter(sendA.data(), block*block, MPI_INT,
                localA.data(), block*block, MPI_INT,
                0, MPI_COMM_WORLD);

    MPI_Scatter(sendB.data(), block*block, MPI_INT,
                localB.data(), block*block, MPI_INT,
                0, MPI_COMM_WORLD);

    // 4) Cannon’s Initial Alignment
    MPI_Status st;
    MPI_Request req;

    int left, right, up, down;

    MPI_Cart_shift(cart, 1, -coords[0], &right, &left);
    MPI_Sendrecv_replace(localA.data(), block*block, MPI_INT,
                         left, 0, right, 0, cart, &st);

    MPI_Cart_shift(cart, 0, -coords[1], &down, &up);
    MPI_Sendrecv_replace(localB.data(), block*block, MPI_INT,
                         up, 1, down, 1, cart, &st);

    // 5) Cannon’s Iterations
    MPI_Cart_shift(cart, 1, -1, &right, &left);
    MPI_Cart_shift(cart, 0, -1, &down, &up);

    for (int step = 0; step < q; step++)
    {
        // Multiply block
        for (int i = 0; i < block; i++)
        {
            for (int j = 0; j < block; j++)
            {
                for (int k = 0; k < block; k++)
                    localC[i*block + j] += localA[i*block + k] * localB[k*block + j];
            }
        }

        // Shift A left
        MPI_Sendrecv_replace(localA.data(), block*block, MPI_INT,
                             left, 2, right, 2, cart, &st);

        // Shift B up
        MPI_Sendrecv_replace(localB.data(), block*block, MPI_INT,
                             up, 3, down, 3, cart, &st);
    }

    // 6) Gather result matrix at rank 0
    vector<int> recvC;

    if (rank == 0)
        recvC.resize(N*N);

    MPI_Gather(localC.data(), block*block, MPI_INT,
               recvC.data(), block*block, MPI_INT,
               0, MPI_COMM_WORLD);

    // 7) Rank 0 rearranges blocks and writes output file
    if (rank == 0)
    {
        vector<int> C(N*N);

        int id = 0;
        for (int pr = 0; pr < q; pr++)
        {
            for (int pc = 0; pc < q; pc++)
            {
                for (int i = 0; i < block; i++)
                {
                    for (int j = 0; j < block; j++)
                    {
                        C[(pr*block + i)*N + (pc*block + j)] = recvC[id++];
                    }
                }
            }
        }

        // Write to file
        ofstream fout("output.txt");
        fout << N << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                fout << C[i*N + j] << " ";
            fout << endl;
        }
        fout.close();

        cout << "Output written to output.txt\n";
    }

    MPI_Finalize();
    return 0;
}
