#include <bits/stdc++.h>

using namespace std;

double F(double x) {
    return x - x*log(x);
}

double G(double x) {
    return -log(x);
}

double newton_rap(double x0, int iter_max = 1000, double eps = 0.00001) {
    double x1;
    int k = 0;
    while(1) {
        x1 = x0 - F(x0)/G(x0);
        if(fabs(F(x1)) <= eps || k >= iter_max) {
            return x1;
        }
        x0 = x1;
        k++;
    }
}

int main() {
    cout << newton_rap(5) << endl;
    return 0;
}
