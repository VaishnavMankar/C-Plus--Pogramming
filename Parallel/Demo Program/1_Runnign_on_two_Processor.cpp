#include<iostream>
#include<vector>
#include<mpi.h>
using namespace std;

int main(int args, char *argv[]){
    MPI_Init(&args, &argv);
    MPI_Status status;
    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = 100;
    int part = n/size;
    if(rank == 0){
        vector<int> A;
        int sum = 0;
        for (int i = 0; i < n; i++){
            A.push_back(i+1);
        }
        
        MPI_Send(A.data() + part, part, MPI_INT,1,1,MPI_COMM_WORLD);
        cout << "my rank " << rank << " out of " << size << endl ; 
        for(int i = 0; i < part; i++){
            sum += A[i];
        }

        int sum1;
        MPI_Recv(&sum1,1,MPI_INT,1,2,MPI_COMM_WORLD, &status);
        int totalsum = sum + sum1;
        cout << totalsum << endl;
    }

    if(rank != 0){
    int sum = 0;
    vector<int> B(part);
    MPI_Recv(B.data(),part,MPI_INT,0,1,MPI_COMM_WORLD,&status);
    cout << "My rank " << rank << "out of " << size << endl;
    for (int i = 0; i < part; i++){
        sum += B[i];
    }
    cout << sum << endl;
    MPI_Send(&sum,1,MPI_INT,0,2,MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}