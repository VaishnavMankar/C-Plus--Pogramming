// Write a parallel code to perform numerical integration using Simpson's 3/8 rule of 0,4∫x^2e^−x dx 
// over 12, 20, 40 and 80 intervals on p processors, where p is determined at run time. Check your 
// code executes and gives correct results before submission.

#include <iostream>
#include <mpi.h>
#include <vector>
#include <cmath>
using namespace std;

double func(double x){
    return x*x*exp(-x);
}

int main(int argc, char *argv[]){
    MPI_Init(&argc, &argv);
    MPI_Status status;
    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double a=0.0, b=4.0;
    int test[] = {12, 20, 40, 80};
    int num_test = sizeof(test) / sizeof(test[0]);

    for (int t=0; t<num_test; t++){
        int n = test[t];
        double h = (b-a)/n;  

        int base = (n-1) / size;
        int remender = (n-1) % size;
        int part = base+(rank<remender ? 1 : 0);

        if (rank==0){
            vector<int> A;
            for (int i=1; i<n; i++){
                A.push_back(i);
            }
            
            //sending the equal parts of data to all the slave nodes
            int set = part;
            for(int i=1; i<size; i++){
                int count = base+(i < remender ? 1 : 0);
                MPI_Send(A.data() + set, count, MPI_INT, i, 1, MPI_COMM_WORLD);
                set += count;
            }

            // mater calculating its own loacl sum
            double localsum = 0.0;
            for (int i=0; i<part; i++){
                int id = A[i];
                if (id%3 == 0){
                    localsum += 2*func(a+id * h);
                }else{
                    localsum += 3*func(a+id * h);
                }
            }
             cout << "Master (rank " << rank << ") calculated its own sum = " << localsum << endl;

            //receiving results from slave 
            for (int i=1; i<size; i++){
                double sum = 0.0;
                MPI_Recv(&sum, 1, MPI_DOUBLE, i, 2, MPI_COMM_WORLD, &status);
                cout << "Master (rank 0) received local sum " << sum << " from process " << i << endl;
                localsum += sum;
            }
            localsum += func(a)+func(b);

            double ans = ((3*h)/8.0) * localsum;
            cout << "n = " << n << "Final answer = " << ans << endl;
        }
        // the work for slave nodes
        else {
            //slave receiving there data
            vector<int> B(part);
            MPI_Recv(B.data(), part, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
            //slave performing there indivial calculatein
            double localsum = 0.0;
            for (int i=0; i<part; i++){
                int id = B[i];
                if (id%3 == 0){
                    localsum += 2*func(a+id*h);
                }else{
                    localsum += 3*func(a+id*h);
                }
            }
            //sending back the locally calculated sum to the master node
            MPI_Send(&localsum, 1, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
        }
    }
    MPI_Finalize();
    return 0;
}
