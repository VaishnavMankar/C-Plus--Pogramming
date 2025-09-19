#include<iostream>
#include<vector>
#include<mpi.h>
using namespace std;

int main(int argc,char *argv[])
{
  MPI_Init(&argc,&argv);
  MPI_Status status;
  int rank,size;     //size is number of processor
  
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  //cout << "my rank " << rank <<" out of " << size << endl;
  
  int n = 100;
  int part = n/size;
  if(rank == 0){
    vector<int> A;
    int sum = 0;
    for(int i = 0; i < n; i++){
       A.push_back(i+1);
    } 
    MPI_Send(A.data()+ part, part, MPI_INT,1,1,MPI_COMM_WORLD);
    cout << "my rank " << rank <<" out of " << size << endl;
    for(int i = 0; i < part; i++){
    sum += A[i];
    }
    //cout << sum << endl;
    int sum1;
    MPI_Recv(&sum1,1,MPI_INT,1,2,MPI_COMM_WORLD, &status);
    int totalsum = sum + sum1;
    cout << totalsum << endl;
  }
  if(rank != 0){
  int sum = 0;
  vector<int> B(part);
  MPI_Recv(B.data(),part,MPI_INT,0,1,MPI_COMM_WORLD, &status);
  cout << "my rank " << rank <<" out of " << size << endl;
  for(int i = 0; i < part; i++){
    sum += B[i];
  }
  //cout << sum << endl;
  MPI_Send(&sum,1,MPI_INT,0,2,MPI_COMM_WORLD);
}
  //vector<int> A;
  //for (int i = 0; i < n; i++){
  //  A.push_back(i+1);
  //}
  //int sum = 0;
  //for(int i = 0; i < n; i++){
  //  sum = sum + A[i];
  //}
  //cout << sum << endl;
  MPI_Finalize();
  return 0;
}      
