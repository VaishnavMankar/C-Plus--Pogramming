#include<iostream>
#include<mpi.h>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
     // MPI environment setup
     MPI_Init(&argc, &argv);
     int rank, size;
     MPI_Comm_rank(MPI_COMM_WORLD, &rank);
     MPI_Comm_size(MPI_COMM_WORLD, &size);     
          	
	MPI_Comm Santosh;
	int dim = 2;
	vector<int> dimVec = {2, 2};
	vector<int> periodicity = {1, 1};
	int reorder = 0;
	MPI_Cart_create(MPI_COMM_WORLD, dim, dimVec.data(), periodicity.data(), reorder, &Santosh);
	
	int newRank;
	MPI_Comm_rank(Santosh, &newRank);
	
	//cout << "New rank: " << newRank << endl;
	
	int localA[2][2], localB[2][2], localC[2][2] = {0};
	if(newRank == 0) 
	{
		localA[0][0] = 1; localA[0][1] = 2; localA[1][0] = 5; localA[1][1] = 6;
		localB[0][0] = 16; localB[0][1] = 15; localB[1][0] = 12; localB[1][1] = 11;
		
		/*int localA[2][2] = {{1, 2}, {5, 6}};
		int localB[2][2] = {{16, 15}, {12, 11}};*/
	}
	else if(newRank == 1) 
	{
		localA[0][0] = 3; localA[0][1] = 4; localA[1][0] = 7; localA[1][1] = 8;
		localB[0][0] = 14; localB[0][1] = 13; localB[1][0] = 10; localB[1][1] = 9;
		
		/*int localA[2][2] = {{3, 4}, {7, 8}};
		int localB[2][2] = {{14, 13}, {10, 9}};*/
	}
	else if(newRank == 2) 
	{
		localA[0][0] = 9; localA[0][1] = 10; localA[1][0] = 13; localA[1][1] = 14;
		localB[0][0] = 8; localB[0][1] = 7; localB[1][0] = 4; localB[1][1] = 3;
		
		/*int localA[2][2] = {{9, 10}, {13, 14}};
		int localB[2][2] = {{8, 7}, {4, 3}};*/
	}
	else if(newRank == 3) 
	{
		localA[0][0] = 11; localA[0][1] = 12; localA[1][0] = 15; localA[1][1] = 16;
		localB[0][0] = 6; localB[0][1] = 5; localB[1][0] = 2; localB[1][1] = 1;
		
		/*int localA[2][2] = {{11, 12}, {15, 16}};
		int localB[2][2] = {{6, 5}, {2, 1}};*/
	}
	
	for(int i=0;i<2;i++)
	{
		if(i==0)
		{
			if((newRank==2)||(newRank==3))
			{
				MPI_Status status;
				MPI_Request send_request, recv_request;
				int left, right;
				MPI_Cart_shift(Santosh,1,1,&left,&right);
				MPI_Isend(&localA,4,MPI_INT,left,0,Santosh,&send_request);
				MPI_Irecv(&localA,4,MPI_INT,right,0,Santosh,&recv_request);
				MPI_Wait(&send_request,&status);
				MPI_Wait(&recv_request,&status);
			}
			
			if((newRank==1)||(newRank==3))
			{
				MPI_Status status1;
				MPI_Request send_request1, recv_request1;
				int up, down;
				MPI_Cart_shift(Santosh,0,1,&up,&down);
				MPI_Isend(&localB,4,MPI_INT,up,1,Santosh,&send_request1);
				MPI_Irecv(&localB,4,MPI_INT,down,1,Santosh,&recv_request1);
				MPI_Wait(&send_request1,&status1);
				MPI_Wait(&recv_request1,&status1);
			}
		}
		
		if(i!=0)
		{
				MPI_Status status;
				MPI_Request send_request, recv_request;
				int left, right;
				MPI_Cart_shift(Santosh,1,1,&left,&right);
				MPI_Isend(&localA,4,MPI_INT,left,0,Santosh,&send_request);
				MPI_Irecv(&localA,4,MPI_INT,right,0,Santosh,&recv_request);
				MPI_Wait(&send_request,&status);
				MPI_Wait(&recv_request,&status);	
				
				MPI_Status status1;
				MPI_Request send_request1, recv_request1;
				int up, down;
				MPI_Cart_shift(Santosh,0,1,&up,&down);
				MPI_Isend(&localB,4,MPI_INT,up,1,Santosh,&send_request1);
				MPI_Irecv(&localB,4,MPI_INT,down,1,Santosh,&recv_request1);
				MPI_Wait(&send_request1,&status1);
				MPI_Wait(&recv_request1,&status1);
		
		}
			
		for(int i1=0;i1<2;i1++)
		{
			for(int j1=0;j1<2;j1++)
			{
				for(int k1=0;k1<2;k1++)
				{
				 	localC[i1][j1] = localC[i1][j1] + localA[i1][k1]*localB[k1][j1];
				}
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	cout<<"local C: rank "<<newRank<<endl;
	for(int i=0; i<2; i++) 
	{
		for(int j=0; j<2; j++)
			cout << localC[i][j] << " ";
		cout << endl;
	}
	
	
	
	/*
	cout << "Local A & B at Rank " << newRank <<":" << endl;
	cout << "Local A: " << endl;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++)
			cout << localA[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	cout << "Local B: " << endl;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++)
			cout << localB[i][j] << " ";
		cout << endl;
	}
	*/
	/*
	vector<int> coords(dim);
	MPI_Cart_coords(Santosh, newRank, dim, coords.data());
	//cout << "My rank " << newRank << " & my coords: " << coords[0] << ", " << coords[1] << endl;
	
	int disp = 1, dir = 0;
	
	if(newRank == 5)
	{
		int left, right;
		MPI_Cart_shift(Santosh, dir, disp, &left, &right);
		
		cout << "Rank: " << newRank << ", my left: " << left << ", right: " << right << endl;  
		
	} */
	
     MPI_Finalize();
     return 0;
}