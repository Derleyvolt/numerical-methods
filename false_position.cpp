#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double F(double x) {
    return -pow(2.7182, x)/2 + (2 * cos(x));
}

double false_position(double a, double b, int iter_max, double eps1 = 1e-4, double eps2 = 1e-4) {
    double x2;

    if(F(a) * F(b) > 0) {
        cout << "Erro: Funcao nao muda de sinal entre a e b" << endl;
        exit(0);
    }

    double interval = fabs(b-a);

    if(interval < eps1) {
        return a;
    }

    if(fabs(F(a)) < eps2) {
        return a;
    }

    if(fabs(F(b)) < eps2) {
        return b;
    }

    int k = 0;

    while(1) {
        interval = fabs(a-b);
        x2 = (a*F(b) - b*F(a))/(F(b)-F(a));

        // distância do y ao eixo x é pequeno o suficiente
        if(fabs(x2) <= eps2) {
            return x2;
        }

        // número de iterações foi superado ou a diferença no eixo x é pequeno o suficiente..
        if(k >= iter_max or interval <= eps1) {
            return x2;
        } else if(F(a) * F(x2) < 0) {
            b = x2;
        } else {
            a = x2;
        }
        k++;
    }
}

int main() {
    cout << fixed << setprecision(4) << false_position(0, 1, 1e4) << endl;
    return 0;
}