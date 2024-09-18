#pragma once
#pragma once
#include "Prerequisites.h"

#ifndef NEWTONRAPHSON3_H
#define NEWTONRAPHSON3_H

class NewtonRaphson3 
{
public:
    double x0, tolerancia;
    int maxIter;

    NewtonRaphson3 (double x0_, double tol, int iter) : x0(x0_), tolerancia(tol), maxIter(iter) {}

    double f(double x) 
    {
        return pow(x, 3) - 2 * x - 2;  // Ecuación: x^3 - 2x - 2 = 0
    }

    double df(double x) 
    {
        return 3 * pow(x, 2) - 2;  // Derivada: 3x^2 - 2
    }

    void iterar() 
    {
        int iter = 0;
        double xNuevo, fx, dfx, error;

        cout << "Iteracion\tx\t\tf(x)\t\tdf(x)\t\txNuevo\t\tError %\n";
        while (iter < maxIter) 
        {
            fx = f(x0);
            dfx = df(x0);
            xNuevo = x0 - fx / dfx;
            error = fabs((xNuevo - x0) / xNuevo) * 100;

            cout << iter + 1 << "\t\t" << x0 << "\t\t" << fx << "\t\t" << dfx << "\t\t" << xNuevo << "\t\t" << error << "%" << endl;

            if (fabs(fx) < tolerancia || error < tolerancia) {
                break;
            }

            x0 = xNuevo;
            iter++;
        }
    }
};

#endif

