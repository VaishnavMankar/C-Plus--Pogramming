#include<iostream>
#include<vector>
#include<mpi.h>
using namespace std;

int main(int argc, char *argv[]){
    MPI_Init(&argc, &argv);
    
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int chunk_size = 5;
    int total_element = 50;
    
    if(rank == 0){
        vector<int> arr;
        for(int i = 0; i < total_element; i++)
            arr.push_back(i);

        cout << "Processor 0 is printing : " << endl;
        for(int i = 0; i < chunk_size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

        //sending the remaining elements to remaining 9 processor to print
        for(int i = 1; i < size; i++){
            int *send_start = arr.data() + (i * chunk_size);

            MPI_Send(send_start, chunk_size, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    }

    if(rank != 0){
        vector<int> receive_data(chunk_size);

        MPI_Recv(receive_data.data(), chunk_size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Processor " << rank << " id printing: ";
        for(int i = 0; i < chunk_size; i++){
            cout << receive_data[i] << " ";
        }
        cout << endl;
    }
    MPI_Finalize();
    return 0;
}