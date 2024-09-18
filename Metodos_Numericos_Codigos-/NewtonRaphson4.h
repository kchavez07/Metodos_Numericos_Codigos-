#pragma once
#include "Prerequisites.h"

#ifndef NEWTONRAPHSON4_H
#define NEWTONRAPHSON4_H

class NewtonRaphson4 
{
public:
    double x0, tolerancia;
    int maxIter;

    NewtonRaphson4 (double x0_, double tol, int iter) : x0(x0_), tolerancia(tol), maxIter(iter) {}

    double f(double x) 
    {
        return exp(x) + x - 7;  // Ecuación: e^x + x - 7 = 0
    }

    double df(double x)
    {
        return exp(x) + 1;  // Derivada: e^x + 1
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
