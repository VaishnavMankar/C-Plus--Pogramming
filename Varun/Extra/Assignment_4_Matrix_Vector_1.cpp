// Parallel Matrix-Vector Multiplication

#include <iostream>
#include <mpi.h>
#include <vector>
#include <cstdlib>
#include <ctime>

/*
1) A4x4 * V4x1 -> 4 processors
2) Amxn * Vnx1 -> m divisible by 'p'
3) Amxn * Vnx1 -> m not divisible by 'p' (generalized version)
*/

using namespace std;

int main(int argc, char *argv[])
{
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	// int arrSize = 16;
	int rows = 4;
	int cols = 4;
	// int blockSize = arrSize / size;

	vector<int> arr; // Initial vector that will be divided among all processors, and then finally will also contain the sorted elements from all processors
	vector<int> X;
	
	if (rank == 0)
	{
		// Creating the matrix and vector
		int i = 1, j = 1;
		for(int k = 1; k <= (rows * cols); k++)
		{
			arr.push_back(i * j);
			i++;

			if(k % 4 == 0 && k > 0)	
			{
				i = 1;				
				j++;
			}
		}

		for(int k = 10; k < 14; k++)
			X.push_back(k);

		//for(int k = 0; k < blockSize; k++)
		//	cout << X[k] << endl;
	}

	vector<int> A(cols);
	vector<int> b(rows);

	MPI_Scatter(arr.data(), cols, MPI_INT, A.data(), cols, MPI_INT, 0, MPI_COMM_WORLD);
	X.resize(cols);
	MPI_Bcast(X.data(), cols, MPI_INT, 0, MPI_COMM_WORLD);

	/*
	for(int i = 0; i < blockSize; i++)
		cout << A[i] << " ";	
	cout << endl;

	for(int i = 0; i < X.size(); i++)
		cout << X[i] << " ";
	cout << endl;
	*/

	// Actual calculation	
	int result = 0;
	for(int i = 0; i < rows; i++)
	{
		result += (A[i] * X[i]);
	}

	MPI_Gather(&result, 1, MPI_INT, b.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);
	
	if(rank == 0)
	{
		for(int i = 0; i < b.size(); i++)
			cout << b[i] << endl;
	}

	MPI_Finalize();
}