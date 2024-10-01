#pragma once
#include "Prerequisites.h"

// Función g(x) para el primer ejercicio
double g1(double x) {  // Cambié el nombre a g1 para diferenciarlo de otras posibles funciones g
    return exp(-x);  // Definición de g(x) = e^(-x)
}

// Método de Punto Fijo para el primer ejercicio
void puntoFijo1(double x0, double tolerancia, int maxIter) {
    double xAnterior = x0;
    double xNuevo;
    double error;
    int iteracion = 1;

    // Imprimir el encabezado de la tabla
    cout << setw(10) << "Iteracion" << setw(10) << "xi" << setw(15) << "g(xi)" << setw(15) << "Error" << endl;

    // Iterar hasta alcanzar la tolerancia o el máximo de iteraciones
    do {
        xNuevo = g1(xAnterior);  // Calcular g(xi) usando la función g1 definida arriba
        error = fabs((xNuevo - xAnterior) / xNuevo) * 100;  // Calcular el error porcentual
        cout << fixed << setprecision(4);
        cout << setw(10) << iteracion << setw(10) << xAnterior << setw(15) << xNuevo << setw(15) << error << "%" << endl;

        xAnterior = xNuevo;  // Actualizar el valor de x para la siguiente iteración
        iteracion++;
    } while (error > tolerancia && iteracion <= maxIter);

    cout << "Raiz aproximada: " << xNuevo << endl;
}

// Función para ejecutar el Método de Punto Fijo para el primer ejercicio
void ejecutarMetodoPuntoFijo1() {
    double x0 = 1.0;  // Valor inicial
    double tolerancia = 0.001;  // Tolerancia para el error
    int maxIter = 10;  // Limitar las iteraciones a 10

    cout << "\nMetodo de Punto Fijo para el primer ejercicio\n";
    puntoFijo1(x0, tolerancia, maxIter);  // Llamada a la función del método de Punto Fijo
}
