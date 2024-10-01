#pragma once 
#include "Prerequisites.h"

// Funci�n g(x) para el tercer ejercicio
double g3(double x) {
    return sqrt((x + 2.5) / 1.8);
}

// M�todo de Punto Fijo para el tercer ejercicio
void puntoFijo3(double x0, double tolerancia, int maxIter) {
    double xAnterior = x0;
    double xNuevo;
    double error;
    int iteracion = 1;

    cout << setw(10) << "Iteracion" << setw(10) << "xi" << setw(15) << "g(xi)" << setw(15) << "Error" << endl;

    do {
        xNuevo = g3(xAnterior);  // Calcular g(xi)
        error = fabs((xNuevo - xAnterior) / xNuevo) * 100;  // Calcular el error
        cout << fixed << setprecision(4);
        cout << setw(10) << iteracion << setw(10) << xAnterior << setw(15) << xNuevo << setw(15) << error << "%" << endl;

        xAnterior = xNuevo;  // Actualizar x para la siguiente iteraci�n
        iteracion++;
    } while (error > tolerancia && iteracion <= maxIter);

    cout << "Raiz aproximada: " << xNuevo << endl;
}

// Funci�n para ejecutar el M�todo de Punto Fijo para el tercer ejercicio
void ejecutarMetodoPuntoFijo3() {
    double x0 = 5.0;  // Valor inicial para el tercer ejercicio
    double tolerancia = 0.001;  // Tolerancia para el error
    int maxIter = 10;  // Limitar las iteraciones a 10

    cout << "\nM�todo de Punto Fijo para el tercer ejercicio\n";
    puntoFijo3(x0, tolerancia, maxIter);  // Llamada a la funci�n del m�todo de Punto Fijo para el tercer ejercicio
}