#include<iostream>
using namespace std;

//convert the augmented matrix to upper triangular matrix form
void convertToUpperTriangular(float a[3][4], int n){
    int i, j, k;
    float ratio;

    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            ratio = a[j][i] / a[i][i];
            for(k = 0; k < n + 1; k++){
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }
}

//performs Back Substitution to find the value of unknowns
void ApplyBackSubstitution(float a[3][4], float value[], int n){
    for(int i = n - 1; i >= 0; i--){
        float sum = 0;
        for(int j = i + 1; j < n; j++){
            sum += a[i][j] * value[j];
        }
        value[i] = (a[i][n] - sum) / a[i][i];
    }
}

int main(){
    int n, i;
    float sx = 0, sy = 0, sxy = 0, sx2y = 0, sx2 = 0, sx3 = 0, sx4 = 0;
    float values[3];

    cout << "Enter number of observations: ";
    cin >> n;
    float x[n], y[n];
    float augmented_matrix[3][4];

    cout << "Enter values of x:\n";
    for(i = 0; i < n; i++) cin >> x[i];

    cout << "Enter values of y:\n";
    for(i = 0; i < n; i++) cin >> y[i];

    // Calculating required summations
    for(i = 0; i < n; i++){
        sx += x[i];
        sy += y[i];
        sxy += x[i] * y[i];
        sx2 += x[i] * x[i];
        sx3 += x[i] * x[i] * x[i];
        sx4 += x[i] * x[i] * x[i] * x[i];
        sx2y += x[i] * x[i] * y[i];
    }

    // Creating the augmented matrix
    augmented_matrix[0][0] = sx2;
    augmented_matrix[0][1] = sx;
    augmented_matrix[0][2] = n;
    augmented_matrix[0][3] = sy;

    augmented_matrix[1][0] = sx3;
    augmented_matrix[1][1] = sx2;
    augmented_matrix[1][2] = sx;
    augmented_matrix[1][3] = sxy;

    augmented_matrix[2][0] = sx4;
    augmented_matrix[2][1] = sx3;
    augmented_matrix[2][2] = sx2;
    augmented_matrix[2][3] = sx2y;

    convertToUpperTriangular(augmented_matrix, 3);
    ApplyBackSubstitution(augmented_matrix, values, 3);

    cout << "Values found: a = " << values[0] << ", b = " << values[1] << ", c = " << values[2] << endl;
    cout << "Equation of the parabola: y = " << values[0] << "x^2 + " << values[1] << "x + " << values[2] << endl;

    return 0;
}
