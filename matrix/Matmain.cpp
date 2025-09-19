#include<iostream>
#include<string>
#include "Matrix.hpp"
 
int main()
{
    int rows,cols;
    string filename1,filename2 ,fileLU;
    cout << "Enter the number of rows and colums:";
    cin >> rows >> cols;

   Matrix matrix1(rows,cols);
   Matrix matrix2(rows,cols);
   
   cout << "Enter filename for Matrix 1:\n";
   cin >> filename1;
   matrix1.inputFromFile(filename1);
  
   cout << "Enter filename for Matrix 2:\n";
   cin >> filename2;
   matrix2.inputFromFile(filename2);
    
   Matrix result = matrix1.add(matrix2);
   cout << "Summation of Matrix:\n";
   result.display();
    
   Matrix result2 = matrix1.sub(matrix2);
   cout << "Subtraction of Matrix:\n";
   result2.display();
   
   Matrix result3 = matrix1.mult(matrix2);
   cout << "Multiplication of Matrix:\n";
   result3.display();

   
   cout << "\n";
   if(result3.isIdentity()){
    cout << "the matrix is an identity matrix. \n";
   }
   else{
    cout << "the matrix is not an identity matrix. \n";
    }
   


   cout<<"\n";
   if(result.isSymmetric()){
    cout << "the matrix is a symmetric matrix. \n";
   }
   else{
    cout << "the matrix is not a symmetric matrix. \n";
    }


   cout<<"Gauss elimination with basic pivoting.\n";
   Matrix result4 = matrix1.upperTriangular();
   cout << "Upper triangular matrix:\n";
   result4.display();
  
//   cout<<"lower triangular matrix:\n";
//   Matrix result5 = matrix1.lowerTriangular();
//   result5.display();





   double x[rows];
   cout << "Back sunstitution.\n";
   result4.backSubstitution(x);


   cout<<"values for x \n";
   for(int i=0;i<rows;i++){
    cout << "x[" << i << "] = " << x[i] << endl;
   }
  


   cout << "Enter filename for LU Decomposition matrix:\n";
   cin >> fileLU;
   Matrix matrixLU(rows, cols);
   matrixLU.inputFromFile(fileLU);
   
   // LU Decomposition
   Matrix L(rows, cols), U(rows, cols);
   matrixLU.luDecomposition(L, U);
   
   cout << "Lower Triangular Matrix (L):\n";
   L.display();
   
   cout << "Upper Triangular Matrix (U):\n";
   U.display();



   return 0;
}
