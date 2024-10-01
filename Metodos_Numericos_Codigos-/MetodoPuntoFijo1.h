#pragma once
#include "Prerequisites.h"

// Funci�n g(x) para el primer ejercicio
double g1(double x) {  // Cambi� el nombre a g1 para diferenciarlo de otras posibles funciones g
    return exp(-x);  // Definici�n de g(x) = e^(-x)
}

// M�todo de Punto Fijo para el primer ejercicio
void puntoFijo1(double x0, double tolerancia, int maxIter) {
    double xAnterior = x0;
    double xNuevo;
    double error;
    int iteracion = 1;

    // Imprimir el encabezado de la tabla
    cout << setw(10) << "Iteracion" << setw(10) << "xi" << setw(15) << "g(xi)" << setw(15) << "Error" << endl;

    // Iterar hasta alcanzar la tolerancia o el m�ximo de iteraciones
    do {
        xNuevo = g1(xAnterior);  // Calcular g(xi) usando la funci�n g1 definida arriba
        error = fabs((xNuevo - xAnterior) / xNuevo) * 100;  // Calcular el error porcentual
        cout << fixed << setprecision(4);
        cout << setw(10) << iteracion << setw(10) << xAnterior << setw(15) << xNuevo << setw(15) << error << "%" << endl;

        xAnterior = xNuevo;  // Actualizar el valor de x para la siguiente iteraci�n
        iteracion++;
    } while (error > tolerancia && iteracion <= maxIter);

    cout << "Raiz aproximada: " << xNuevo << endl;
}

// Funci�n para ejecutar el M�todo de Punto Fijo para el primer ejercicio
void ejecutarMetodoPuntoFijo1() {
    double x0 = 1.0;  // Valor inicial
    double tolerancia = 0.001;  // Tolerancia para el error
    int maxIter = 10;  // Limitar las iteraciones a 10

    cout << "\nMetodo de Punto Fijo para el primer ejercicio\n";
    puntoFijo1(x0, tolerancia, maxIter);  // Llamada a la funci�n del m�todo de Punto Fijo
}
