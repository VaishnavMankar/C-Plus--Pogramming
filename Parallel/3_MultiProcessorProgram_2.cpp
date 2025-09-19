#include<iostream>
#include<vector>
#include<mpi.h>
using namespace std;

int main(int argc, char *argv[]){
    MPI_Init(&argc, &argv);
    MPI_Status status;
    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = 1000;
    int base = n / size;  //minimum elements per process
    int rem = n % size; //leftover element to distribute

    //Each process'r part size
    int part = base + (rank < rem ? 1 : 0);
    
    if(rank == 0){
        //Generate number 1 to n
        vector<int> A(n);
        for(int i = 0; i < n; i++){
            A[i] = i + 1;
        }
        int offset = part; // process 0 keep first 'part' elements

        //send part to all other ranks
        for(int i = 1; i < size; i++){
            int count = base + (i < rem ? 1 : 0);//size of this rank's part
            MPI_Send(A.data() + offset, count, MPI_INT, i , 1, MPI_COMM_WORLD);
            offset += count;
        }

        //compute local sum for rank 0
        int lsum = 0;
        for(int i = 0; i < part; i++){
            lsum += A[i];
        }
        cout << "Local Sum on rank " << rank << ": " << lsum << endl;

        //receive partial sum from other 
        for(int i = 1; i < size; i++){
            int sum;
            MPI_Recv(&sum,1, MPI_INT, i, 2, MPI_COMM_WORLD, &status);
            lsum += sum;
        }
        cout << "Total sum = " << lsum << endl;
    }
    else{
        //receive my chunk
        vector<int> B(part);
        MPI_Recv(B.data(), part, MPI_INT,0,1,MPI_COMM_WORLD, &status);

        //compute local sum
        int lsum = 0;
        for(int i = 0; i < part; i++){
            lsum += B[i];
        }
        cout << "local sum on rank " << rank << ": " << lsum << endl;

        //send result back
        MPI_Send(&lsum, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}