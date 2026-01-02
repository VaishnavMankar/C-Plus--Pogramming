// Parallel Quick Sort

#include <iostream>
#include <mpi.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
*/

int partition(vector<int> &A, int start, int end)
{
	int pivot = A[end];	
	int i = start - 1;

	for(int j = start; j <= end - 1; j++)
	{
		if(A[j] <= pivot)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[end]);
	return i + 1;
}

void quicksort(vector<int> &A, int start, int end)
{
	if(start < end)
	{
		int part = partition(A, start, end);
		quicksort(A, start, part - 1);
		quicksort(A, part + 1, end);
	}
}

void parallel_quicksort(vector<int> &B, MPI_Comm comm)
{
	int rank, size;
	MPI_Comm_rank(comm, &rank);
        MPI_Comm_size(comm, &size);

	// If only a single processor is available, apply quicksort on it directly and return.
	if(size == 1)
	{
		if(!B.empty())
		{
			quicksort(B, 0, B.size() - 1);	
		}
		return;
	}

	// Select a common pivot for that specific communicator
	int pivot;
	if(!B.empty())
	{
		quicksort(B, 0, B.size() - 1);	
	}

	//for(int val : B)
	//	cout << val << endl;
	//cout << endl;
	
	if(rank == 0)
	{
		pivot = (B.empty() ? 0 : B[B.size() / 2]);  // Taking middle element as the pivot element
	}

	// Using the common pivot for all processors in the current communicating domain
	MPI_Bcast(&pivot, 1, MPI_INT, 0, comm);

	// Two vectors that will hold elements less than pivot and greater than pivot
	vector<int> L, R;

	for(int val : B)
	{
		if(val < pivot)
			L.push_back(val);
		else
			R.push_back(val);
	}

	// Exchanging the elements from two processors to get all elements smaller than pivot to the processors with lower rank, and shifting elements higher than pivot to higher rank processors.
	int processorSwapPartner;
	vector<int> recvData;
	MPI_Status status;

	if(rank < size / 2)
	{
		// Lower processor R will be swapped with consecutive higher processor L, for eg. R of process with rank 0 being swapped with L of process 3		
		processorSwapPartner = rank + size / 2;

		int sendSize = R.size();
		MPI_Send(&sendSize, 1, MPI_INT, processorSwapPartner, 0, comm);

		int recvSize;
		MPI_Recv(&recvSize, 1, MPI_INT, processorSwapPartner, 0, comm, &status);

		recvData.resize(recvSize);

		MPI_Send(R.data(), sendSize, MPI_INT, processorSwapPartner, 1, comm);
		MPI_Recv(recvData.data(), recvSize, MPI_INT, processorSwapPartner, 1, comm, &status);

		// Now we get a full vector with elements less than pivot in B
		B = L;
		B.insert(B.end(), recvData.begin(), recvData.end()); // Appending 'L' vector elements from the higher rank processor to the already present lower elements in lower rank vector 'B'
	}else
	{
		// Higher processor L will be swapped with consecutive lower processor R, for eg. L of process with rank 3 being swapped with R of process 0		
		processorSwapPartner = rank - size / 2;

		int sendSize = L.size();
		MPI_Send(&sendSize, 1, MPI_INT, processorSwapPartner, 0, comm);

		int recvSize;
		MPI_Recv(&recvSize, 1, MPI_INT, processorSwapPartner, 0, comm, &status);

		recvData.resize(recvSize);

		MPI_Send(L.data(), sendSize, MPI_INT, processorSwapPartner, 1, comm);
		MPI_Recv(recvData.data(), recvSize, MPI_INT, processorSwapPartner, 1, comm, &status);

		// Now we get a full vector with elements less than pivot in B
		B = R;
		B.insert(B.end(), recvData.begin(), recvData.end());
	}

	// Now creating a new communicating domain for repeating the exact same following steps:
	/*
		1) Taking a common pivot
		2) Splitting subarray on every processor into two parts L and R, based on pivot where L will have elements less than pivot, R will have elements greater than pivot
		3) Then, swapping R of higher ranks with L of lower ranks to partition data into - all elements lower than current pivot to lower ranks, and all elements higher than pivot to higher ranks
		4) Then combining the L part with L, R with R and forming a new subarray B for every processor
		5) Then forming new communication domains on every processor for dividing current new B into further 2 parts (less than and greater than pivot), and each domain will now have its independent pivot
		6) Repeating all the steps recursively until all elements have been sorted and merged into a single vector
	*/
		
	int colour = (rank < size / 2 ? 0 : 1);  // Lower ranks get colour 0, higher get 1
	MPI_Comm newComm;
	MPI_Comm_split(comm, colour, rank, &newComm);
	
	parallel_quicksort(B, newComm);

	MPI_Comm_free(&newComm);
}

