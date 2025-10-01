#include<iostream>
#include<vector>
#include<mpi.h>
using namespace std;

int main(int argc, char* argv[]){
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int elements = 5;

    if(rank == 0){
        vector<int> arr = {2,4,6,8,10,12,14,16,18,20};

        cout << "Processor 0 is printing this data: " << endl;
        for(int i = 0; i < elements; i++){
            cout  << arr[i] << " ";
        }
        cout << endl;

        MPI_Send(&arr[elements], elements, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }

    else if(rank == 1){
        vector<int> receive_data(elements);

        MPI_Recv(receive_data.data(), elements, MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
         
        cout << "Processor 1 is printing this data: " << endl;
        for(int i = 0; i < elements; i++){
            cout << receive_data[i] << " ";
        }
        cout << endl;
    }
    MPI_Finalize();
    return 0;
}