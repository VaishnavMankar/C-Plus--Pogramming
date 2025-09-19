#include<iostream>
#include<vector>
using namespace std;

class LagrangesInterpolation {
private:
    vector<float> X;
    vector<float> Y;
    int n;

public:
    LagrangesInterpolation(int n);
    void inputValues();
    float interpolate(float x);
};