int main(int argc, char* argv[])
{
 	int rank, size;

        MPI_Init(&argc, &argv);
        MPI_Status status;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);

	int arrSize = 20;
	int blockSize = arrSize / size;
	// cout << blockSize << endl;
	vector<int> A;

	if(rank == 0)
	{
		srand(time(0));
		A.resize(arrSize);
		
		for(int i = 0; i < arrSize; i++)
		{
			A[i] = (rand() % 100);
		}
	}

	if(rank == 0)
	{
		//for(int val : A)
		//	cout << val << endl;
		//cout << endl;
	}

	vector<int> B(blockSize);

	MPI_Scatter(A.data(), blockSize, MPI_INT, B.data(), blockSize, MPI_INT, 0, MPI_COMM_WORLD);

	parallel_quicksort(B, MPI_COMM_WORLD);
	
	int localSize = B.size();
	vector<int> recvCounts(size), displacement(size);

	// Storing all local sizes of B, which will vary after the function parallel_quicksort(), in the array recvCounts
	MPI_Gather(&localSize, 1, MPI_INT, recvCounts.data(), 1, MPI_INT, 0, MPI_COMM_WORLD); // 0 is root process
	
	if(rank == 0)
	{
		displacement[0] = 0;

		for(int i = 1; i < size; i++)
			displacement[i] = displacement[i - 1] + recvCounts[i - 1]; // Each process will return some data of different size, and displacement is the way to know the starting point or index from where we have to start for that ith process
		A.clear();		
		A.resize(displacement[size - 1] + recvCounts[size - 1]);  // 'A' will now contain the new sorted array
	}

	// Gathering the actual sorted array, using MPI_Gatherv for gathering data of variable amount
	MPI_Gatherv(B.data(), localSize, MPI_INT, A.data(), recvCounts.data(), displacement.data(), MPI_INT, 0, MPI_COMM_WORLD);
	
	if(rank == 0)
	{
		for(int val : A)
			cout << val << endl;
	}
	
	MPI_Finalize();
}

/*
vector<vector<int>> splitdata(vector<int> &A, int num_targets)
{
	vector<vector<int>> result(num_targets);

	int total = A.size();
	int base = total / num_targets;
	int rem = total % num_targets;
	int offset = 0;

	for(int i = 0; i < num_targets; i++)
	{
		int size = base + (i < rem ? 1 : 0);
		result[i].insert(result[i].end(), A.begin() + offset, A.begin() + offset + size);
		offset += size;
	}

	return result;
}

	int half = size / 2;

	int local_less_size = less.size();
	int local_greater_size = greater.size();

	int total_less_size, total_greater_size;
	MPI_Allreduce(&local_less_size, &total_less_size, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	MPI_Allreduce(&local_greater_size, &total_greater_size, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

	bool isLower = rank < half;
	int group_size = half;
	int my_rank_in_group = isLower ? rank : rank - half;
	int group_total_size = isLower ? total_less_size : total_greater_size;
	int base_chunk = group_total_size / group_size;
	int remainder = group_total_size % group_size;
	int my_target_size = base_chunk + (my_rank_in_group < remainder ? 1 : 0)  // Each processor knows how many values it should receive

	cout << endl;
	for(int i = 0; i < blockSize; i++)
        {
        	cout << arr[i] << " ";
        }
	cout << endl;
	cout << endl << pivot << endl;
*/
