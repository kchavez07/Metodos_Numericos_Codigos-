#ifndef BISECCION_H
#define BISECCION_H

#include <iostream>
#include <iomanip>
#include <cmath>

class Biseccion {
protected:
    double x0, x1, xm, tol;
    int maxIter;

public:
    Biseccion(double x0, double x1, double tol, int maxIter) : x0(x0), x1(x1), tol(tol), maxIter(maxIter) {}

    virtual double funcion(double x) = 0;  // Función virtual para cada ecuación específica.

    void metodoBiseccion() {
        double f0, f1, fm;
        int iter = 0;
        double errorPorcentual = 100;  // Inicialmente el error es 100%
        double errorAnterior = 0;

        // Encabezados de la tabla
        std::cout << std::setw(10) << "Iteracion" << std::setw(10) << "x0" << std::setw(10) << "x1" << std::setw(10) << "xm"
            << std::setw(15) << "f(xm)" << std::setw(15) << "f(x0)" << std::setw(15) << "f(x1)"
            << std::setw(15) << "Error %" << std::endl;

        while (iter < maxIter && errorPorcentual > tol) {
            xm = (x0 + x1) / 2.0;
            f0 = funcion(x0);
            f1 = funcion(x1);
            fm = funcion(xm);

            // Mostrar resultados de manera más legible
            std::cout << std::setw(10) << iter
                << std::setw(10) << std::setprecision(6) << x0
                << std::setw(10) << std::setprecision(6) << x1
                << std::setw(10) << std::setprecision(6) << xm
                << std::setw(15) << std::setprecision(6) << fm
                << std::setw(15) << std::setprecision(6) << f0
                << std::setw(15) << std::setprecision(6) << f1;

            // Cálculo del error porcentual
            if (iter > 0) {
                errorPorcentual = fabs((xm - errorAnterior) / xm) * 100; // Error porcentual en porcentaje
                std::cout << std::setw(15) << std::setprecision(4) << errorPorcentual << "%" << std::endl;
            }
            else {
                std::cout << std::setw(15) << "N/A" << std::endl; // En la primera iteración no hay error previo
            }

            errorAnterior = xm;

            if (fabs(fm) < tol) {
                break;
            }

            if (f0 * fm < 0) {
                x1 = xm;
            }
            else {
                x0 = xm;
            }

            iter++;
        }
    }
};

#endif
