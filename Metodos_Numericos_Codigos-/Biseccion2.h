#pragma once
#include "Prerequisites.h"

// Definir la función f(i)
double funcion(double i) {
    double P = 20000.0;
    double n = 6.0;
    double A = 4000.0;
    return P * pow(1 + i / n, n) - A;
}

// Método de bisección
void Biseccion(double t0, double t1, double tol) {
    double tm, f_tm, error;
    int iteracion = 0;

    cout << setw(10) << "Iteracion"
        << setw(15) << "t0"
        << setw(15) << "t1"
        << setw(15) << "tm"
        << setw(20) << "f(tm)"
        << setw(20) << "Error porcentual (%)" << endl;

    do {
        tm = (t0 + t1) / 2;
        f_tm = funcion(tm);

        // Calcular el error porcentual
        error = fabs((t1 - t0) / tm) * 100;

        cout << setw(10) << iteracion
            << setw(15) << fixed << setprecision(6) << t0
            << setw(15) << t1
            << setw(15) << tm
            << setw(20) << f_tm
            << setw(15) << fixed << setprecision(2) << error << "%" << endl;

        if (funcion(t0) * f_tm < 0) {
            t1 = tm;
        }
        else {
            t0 = tm;
        }

        iteracion++;
    } while (error > tol);

    cout << "\nEl valor aproximado de i es: " << tm << endl;
}