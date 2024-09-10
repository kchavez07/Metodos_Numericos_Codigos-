#include "Prerequisites.h"
#include "Biseccion.h"
#ifndef BISECCION2_H
#define BISECCION2_H

class Biseccion2 : public Biseccion {
public:
    Biseccion2(double x0, double x1, double tol, int maxIter) : Biseccion(x0, x1, tol, maxIter) {}

    double funcion(double i) override {
        double P = 20000;
        int n = 6;
        double A = 4000;
        return P * pow(1 + i, n) - A;
    }
};

#endif
