#pragma once
#include "Prerequisites.h"

class NewtonRaphson1 
{
private:
    double x;  // Valor inicial
    double tolerancia;  // Criterio de convergencia
    int maxIter;  // Máximo número de iteraciones

public:
    NewtonRaphson1(double xInicial, double tol, int iter) : x(xInicial), tolerancia(tol), maxIter(iter) {}

    double funcion(double x) 
    {
        return x * x * x + 2 * x * x + 10 * x - 20;
    }

    double derivada(double x) 
    {
        return 3 * x * x + 4 * x + 10;
    }

    void iterar() 
    {
        double xNuevo, error;
        int iteracion = 1;

        // Aseguramos el encabezado de la tabla con setw()
        cout << setw(12) << "Iteracion" << setw(12) << "x" << setw(12) << "f(x)"
            << setw(12) << "df(x)" << setw(12) << "xNuevo" << setw(12) << "Error %" << endl;

        do {
            double f_x = funcion(x);
            double df_x = derivada(x);
            xNuevo = x - f_x / df_x;
            error = fabs((xNuevo - x) / xNuevo) * 100;

            // Aseguramos que cada dato esté bien alineado en su columna
            cout << setw(12) << iteracion << setw(12) << x << setw(12) << f_x
                << setw(12) << df_x << setw(12) << xNuevo << setw(12) << error << "%" << endl;

            x = xNuevo;
            iteracion++;
        } while (error > tolerancia && iteracion <= maxIter);
    }
};
