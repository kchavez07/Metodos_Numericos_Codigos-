#pragma once
#include "Prerequisites.h"
#define BISECCION3_H

class Biseccion3 {
public:
    void biseccionMethod(std::function<double(double)> func, double t0, double t1, double tol, int maxIter);

    double funcion3(double x) {
        // Tu implementación aquí
        return x * x - 2;  // Ejemplo simple, puedes cambiarlo según tu necesidad
    }
};