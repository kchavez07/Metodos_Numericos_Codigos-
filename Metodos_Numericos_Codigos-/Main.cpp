#include "Prerequisites.h"
#include "Biseccion.h"
#include "Biseccion1.h"
#include "Biseccion2.h"
#include "Biseccion3.h"
#include "NewtonRaphson1.h"
#include "NewtonRaphson2.h"


int main() {
    cout << fixed << setprecision(6);

    // Biseccion 1
    cout << "Ejercicio 1: Resolver y = 10e^(-kt)cos(wt) - 4" << endl;
    Biseccion1 e1(0, 2, 0.0002, 100);
    e1.metodoBiseccion();
    cout << endl;

    // Biseccion 2
    cout << "Ejercicio 2: Resolver A = 20000(1 + i)^6 - 4000" << endl;
    Biseccion2 e2(0, 0.1, 0.00002, 100);
    e2.metodoBiseccion();
    cout << endl;

    // Biseccion 3
    cout << "Ejercicio 3: Resolver la velocidad de un paracaidista" << endl;
    Biseccion3 e3(50, 100, 0.0001, 100);
    e3.metodoBiseccion();
    cout << endl;

    // NewtonRaphson1
    cout << "Resolviendo: x^3 + 2x^2 + 10x - 20 = 0" << endl;
    double xInicial = 1.0;        // Valor inicial de x para el polinomio
    double toleranciaPolinomio = 0.001; // Tolerancia de error para el polinomio

    NewtonRaphsonPolinomio solverPolinomio(xInicial, toleranciaPolinomio);
    solverPolinomio.iterar();

    cout << "---------------------------------" << endl;
        
    // NewtonRahpson2
    cout << "Resolviendo: 70e^{-1.5t} + 20e^{-0.8t} = 10" << endl;
    double tInicial = 1.5;        // Valor inicial de t para la concentración de bacterias
    double toleranciaBacterias = 0.001; // Tolerancia de error para las bacterias

    // Instancia para la ecuación de concentración de bacterias
    NewtonRaphsonBacterias solverBacterias(tInicial, toleranciaBacterias);
    solverBacterias.iterar();

        return 0;
    }