#include "Prerequisites.h"
#ifndef BISECCION2_H
#define BISECCION2_H

class Biseccion2 {
public:
    double bisectionMethod(double (*func)(double), double t0, double t1, double tol, int maxIter) {
        double tm, error = 100;
        int iter = 0;

        cout << "Ejercicio 2: Calcular el valor de i para que A = 4000" << endl;
        cout << "Iteración\t t0\t\t t1\t\t tm\t\t f(tm)\t\t Error porcentual (%)\n";

        while (error > tol && iter < maxIter) {
            tm = (t0 + t1) / 2.0;
            double f_tm = func(tm);
            error = abs((t1 - t0) / tm) * 100;

            cout << fixed << setprecision(4) << iter + 1 << "\t\t "
                << t0 << "\t " << t1 << "\t " << tm << "\t "
                << f_tm << "\t " << error << " %\n";

            if (f_tm == 0.0 || error < tol) {
                break;
            }

            if (func(t0) * f_tm < 0) {
                t1 = tm;
            }
            else {
                t0 = tm;
            }

            iter++;
        }

        cout << "El valor aproximado de i es: " << tm << endl;
        return tm;
    }
};

#endif