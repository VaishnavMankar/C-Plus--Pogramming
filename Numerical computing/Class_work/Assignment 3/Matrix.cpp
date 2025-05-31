#include "Matrix.hpp"
#include<iostream>
#include <fstream>
#include <cmath>
using namespace std;

Matrix::Matrix()
{
    rows = 0;
    cols = 0;
}
Matrix::Matrix(int r, int c) : rows(r), cols(c), data(r, vector<double>(c, 0)){
}

Matrix::Matrix(const Matrix &mat) : rows(mat.rows), cols(mat.cols), data(mat.data){
}

Matrix::~Matrix(){
}

void Matrix::inputFileMatrix(const std::string &File)
{
    ifstream inputFile(File);

    if (!inputFile.is_open()){
        cerr << "Error: Unable to open input file!" << endl;
        return;
    }

    int newRows, newCols;
    inputFile >> newRows >> newCols;

    // Update matrix dimensions
    rows = newRows;
    cols = newCols;

    // Resize the vector with zero-initialization
    data.resize(rows, vector<double>(cols, 0.0));

    // Read matrix values from the file
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (!(inputFile >> data[i][j])){
                cerr << "Error: Not enough data in input file!" << endl;
                inputFile.close();
                return;
            }
        }
    }

    inputFile.close();
    cout << "Matrix read from file successfully!" << endl;
}


void Matrix::displayMatrix()
{
    cout << "Matrix: " << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::add(const Matrix &mat)
{
    if (rows != mat.rows || cols != mat.cols){
        cerr << "Error: Number of rows and columns are not same!" << endl;
        return Matrix(0, 0); // Explicitly return a properly allocated empty matrix
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            result.data[i][j] = this->data[i][j] + mat.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::mult(const Matrix &mat)
{
    if (cols != mat.rows){
        cerr << "Error: Matrices cannot be multiplied, incompatible dimensions!" << endl;
        return Matrix(0,0); // Return an empty matrix
    }

    Matrix result(rows, mat.cols); // Create result matrix of size (rows x mat.cols)

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < mat.cols; j++){
            result.data[i][j] = 0;         // Initialize result cell
            for (int k = 0; k < cols; k++) { // Multiply row elements by column elements
                result.data[i][j] += this->data[i][k] * mat.data[k][j];
            }
        }
    }

    return result;
}

Matrix Matrix::sub(const Matrix &mat)
{
    if (rows != mat.rows || cols != mat.cols){
        cerr << "Error: Number of rows and columns are not same!" << endl;
        return Matrix(0, 0); // Return empty matrix
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = this->data[i][j] - mat.data[i][j];

    return result;
}
bool Matrix::isIdentity()
{
    if (rows != cols)
        return false;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (i == j && data[i][j] != 1){
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isSymmetric()
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

bool Matrix::isDiagonallyDominant(){
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < cols; j++) {
            if (i != j) {
                sum += abs(data[i][j]); // Using abs instead of fabs for clarity
            }
        }
        if (abs(data[i][i]) <= sum) { // Ensuring strict dominance
            return false;
        }
    }
    return true;
}

// gauss elimination with Simple Pivoting

// LU Decomposition
Matrix Matrix::LUusingDoolittle() {
    if (rows != cols) {
        cerr << "Error: LU decomposition requires a square matrix!" << endl;
        return Matrix(0, 0);
    }

    int n = rows;
    Matrix L(n, n), U(n, n); // Initialize L and U as empty matrices

    // Compute L and U 
    for (int i = 0; i < n; i++) {
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L.data[i][j] * U.data[j][k];
            }
            U.data[i][k] = data[i][k] - sum;
        }

        for (int k = i; k < n; k++) {
            if (i == k)
                L.data[i][i] = 1;
            else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += L.data[k][j] * U.data[j][i];
                }
                L.data[k][i] = (data[k][i] - sum) / U.data[i][i];
            }
        }
    } 
    // Matrix L(n, n), U(*this);

    // for (int i = 0; i < n; i++)
    //     L.data[i][i] = 1;

    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (fabs(U.data[i][i]) < 1e-9) {
    //             cerr << "Error: Zero pivot encountered in LU Decomposition!" << endl;
    //             return Matrix(0, 0);
    //         }

    //         double factor = U.data[j][i] / U.data[i][i];
    //         L.data[j][i] = factor;
    //         for (int k = i; k < n; k++)
    //             U.data[j][k] -= factor * U.data[i][k];
    //     }
    // }

    L.displayMatrix();
    U.displayMatrix();
    
    Matrix result = L.mult(U);
    result.displayMatrix();
    return result;
}

Matrix Matrix::LUusingCrout() {
    if (rows != cols) {
        cerr << "Error: LU decomposition requires a square matrix!" << endl;
        return Matrix(0, 0);
    }

    int n = rows;
    Matrix L(n, n), U(n, n);

    for (int j = 0; j < n; j++) {
        U.data[j][j] = 1; // Unit diagonal for U

        for (int i = j; i < n; i++) {
            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L.data[i][k] * U.data[k][j];
            }
            L.data[i][j] = data[i][j] - sum;
        }

        for (int i = j + 1; i < n; i++) {
            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L.data[j][k] * U.data[k][i];
            }
            U.data[j][i] = (data[j][i] - sum) / L.data[j][j];
        }
    }

    L.displayMatrix();
    U.displayMatrix();

    Matrix result = L.mult(U);
    result.displayMatrix();
    return result;
}

