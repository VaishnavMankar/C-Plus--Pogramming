#include <vector>
#include <string>
using namespace std;

class Polynomial {
private:
    vector<float> X;
    vector<float> Y;
    int n;
    float interpolationX;

public:
    Polynomial(const std::string& filename);
    float lagrangeInterpolation();
    void leastSquaresLine();
    void leastSquaresParabola();
};

