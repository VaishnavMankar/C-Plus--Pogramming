#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,i,j;
    float sum_x=0, sum_2x=0, sum_xy=0,sum_y=0;
    cout << "Enter the number of observation: "<< endl;
    cin >> n;
    float a,b;
    //vector<float>
    float x[n];
    //vector<float>
    float y[n];
    float agumented_matric[2][3];

    cout<< "Enter the value of x" << endl;
    for(i = 0; i < n; i++){
        cin >> x[i];
    }
    cout << "Enter the value of y"<< endl;
    for(i = 0; i < n; i++){
        cin >> y[i];
    }
    //commputing the sumation
    for(i = 0; i < n; i++){
        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
        sum_xy = sum_xy + (x[i] * y[i]);
        sum_2x = sum_2x + (x[i] * x[i]);
    }

    //finding sloap and intercept 
    agumented_matric[0][0]= sum_x;
    agumented_matric[0][1]= n;
    agumented_matric[0][2]= sum_y;
    agumented_matric[1][0]= sum_2x;
    agumented_matric[1][1]= sum_x;
    agumented_matric[1][2]= sum_xy;

    float ratio = agumented_matric[1][0]/agumented_matric[0][0];
    for(int i=0;i<3;i++){
        agumented_matric[1][i] = agumented_matric[1][i]-ratio*agumented_matric[0][i];
    }

    //printing upper triangular matrix
    for(i = 0;i < 2; i++){
        for(j = 0;j < 3; j++){
            cout<<agumented_matric[i][j]<<" ";
        }
        cout<<endl;
    }
    
    b = agumented_matric[1][2]/agumented_matric[1][1];
    a = (agumented_matric[0][2]-agumented_matric[0][1]*b)/agumented_matric[0][0];

    //...................output...........................
    cout<<"Equation of the line y = "<<a<<"x + "<< b<<endl;

}