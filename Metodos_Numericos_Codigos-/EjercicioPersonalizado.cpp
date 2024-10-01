// EjercicioPersonalizado.cpp
#include "EjercicioPersonalizado.h"  // Incluir el encabezado del ejercicio personalizado
#include "Biseccion1.h"
#include "MetodoPuntoFijo2.h"

// Implementaci�n de la funci�n que ejecuta el men� de ecuaci�n personalizada
void ejecutarEjercicioPersonalizado() {
    int opcionMetodo;
    cout << "\n--- MENU EJERCICIO PERSONALIZADO ---\n";
    cout << "1. Resolver con M�todo de Bisecci�n\n";
    cout << "2. Resolver con M�todo de Newton-Raphson\n";
    cout << "3. Resolver con M�todo de Punto Fijo\n";
    cout << "Opcion: ";
    cin >> opcionMetodo;

    switch (opcionMetodo) {
    case 1: {
        double a, b, tol;
        int maxIter;
        cout << "\nIngrese los valores iniciales para Bisecci�n\n";
        cout << "Valor de a: ";
        cin >> a;
        cout << "Valor de b: ";
        cin >> b;
        cout << "Tolerancia: ";
        cin >> tol;
        cout << "M�ximo de Iteraciones: ";
        cin >> maxIter;

        resolverConBiseccion(a, b, tol, maxIter);  // Llamada a la funci�n para Bisecci�n
        break;
    }
    case 2: {
        double x0, tol;
        int maxIter;
        cout << "\nIngrese el valor inicial para Newton-Raphson\n";
        cout << "Valor de x0: ";
        cin >> x0;
        cout << "Tolerancia: ";
        cin >> tol;
        cout << "M�ximo de Iteraciones: ";
        cin >> maxIter;

        resolverConNewtonRaphson(x0, tol, maxIter);  // Llamada a la funci�n para Newton-Raphson
        break;
    }
    case 3: {
        double x0, tol;
        int maxIter;
        cout << "\nIngrese el valor inicial para Punto Fijo\n";
        cout << "Valor de x0: ";
        cin >> x0;
        cout << "Tolerancia: ";
        cin >> tol;
        cout << "M�ximo de Iteraciones: ";
        cin >> maxIter;

        resolverConPuntoFijo(x0, tol, maxIter);  // Llamada a la funci�n para Punto Fijo
        break;
    }
    default:
        cout << "Opci�n no v�lida.\n";
        break;
    }
}

// Implementaci�n de la funci�n para resolver con Bisecci�n
void resolverConBiseccion(double a, double b, double tol, int maxIter) {
    // Creaci�n de un objeto de la clase derivada Biseccion1
    Biseccion1 solver(a, b, tol, maxIter);
    solver.metodoBiseccion();
}

// Implementaci�n de la funci�n para resolver con Newton-Raphson
void resolverConNewtonRaphson(double x0, double tol, int maxIter) {
    // Creaci�n de un objeto de la clase NewtonRaphson3
    NewtonRaphson3 solver(x0, tol, maxIter);
    solver.iterar();
}

// Implementaci�n de la funci�n para resolver con Punto Fijo
void resolverConPuntoFijo(double x0, double tol, int maxIter) {
    // Creaci�n de un objeto de la clase MetodoPuntoFijo3
    puntoFijo(x0, tol, maxIter);  // Usar la funci�n de Punto Fijo para resolver
}
