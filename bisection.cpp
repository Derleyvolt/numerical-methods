#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double F(double x) {
    return -pow(2.7182, x)/2 + (2 * cos(x));
}

double bisection(double a, double b, int iter_max, double eps = 0.0001) {
    double x0;
    double interval = fabs(a-b);
    int k = 0;
    while(1) {
        x0 = (a+b)/2.0; // x0
        if(interval <= eps or k >= iter_max) {
            return x0;
        } else if(F(a) * F(x0) < 0) {
            b = x0;
        } else if(F(x0) * F(b) < 0) {
            a = x0;
        }

        interval = interval/2.0;

        k++;
    }
}

int main() {
    cout << fixed << setprecision(4) << bisection(0.0, 1.0, 1000) << endl;
    return 0;
}