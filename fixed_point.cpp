#include <bits/stdc++.h>

using namespace std;

double F(double x) {
    return pow(x, 3) - 9*x + 3;
}

double G(double x) {
    return (pow(x, 3) + 3)/9.0;
}

double point_fixed(double x0, int iter_max = 1e4, double eps = 1e-4) {
    double x1;
    int k = 0;
    while(1) {
        x1 = G(x0);
        if(fabs(F(x1)) <= eps || fabs(x1-x0) <= eps || k >= iter_max) {
            return x1;
        }

        x0 = x1;
        k++;
    }
}

int main() {
    cout << point_fixed(1) << endl;
    return 0;
}