#pragma once
#include "Prerequisites.h"
#include "Biseccion.h"

#ifndef BISECCION3_H
#define BISECCION3_H

class Biseccion3 : public Biseccion {
public:
    Biseccion3(double x0, double x1, double tol, int maxIter) : Biseccion(x0, x1, tol, maxIter) {}

    double funcion(double m) override {
        double g = 9.8;
        double c = 15.0;
        double v = 35.0;
        double t = 9.0;
        return (g * m / c) * (1 - exp(-c * t / m)) - v;
    }

    // Sobrescribimos el método bisección para agregar mayor separación en las primeras columnas
    void metodoBiseccion() {
        double f0, f1, fm;
        int iter = 0;
        double errorPorcentual = 100;  // Inicialmente el error es 100%
        double errorAnterior = 0;

        // Encabezados de la tabla con mayor separación en las primeras 4 columnas
        std::cout << std::setw(15) << "Iteracion" << std::setw(15) << "x0" << std::setw(15) << "x1" << std::setw(15) << "xm"
            << std::setw(15) << "f(xm)" << std::setw(15) << "f(x0)" << std::setw(15) << "f(x1)"
            << std::setw(20) << "Error %" << std::endl;

        while (iter < maxIter && errorPorcentual > tol) {
            xm = (x0 + x1) / 2.0;
            f0 = funcion(x0);
            f1 = funcion(x1);
            fm = funcion(xm);

            // Mostrar resultados con mayor separación en las primeras 4 columnas
            std::cout << std::setw(15) << iter
                << std::setw(15) << std::setprecision(6) << x0
                << std::setw(15) << std::setprecision(6) << x1
                << std::setw(15) << std::setprecision(6) << xm
                << std::setw(15) << std::setprecision(6) << fm
                << std::setw(15) << std::setprecision(6) << f0
                << std::setw(15) << std::setprecision(6) << f1;

            // Cálculo del error porcentual
            if (iter > 0) {
                errorPorcentual = fabs((xm - errorAnterior) / xm) * 100; // Error porcentual en porcentaje
                std::cout << std::setw(20) << std::setprecision(4) << errorPorcentual << "%" << std::endl;
            }
            else {
                std::cout << std::setw(20) <<  "N/A"  << std::endl; // En la primera iteración no hay error previo
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
