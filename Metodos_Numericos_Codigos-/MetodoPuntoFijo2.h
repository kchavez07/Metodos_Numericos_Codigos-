#pragma once
#include "Prerequisites.h"

// Funci�n g(x) para el segundo ejercicio
double g(double x) {
    return pow((1 / (4 * log(3000 * sqrt(x)) - 0.4)), 2);
}

// M�todo de Punto Fijo
void puntoFijo(double x0, double tolerancia, int maxIter) {
    double xAnterior = x0;
    double xNuevo;
    double error;
    int iteracion = 1;

    cout << setw(10) << "Iteracion" << setw(10) << "xi" << setw(15) << "g(xi)" << setw(15) << "Error" << endl;

    do {
        xNuevo = g(xAnterior);  // Calcular g(xi)
        error = fabs((xNuevo - xAnterior) / xNuevo) * 100;  // Calcular el error
        cout << fixed << setprecision(4);
        cout << setw(10) << iteracion << setw(10) << xAnterior << setw(15) << xNuevo << setw(15) << error << "%" << endl;

        xAnterior = xNuevo;  // Actualizar x para la siguiente iteraci�n
        iteracion++;
    } while (error > tolerancia && iteracion <= maxIter);

    cout << "Ra�z aproximada: " << xNuevo << endl;
}

// Funci�n para ejecutar el M�todo de Punto Fijo para el segundo ejercicio
void ejecutarMetodoPuntoFijo2() {
    double x0 = 1.0;  // Valor inicial (puedes ajustar el valor inicial seg�n lo que desees)
    double tolerancia = 0.001;  // Tolerancia para el error
    int maxIter = 10;  // Limitar las iteraciones a 10

    cout << "\nM�todo de Punto Fijo para el segundo ejercicio\n";
    puntoFijo(x0, tolerancia, maxIter);  // Llamada a la funci�n del m�todo de Punto Fijo
}