Matrix Matrix::CholeskyDecomposition() {
    if (rows != cols) {
        cerr << "Error: Cholesky decomposition requires a square matrix!" << endl;
        return Matrix(0, 0);
    }

    int n = rows;
    Matrix L(n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;

            if (j == i) {
                for (int k = 0; k < j; k++) {
                    sum += pow(L.data[j][k], 2);
                }
                double val = data[j][j] - sum;
                if (val <= 0) {
                    cerr << "Error: Matrix is not positive definite!" << endl;
                    return Matrix(0, 0);
                }
                L.data[j][j] = sqrt(val);
            } else {
                for (int k = 0; k < j; k++) {
                    sum += L.data[i][k] * L.data[j][k];
                }
                L.data[i][j] = (data[i][j] - sum) / L.data[j][j];
            }
        }
    }

    L.displayMatrix();

    Matrix Lt(n, n);
    // Compute transpose of L
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            Lt.data[j][i] = L.data[i][j];

    Lt.displayMatrix();

    Matrix result = L.mult(Lt);
    result.displayMatrix();

    return result;
}


//Gauss-Jacobi Method
Matrix Matrix::GaussJacobi(const Matrix &b, int maxIter, double tolerance){
    // if (!isDiagonallyDominant()) {
    //     cerr << "Error: Matrix is not diagonally dominant! Gauss-Jacobi method cannot proceed." << endl;
    //     return Matrix(0, 0);
    // }

    Matrix x(rows, 1); // Initialize solution vector with zeros
    Matrix prev_x(x);

    for (int iter = 0; iter < maxIter; iter++) {
        for (int i = 0; i < rows; i++) {
            double sum = 0;
            for (int j = 0; j < cols; j++) {
                if (i != j) {
                    sum += data[i][j] * prev_x.data[j][0];
                }
            }
            x.data[i][0] = (b.data[i][0] - sum) / data[i][i];
        }

        // Check convergence
        double error = 0;
        for (int i = 0; i < rows; i++) {
            error += abs(x.data[i][0] - prev_x.data[i][0]);
        }
        if (error < tolerance) {
            return x;
        }
        prev_x = x;
    }

    return x;
}

// Gauss-Seidel Method
Matrix Matrix::GaussSeidel(const Matrix &b, int maxIter, double tolerance) {
    // if (!isDiagonallyDominant()) {
    //     cerr << "Error: Matrix is not diagonally dominant! Gauss-Seidel method cannot proceed." << endl;
    //     return Matrix(0, 0);
    // }

    Matrix x(rows, 1); // Initialize solution vector with zeros

    for (int iter = 0; iter < maxIter; iter++) {
        Matrix prev_x(x);
        
        for (int i = 0; i < rows; i++) {
            double sum = 0;
            for (int j = 0; j < cols; j++) {
                if (i != j) {
                    sum += data[i][j] * x.data[j][0]; // Use updated values immediately
                }
            }
            x.data[i][0] = (b.data[i][0] - sum) / data[i][i];
        }

        // Check convergence
        double error = 0;
        for (int i = 0; i < rows; i++) {
            error += abs(x.data[i][0] - prev_x.data[i][0]);
        }
        if (error < tolerance) {
            return x;
        }
    }

    return x;
}
Matrix Matrix::GaussElimination(const Matrix &mat)
{
    if (rows != mat.rows || mat.cols != 1){
        cerr << "Error: Augment matrix must have the same number of rows and exactly one column." << endl;
        return *this;
    }

    // Augment the matrix
    Matrix obj1(*this); // Copy current matrix

    obj1.cols += 1; // Increase column count

    for (int i = 0; i < rows; i++){
        // Check if row size is as expected before augmentation
        if (obj1.data[i].size() == obj1.cols - 1){
            obj1.data[i].push_back(mat.data[i][0]); // Append column
        }
        else{
            cerr << "Error: Row " << i << " has unexpected size! Expected " << obj1.cols - 1 << ", got " << obj1.data[i].size() << endl;
            return *this;
        }
    }

    int n = obj1.rows;

    for (int i = 0; i < n; i++){
        int maxIndex = i;

        for (int k = i + 1; k < n; k++){
            if (fabs(obj1.data[k][i]) > fabs(obj1.data[maxIndex][i])){
                maxIndex = k;
            }
        }

        if (maxIndex != i){
            std::swap(obj1.data[i], obj1.data[maxIndex]);
        }

        if (fabs(obj1.data[i][i]) < 1e-9){
            obj1;
        }

        for (int j = i + 1; j < obj1.cols; j++){
            obj1.data[i][j] /= obj1.data[i][i];
        }

        obj1.data[i][i] = 1;

        for (int k = i + 1; k < n; k++){
            double factor = obj1.data[k][i];

            for (int j = i; j < obj1.cols; j++){
                obj1.data[k][j] -= factor * obj1.data[i][j];
            }
        }
    }

    // Back-substitution to find the solution
    Matrix result(n, 1);

    for (int i = n - 1; i >= 0; i--){
        result.data[i][0] = obj1.data[i][n];

        for (int j = i + 1; j < n; j++){
            result.data[i][0] -= obj1.data[i][j] * result.data[j][0];
        }
    }

    return result;
}
