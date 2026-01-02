// Parallel Quick Sort

#include <iostream>
#include <mpi.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int> &A, int start, int end)
{
	int pivot = A[end];
	int i = start - 1;

	for (int j = start; j <= end - 1; j++)
	{
		if (A[j] <= pivot)
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
	if (start < end)
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
	int bSize = B.size();

	// If only a single processor is available, apply quicksort on it directly and return.
	if (size == 1)
	{
		if (!B.empty())
		{
			quicksort(B, 0, bSize - 1);
		}
		return;
	}

	// Select a common pivot for that specific communicator
	int pivot;
	if (!B.empty())
	{
		quicksort(B, 0, bSize - 1);
	}

	if (rank == 0)
	{
		pivot = (B.empty() ? 0 : B[bSize / 2]); // Taking middle element as the pivot element
	}

	// Using the common pivot for all processors in the current communication domain
	MPI_Bcast(&pivot, 1, MPI_INT, 0, comm);

	// Two vectors that will hold elements less than pivot and greater than pivot
	vector<int> L, R;

	for (int val : B)
	{
		if (val < pivot)
			L.push_back(val);
		else
			R.push_back(val);
	}

	int lower_size = size / 2;
	int upper_size = size - lower_size;
	int pairs = min(lower_size, upper_size); // The count of processors that will get a pair for swapping L and R

	int partner = -1;
	bool hasPartner = false;

	// Ranks less than pair count will get a partner
	if (rank < pairs)
	{
		partner = rank + lower_size; // Lower ranks will get paired with higher rank processor
		hasPartner = true;
	}
	else if (rank >= lower_size && rank < lower_size + pairs) // Upper ranks that will be paired with the lower ranks
	{
		partner = rank - lower_size; // Higher ranks will get paired with lower rank processors
		hasPartner = true;
	}

	// Swapping L and R of paired processors
	if (hasPartner)
	{
		int sendSize = (rank < lower_size) ? (int)R.size() : (int)L.size(); // If it is lower rank, we send L, if it is higher rank, swap its R
		int recvSize = 0;

		MPI_Sendrecv(&sendSize, 1, MPI_INT, partner, 0, // Here, partner is destination, which simultaneously receives data (sendSize) sent by its partner processor
					 &recvSize, 1, MPI_INT, partner, 0, // Here, partner is source, which sends 'sendSize'
					 comm, MPI_STATUS_IGNORE);

		vector<int> recvData(recvSize);

		// Lower processor R will be swapped with consecutive higher processor L, for eg. R of process with rank 0 being swapped with L of process 3
		if (rank < lower_size)
		{
			// Current processor will send its R to partner, and in turn will receive its L in recvData vector, then we append current processors L with partner processors L so that whole B will have elements that are less than pivot
			MPI_Sendrecv(R.data(), sendSize, MPI_INT, partner, 1,
						 recvData.data(), recvSize, MPI_INT, partner, 1,
						 comm, MPI_STATUS_IGNORE);
			B = L;
			B.insert(B.end(), recvData.begin(), recvData.end());
		}
		else // Higher processor L will be swapped with consecutive lower processor R, for eg. L of process with rank 3 being swapped with R of process 0
		{
			MPI_Sendrecv(L.data(), sendSize, MPI_INT, partner, 1,
						 recvData.data(), recvSize, MPI_INT, partner, 1,
						 comm, MPI_STATUS_IGNORE);
			B = R;
			B.insert(B.end(), recvData.begin(), recvData.end());
		}
	}

	MPI_Status status;
	MPI_Barrier(comm); // Ensuring all pair exchanges completed

	// Handling single 'extra' rank processor that has no pair
	int extra_rank = 2 * lower_size; // index of the one possible extra (if < size)
	if (extra_rank < size)
	{
		if (rank == extra_rank)
		{
			// Sending L to a lower rank processor, R to an higher rank processor
			int destLower = (pairs > 0) ? (pairs - 1) : -1; // Last lower paired rank
			int destUpper = lower_size;						// First rank in upper group

			int Lsize = L.size();
			int Rsize = R.size();

			// Sending sizes and then data, as data is not evenly spread out in L and R vectors
			if (destLower >= 0)
			{
				MPI_Send(&Lsize, 1, MPI_INT, destLower, 2, comm);
				if (Lsize > 0)
					MPI_Send(L.data(), Lsize, MPI_INT, destLower, 3, comm);
			}
			if (destUpper < size)
			{
				MPI_Send(&Rsize, 1, MPI_INT, destUpper, 4, comm);
				if (Rsize > 0)
					MPI_Send(R.data(), Rsize, MPI_INT, destUpper, 5, comm);
			}

			// Extra processor gives all its elements to other processors, therefore it does not have to keep its B
			B.clear();
		}
		else // The 2 processors that get extra processor's elements will now receive them
		{
			if (pairs > 0 && rank == (pairs - 1))
			{
				// Receiving size of L and then L from extra
				int recvLsize = 0;
				MPI_Recv(&recvLsize, 1, MPI_INT, extra_rank, 2, comm, &status);
				if (recvLsize > 0)
				{
					vector<int> recvL(recvLsize);
					MPI_Recv(recvL.data(), recvLsize, MPI_INT, extra_rank, 3, comm, &status);
					B.insert(B.end(), recvL.begin(), recvL.end()); // Appending extra L elements after current elements of B
				}
			}

			if (rank == lower_size && lower_size < size)
			{
				// Receiving size of R and then R from extra
				int recvRsize = 0;
				MPI_Recv(&recvRsize, 1, MPI_INT, extra_rank, 4, comm, &status);
				if (recvRsize > 0)
				{
					vector<int> recvR(recvRsize);
					MPI_Recv(recvR.data(), recvRsize, MPI_INT, extra_rank, 5, comm, &status);
					B.insert(B.end(), recvR.begin(), recvR.end());
				}
			}
		}
	}

	int colour;
	// Assigning colours to paired processors only
	if (rank < lower_size)
		colour = 0;
	else if (rank < lower_size + pairs)
		colour = 1;
	else
		colour = MPI_UNDEFINED; // Extra rank drops out

	MPI_Comm newComm;
	MPI_Comm_split(comm, colour, rank, &newComm);

	if (colour != MPI_UNDEFINED)
	{
		parallel_quicksort(B, newComm);
		MPI_Comm_free(&newComm);
	}
}

int main(int argc, char *argv[])
{
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int arrSize = 20;
	vector<int> A; // Initial vector that will be divided among all processors, and then finally will also contain the sorted elements from all processors

	if (rank == 0)
	{
		// Randomly filling up 'A' with 'arrSize' elements
		srand(time(0));
		A.resize(arrSize);

		cout << "\nInitial unsorted array:" << endl;
		for (int i = 0; i < arrSize; i++)
		{
			A[i] = (rand() % 100);
			cout << A[i] << " ";
		}
		cout << endl;
	}

	int blockSize = arrSize / size;
	int rem = arrSize % size;

	// Elements will not be scattered evenly, because the total number of elements might not always be divisible by the number of processors 'p', therefore using scatterv instead of just scatter
	vector<int> sendCounts(size);
	vector<int> sendDispls(size);

	int offset = 0;
	for (int i = 0; i < size; ++i)
	{
		sendCounts[i] = blockSize + (i < rem ? 1 : 0); // First 'rem' ranks get one extra number if 'arrSize' is greater than number of available processors
		sendDispls[i] = offset;						   // Current rank will start getting elements from this sendDispls[i]th position
		offset += sendCounts[i];					   // Next offset will be sendCounts[i] positions ahead of the current position in displacement
	}

	int rankBSize = sendCounts[rank]; // Size of data that current rank will get
	vector<int> B(rankBSize);

	MPI_Scatterv(
		A.data(), // Root sends the data
		sendCounts.data(), sendDispls.data(), MPI_INT,
		B.data(), rankBSize, MPI_INT,
		0, MPI_COMM_WORLD);

	parallel_quicksort(B, MPI_COMM_WORLD); // All processors send their sorted data into this B vector

	int localSize = B.size();
	vector<int> recvCounts(size), displacement(size);

	// Storing all local sizes of B, which will vary after the function parallel_quicksort(), in the array recvCounts, because the data will be unevenly spread after it has been sent to parallel_quicksort function
	MPI_Gather(&localSize, 1, MPI_INT, recvCounts.data(), 1, MPI_INT, 0, MPI_COMM_WORLD); // 0 is root process, on which the whole data will be gathered

	if (rank == 0)
	{
		displacement[0] = 0;

		for (int i = 1; i < size; i++)
			displacement[i] = displacement[i - 1] + recvCounts[i - 1]; // Each process will return some data of different size, and displacement is the way to know the starting point or index from where we have to start for that ith process
		A.clear();
		A.resize(displacement[size - 1] + recvCounts[size - 1]); // 'A' will now contain the new sorted array
	}

	// Gathering the actual sorted array, using MPI_Gatherv for gathering data of variable amount
	MPI_Gatherv(B.data(), localSize, MPI_INT, A.data(), recvCounts.data(), displacement.data(), MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0)
	{
		cout << "\nArray after sorting: " << endl;
		for (int val : A)
			cout << val << " ";

		cout << "\n\nSize of A: " << A.size() << "\n\n";
	}

	MPI_Finalize();
}