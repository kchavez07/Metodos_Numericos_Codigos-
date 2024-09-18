#pragma once
#include "Prerequisites.h"

class NewtonRaphson2 {
private:
    double t;  // Valor inicial
    double tolerancia;  // Criterio de convergencia
    int maxIter;  // Máximo número de iteraciones

public:
    NewtonRaphson2(double tInicial, double tol, int iter) : t(tInicial), tolerancia(tol), maxIter(iter) {}

    double funcion(double t) 
    {
        return 70 * exp(-1.5 * t) + 20 * exp(-0.8 * t) - 10;
    }

    double derivada(double t) 
    {
        return -105 * exp(-1.5 * t) - 16 * exp(-0.8 * t);
    }

    void iterar() 
    {
        double tNuevo, error;
        int iteracion = 1;

        // Aseguramos el encabezado de la tabla con setw()
        cout << setw(12) << "Iteracion" << setw(12) << "t" << setw(12) << "f(t)"
            << setw(12) << "df(t)" << setw(12) << "tNuevo" << setw(12) << "Error %" << endl;

        do {
            double f_t = funcion(t);
            double df_t = derivada(t);
            tNuevo = t - f_t / df_t;
            error = fabs((tNuevo - t) / tNuevo) * 100;

            // Aseguramos que cada dato esté bien alineado en su columna
            cout << setw(12) << iteracion << setw(12) << t << setw(12) << f_t
                << setw(12) << df_t << setw(12) << tNuevo << setw(12) << error << "%" << endl;

            t = tNuevo;
            iteracion++;
        } while (error > tolerancia && iteracion <= maxIter);
    }
};
