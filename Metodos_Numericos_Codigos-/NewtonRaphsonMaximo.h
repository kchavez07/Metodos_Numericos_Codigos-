#pragma once
#include "Prerequisites.h"

class NewtonRaphsonMaximo
{
private:
    double x;  // Valor inicial
    double tolerancia;  // Criterio de convergencia
    int maxIter;  // Máximo número de iteraciones

public:
    NewtonRaphsonMaximo(double xInicial, double tol, int iter) : x(xInicial), tolerancia(tol), maxIter(iter) {}

    // Función original
    double funcion(double x)
    {
        return (1 / (pow(x - 4, 2) + 1)) - 2;
    }

    // Primera derivada
    double derivada(double x)
    {
        return -2 * (x - 4) / pow((pow(x - 4, 2) + 1), 2);
    }

    // Segunda derivada
    double segundaDerivada(double x)
    {
        return (2 * (pow(x - 4, 2) - 1)) / pow((pow(x - 4, 2) + 1), 3);
    }

    // Método para iterar utilizando Newton-Raphson
    void iterar()
    {
        double xNuevo, error;
        int iteracion = 1;

        // Encabezado de la tabla
        std::cout << std::setw(12) << "Iteracion" << std::setw(12) << "x"
            << std::setw(12) << "f'(x)" << std::setw(12) << "f''(x)"
            << std::setw(12) << "xNuevo" << std::setw(12) << "Error %" << std::endl;

        do {
            double f1_x = derivada(x);        // Primera derivada
            double f2_x = segundaDerivada(x); // Segunda derivada

            // Verificamos si la segunda derivada es muy pequeña o cero
            if (fabs(f2_x) < 1e-6) {
                std::cout << "Advertencia: La segunda derivada es muy pequeña o cero, no se puede continuar." << std::endl;
                break;
            }

            xNuevo = x - (f1_x / f2_x);       // Fórmula de Newton-Raphson
            error = fabs((xNuevo - x) / xNuevo) * 100; // Error porcentual

            // Mostramos resultados
            std::cout << std::fixed << std::setprecision(4);
            std::cout << std::setw(12) << iteracion << std::setw(12) << x << std::setw(12) << f1_x
                << std::setw(12) << f2_x << std::setw(12) << xNuevo << std::setw(12) << error << "%" << std::endl;

            x = xNuevo;  // Actualizamos x para la siguiente iteración
            iteracion++;
        } while (error > tolerancia && iteracion <= maxIter);
    }
};
