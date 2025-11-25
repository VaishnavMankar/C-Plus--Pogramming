// Parallel Matrix-Vector Multiplication

#include <iostream>
#include <mpi.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>

/*
1) A4x4 * V4x1 -> 4 processors
2) Anxm * Vmx1 -> n divisible by 'p'
3) Anxm * Vmx1 -> n not divisible by 'p' (generalized version)
*/

using namespace std;

int main(int argc, char *argv[])
{
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int n;
	int m;

	vector<int> arr; // Initial vector that will be divided among all processors, and then finally will also contain the sorted elements from all processors
	vector<int> X;

	if (rank == 0)
	{
		// Reading matrix from file
		ifstream matFile("matrixvectorinput.txt");

		if (!matFile)
		{
			cout << "Error opening the matrix file!" << endl;
			exit(0);
		}

		matFile >> n >> m;

		arr.resize(n * m);

		for (int i = 0; i < n * m; i++)
		{
			if (!(matFile >> arr[i]))
			{
				exit(0);
			}
		}

		int vc;

		matFile >> m >> vc;

		X.resize(m);

		for (int i = 0; i < m; i++)
		{
			if (!(matFile >> X[i]))
			{
				exit(0);
			}
		}
	}

	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);

	int factor = n / size;
	int excessRow = n % size;
	int extraRowStart = size - excessRow;

	X.resize(m);

	MPI_Bcast(X.data(), m, MPI_INT, 0, MPI_COMM_WORLD);

	vector<int> sendCounts(size);
	vector<int> sendDispls(size);

	int offset = 0;
	for (int i = 0; i < size; ++i)
	{
		int row = factor + (i >= extraRowStart ? 1 : 0); // Assigning excess row to processors from last
		sendCounts[i] = row * m;
		sendDispls[i] = offset;
		offset += sendCounts[i];
	}

	// Sending unequal amount of data
	int elements = sendCounts[rank]; // Size of data that current rank will get
	vector<int> A(elements);
	vector<int> b;

	MPI_Scatterv(arr.data(), // Root sends the data
				 sendCounts.data(), sendDispls.data(), MPI_INT,
				 A.data(), elements, MPI_INT,
				 0, MPI_COMM_WORLD);

	int rows = factor + (rank >= extraRowStart ? 1 : 0);

	// Actual calculation
	vector<int> result(rows, 0);
	int resIndex = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result[i] += A[i * m + j] * X[j];
		}
	}

	// Receiving unequal amount of data
	vector<int> recvCounts(size), displacement(size);
	int localSize = rows;
	b.resize(rows);

	MPI_Gather(&localSize, 1, MPI_INT, recvCounts.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0)
	{
		displacement[0] = 0;

		for (int i = 1; i < size; i++)
			displacement[i] = displacement[i - 1] + recvCounts[i - 1]; // Each process will return some data of different size, and displacement is the way to know the starting point or index from where we have to start for that ith process

		b.resize(displacement[size - 1] + recvCounts[size - 1]); // 'b' will now contain the values
	}

	// Gathering the actual sorted array, using MPI_Gatherv for gathering data of variable amount
	MPI_Gatherv(result.data(), localSize, MPI_INT, b.data(), recvCounts.data(), displacement.data(), MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0)
	{
		ofstream outputFile("output_assign4.txt");

		for (int n : b)
		{
			outputFile << n << "\n";
		}

		cout << "\nResult: ";
		for (int i = 0; i < b.size(); i++)
			cout << b[i] << " ";
		cout << "\n\n";
	}

	MPI_Finalize();
}