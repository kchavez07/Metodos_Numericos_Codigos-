#pragma once
#include "Prerequisites.h"
#include "Biseccion.h"

#ifndef BISECCION1_H
#define BISECCION1_H

class Biseccion1 : public Biseccion {
public:
    Biseccion1(double x0, double x1, double tol, int maxIter) : Biseccion(x0, x1, tol, maxIter) {}

    double funcion(double t) override {
        double k = 0.5;
        double w = 2.0;
        return 10 * exp(-k * t) * cos(w * t) - 4;
    }
};

#endif
