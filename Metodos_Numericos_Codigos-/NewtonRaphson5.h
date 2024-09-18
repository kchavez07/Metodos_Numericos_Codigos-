#pragma once
#include "Prerequisites.h"

#ifndef NEWTONRAPHSON5_H
#define NEWTONRAPHSON5_H

#include <iostream>
#include <cmath>
using namespace std;

class NewtonRaphson5 
{
public:
    double x0, tolerancia;
    int maxIter;

    NewtonRaphson5 (double x0_, double tol, int iter) : x0(x0_), tolerancia(tol), maxIter(iter) {}

    double f(double x) 
    {
        return log(x) + pow(x, 2) - 3;  // Ecuación: ln(x) + x^2 - 3 = 0
    }

    double df(double x) 
    {
        return (1 / x) + 2 * x;  // Derivada: 1/x + 2x
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

