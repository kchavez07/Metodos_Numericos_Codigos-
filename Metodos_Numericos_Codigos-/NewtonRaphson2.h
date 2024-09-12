#pragma once
#include "Prerequisites.h"

class NewtonRaphsonBacterias {
private:
    double t;  // Valor inicial
    double tolerancia;  // Criterio de convergencia

public:
    NewtonRaphsonBacterias(double tInicial, double tol) : t(tInicial), tolerancia(tol) {}

    double funcion(double t) {
        return 70 * exp(-1.5 * t) + 20 * exp(-0.8 * t) - 10;
    }

    double derivada(double t) {
        return -105 * exp(-1.5 * t) - 16 * exp(-0.8 * t);
    }

    void iterar() {
        double tNuevo, error;
        int iteracion = 1;

        do {
            double f_t = funcion(t);
            double df_t = derivada(t);
            tNuevo = t - f_t / df_t;
            error = fabs((tNuevo - t) / tNuevo) * 100;

            cout << fixed << setprecision(5);
            cout << "Iteracion " << iteracion << ": t = " << t << ", f(t) = " << f_t
                << ", f'(t) = " << df_t << ", tNuevo = " << tNuevo << ", Error = " << error << "%" << endl;

            t = tNuevo;
            iteracion++;
        } while (error > tolerancia);
    }
};