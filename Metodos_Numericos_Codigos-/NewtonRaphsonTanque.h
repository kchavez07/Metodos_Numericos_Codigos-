#pragma once
#include "Prerequisites.h"

#define PI 3.14159265358979323846  // Definir pi

class NewtonRaphsonTanque {
private:
    double h;  // Valor inicial para la profundidad
    double tolerancia;  // Criterio de convergencia
    int maxIter;  // Máximo número de iteraciones
    const double R = 3.0;  // Radio del tanque
    const double V = 30.0;  // Volumen deseado

public:
    NewtonRaphsonTanque(double hInicial, double tol, int iter) : h(hInicial), tolerancia(tol), maxIter(iter) {}

    // Función para el volumen del tanque
    double funcion(double h) {
        return (PI * h * h * (3 * R - h)) / 3 - V;
    }

    // Derivada de la función del volumen del tanque
    double derivada(double h) {
        return (2 * PI * h * (3 * R - h) - PI * h * h) / 3;
    }

    // Método para iterar utilizando Newton-Raphson
    void iterar() {
        double hNuevo, error;
        int iteracion = 1;

        // Encabezado de la tabla
        std::cout << std::setw(12) << "Iteracion" << std::setw(12) << "h"
            << std::setw(12) << "f(h)" << std::setw(12) << "f'(h)"
            << std::setw(12) << "hNuevo" << std::setw(12) << "Error %" << std::endl;

        do {
            double f_h = funcion(h);        // Función f(h)
            double df_h = derivada(h);      // Derivada f'(h)
            hNuevo = h - (f_h / df_h);      // Fórmula de Newton-Raphson
            error = fabs((hNuevo - h) / hNuevo) * 100; // Error porcentual

            // Mostramos resultados
            std::cout << std::fixed << std::setprecision(4);
            std::cout << std::setw(12) << iteracion << std::setw(12) << h << std::setw(12) << f_h
                << std::setw(12) << df_h << std::setw(12) << hNuevo << std::setw(12) << error << "%" << std::endl;

            h = hNuevo;  // Actualizamos h para la siguiente iteración
            iteracion++;
        } while (error > tolerancia && iteracion <= maxIter);
    }
};