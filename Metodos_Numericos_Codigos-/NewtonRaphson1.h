#pragma once
#include "Prerequisites.h"

class NewtonRaphsonPolinomio {
private:
    double x;  // Valor inicial
    double tolerancia;  // Criterio de convergencia

public:
    NewtonRaphsonPolinomio(double xInicial, double tol) : x(xInicial), tolerancia(tol) {}

    double funcion(double x) {
        return x * x * x + 2 * x * x + 10 * x - 20;
    }

    double derivada(double x) {
        return 3 * x * x + 4 * x + 10;
    }

    void iterar() {
        double xNuevo, error;
        int iteracion = 1;

        do {
            double f_x = funcion(x);
            double df_x = derivada(x);
            xNuevo = x - f_x / df_x;
            error = fabs((xNuevo - x) / xNuevo) * 100;

            cout << fixed << setprecision(5);
            cout << "Iteracion " << iteracion << ": x = " << x << ", f(x) = " << f_x
                << ", f'(x) = " << df_x << ", xNuevo = " << xNuevo << ", Error = " << error << "%" << endl;

            x = xNuevo;
            iteracion++;
        } while (error > tolerancia);
    }
};
