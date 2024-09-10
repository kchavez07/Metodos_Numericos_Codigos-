#include "Prerequisites.h"
#include "Biseccion.h"
#include "Biseccion1.h"
#include "Biseccion2.h"
#include "Biseccion3.h"


int main() {
    cout << fixed << setprecision(6);

    // Ejercicio 1
    cout << "Ejercicio 1: Resolver y = 10e^(-kt)cos(wt) - 4" << endl;
    Biseccion1 e1(0, 2, 0.0002, 100);
    e1.metodoBiseccion();
    cout << endl;

    // Ejercicio 2
    cout << "Ejercicio 2: Resolver A = 20000(1 + i)^6 - 4000" << endl;
    Biseccion2 e2(0, 0.1, 0.00002, 100);
    e2.metodoBiseccion();
    cout << endl;

    // Ejercicio 3
    cout << "Ejercicio 3: Resolver la velocidad de un paracaidista" << endl;
    Biseccion3 e3(50, 100, 0.0001, 100);
    e3.metodoBiseccion();
    cout << endl;

    return 0;
}