#include "Matrix.hpp"
#include <fstream>



void Matrix::inputFromFile(const string &filename){

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }


    // if (data) {  
    //     for (int i = 0; i < rows; i++) {
    //         delete[] data[i];
    //     }
    //     delete[] data;
    // }

    // file >> rows >> cols ;
    // data = new int*[rows];
    // for (int i = 0; i < rows; i++) {
    //     data[i] = new int[cols];
    //     for (int j = 0; j < cols; j++) {
    //         file >> data[i][j];
    //     }
    // }


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(file >> data[i][j])) {  // if no data in the file
                cout << "Error: Invalid data format in file.\n";
                return;
            }
        }
    }

    file.close();
}

Matrix::Matrix(int r, int c) {
    rows = r;
    cols = c;
    data =new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
    }
}

Matrix::Matrix(const Matrix & other) {
    rows = other.rows;
    cols = other.cols;
    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    if(data){
    for(int i =0; i < rows; i++){
        delete[] data[i];
    }
    delete[] data;
  }
}

void Matrix::input() {
    cout << "Enter elements for " << rows << "x" << cols << " matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> data[i][j];
        }
    }
}

void Matrix::display() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::add(const Matrix& second) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + second.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::sub(const Matrix & second) const {
 Matrix result2(rows, cols);
 for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
   result2.data[i][j] = data[i][j] - second.data[i][j];
    }
 } 
   return result2;
}

Matrix Matrix::mult(const Matrix & second) const{
    if (cols != second.rows) {
        cout << "Matrices cannot be multiplied.\n";
        return Matrix(0, 0); // Return empty matrix
    }

    Matrix result3(rows, second.cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<second.cols; j++){     
           result3.data[i][j]=0;

        }
    }

     for(int i=0; i<rows; i++){
          for(int j=0; j<second.cols; j++){
             for(int k=0; k<cols; k++){
                result3.data[i][j] += data[i][k] * second.data[k][j];
            }
          }
    }
    return result3;
}



Matrix Matrix::upperTriangular() const {
    Matrix result4(*this);
    for(int k=0; k < result4.rows -1; k++){
        if(data[k][k]==0){
            for(int i= k + 1; i < result4.rows; i++){
                if(result4.data[i][k] != 0){
                 {
                   swap(result4.data[k],result4.data[i]);
                 } 
                   break;
                }
            }
        }
    if(result4.data[k][k] == 0){
        cout << "Matrix is singular.\n";
        return  Matrix(0,0); 
    }

    for(int i=k+1; i<result4.rows; i++){
        double factor = result4.data[i][k] / result4.data[k][k];
          for(int j= k+1; j<result4.cols; j++){
            result4.data[i][j] -= factor * result4.data[k][j];
        }
        result4.data[i][k] = 0;

      }

    }
    return result4;
}

// Matrix Matrix::lowerTriangular() const {
//     Matrix result5(*this); 

//     for (int k = 0; k < result5.rows; k++) {  
        
//         if (result5.data[k][k] == 0) {
//             for (int i = k + 1; i < result5.rows; i++) {
//                 if (result5.data[i][k] != 0) {
                    
//                     swap(result5.data[k], result5.data[i]);
//                     break;
//                 }
//             }
//         }

    
//         if (result5.data[k][k] == 0) {
//             cout << "Matrix is singular, cannot convert to lower triangular.\n";
//             return Matrix(result5.rows, result5.cols);
//         }

    
//         for (int i = 0; i < k; i++) {  
//             double factor = result5.data[i][k] / result5.data[k][k];

//             for (int j = k; j < result5.cols; j++) {  
//                 result5.data[i][j] -= factor * result5.data[k][j];
//             }
//         }
//     }

//     return result5;  
// }




  void Matrix::backSubstitution(double x[]) {  
    for (int i = rows - 1; i >= 0; i--) {
        if (data[i][i] == 0) {
            cout << "No unique solution exists.\n";
            return;
        }
        x[i] = data[i][cols - 1];  
        for (int j = i + 1; j < rows; j++) {
            x[i] -= data[i][j] * x[j];
        }
        x[i] /= data[i][i];  
    }
}



void Matrix::luDecomposition(Matrix &L, Matrix &U) const {
    if (rows != cols) {
        cout << "LU Decomposition only works for square matrices.\n";
        return;
    }

    // Initialize L and U with zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            L.data[i][j] = 0;
            U.data[i][j] = 0;
        }
    }

    // LU Decomposition Logic
    for (int i = 0; i < rows; i++) {
        // **Upper Triangular Matrix (U)**
        for (int k = i; k < cols; k++) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L.data[i][j] * U.data[j][k];
            }
            U.data[i][k] = data[i][k] - sum;
        }

        // **Lower Triangular Matrix (L)**
        for (int k = i; k < rows; k++) {
            if (i == k) {
                L.data[i][i] = 1;  // **L matrix diagonal 1**
            } else {
                int sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += L.data[k][j] * U.data[j][i];
                }
                if (U.data[i][i] == 0) {
                    cout << "LU Decomposition failed (zero pivot encountered).\n";
                    return;
                }
                L.data[k][i] = (data[k][i] - sum) / U.data[i][i];
            }
        }
    }
}






  bool Matrix::isIdentity() const 
 {
   if(rows != cols)
   return false;

   for(int i =0; i<rows; i++){
    for(int j=0; j<cols; j++){
        if(i == j && data[i][j] !=1  ||  i != j && data[i][j] !=0){
        return false;      
        }
    }
   }
   return true;
}

  bool Matrix::isSymmetric() const
  {
    if(rows!= cols)
    return false;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(data[i][j]!= data[j][i])
            return false;
        }
    }
    return true;

 }
