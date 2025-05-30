#include<iostream>
#include<vector>
using namespace std;

class Matrix{
private:
    int rows, cols;
    vector<vector<double>> data;

public:
    Matrix();
    Matrix(int r, int c);// Constructors
    Matrix(const Matrix &mat);
    ~Matrix();  // Destructor (optional, but keep it if declared in .cpp)

    void inputFileMatrix(const string &file);
    void displayMatrix();

    Matrix add(const Matrix &mat);
    Matrix sub(const Matrix &mat);
    Matrix mult(const Matrix &mat);

    bool isIdentity();
    bool isSymmetric();
    bool isDiagonallyDominant();

    // Gaussian Elimination simple pivoting
    Matrix GaussElimination(const Matrix &mat);
    Matrix LUusingDoolittle();
    Matrix LUusingCrout();
    Matrix CholeskyDecomposition();
    Matrix GaussJacobi(const Matrix &B, int maxIter, double tolerance);
    Matrix GaussSeidel(const Matrix &B, int maxIter, double tolerance);
};

       