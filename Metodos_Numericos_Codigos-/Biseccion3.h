#pragma once
#include "Prerequisites.h"
#define BISECCION3_H

class Biseccion3 {
public:
    void biseccionMethod(std::function<double(double)> func, double t0, double t1, double tol, int maxIter);

    double funcion3(double x) {
        // Tu implementaci�n aqu�
        return x * x - 2;  // Ejemplo simple, puedes cambiarlo seg�n tu necesidad
    }
};