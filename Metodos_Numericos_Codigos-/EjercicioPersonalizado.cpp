// EjercicioPersonalizado.cpp
#include "EjercicioPersonalizado.h"  // Incluir el encabezado del ejercicio personalizado
#include "Biseccion1.h"
#include "MetodoPuntoFijo2.h"

// Implementación de la función que ejecuta el menú de ecuación personalizada
void ejecutarEjercicioPersonalizado() {
    int opcionMetodo;
    cout << "\n--- MENU EJERCICIO PERSONALIZADO ---\n";
    cout << "1. Resolver con Método de Bisección\n";
    cout << "2. Resolver con Método de Newton-Raphson\n";
    cout << "3. Resolver con Método de Punto Fijo\n";
    cout << "Opcion: ";
    cin >> opcionMetodo;

    switch (opcionMetodo) {
    case 1: {
        double a, b, tol;
        int maxIter;
        cout << "\nIngrese los valores iniciales para Bisección\n";
        cout << "Valor de a: ";
        cin >> a;
        cout << "Valor de b: ";
        cin >> b;
        cout << "Tolerancia: ";
        cin >> tol;
        cout << "Máximo de Iteraciones: ";
        cin >> maxIter;

        resolverConBiseccion(a, b, tol, maxIter);  // Llamada a la función para Bisección
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
        cout << "Máximo de Iteraciones: ";
        cin >> maxIter;

        resolverConNewtonRaphson(x0, tol, maxIter);  // Llamada a la función para Newton-Raphson
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
        cout << "Máximo de Iteraciones: ";
        cin >> maxIter;

        resolverConPuntoFijo(x0, tol, maxIter);  // Llamada a la función para Punto Fijo
        break;
    }
    default:
        cout << "Opción no válida.\n";
        break;
    }
}

// Implementación de la función para resolver con Bisección
void resolverConBiseccion(double a, double b, double tol, int maxIter) {
    // Creación de un objeto de la clase derivada Biseccion1
    Biseccion1 solver(a, b, tol, maxIter);
    solver.metodoBiseccion();
}

// Implementación de la función para resolver con Newton-Raphson
void resolverConNewtonRaphson(double x0, double tol, int maxIter) {
    // Creación de un objeto de la clase NewtonRaphson3
    NewtonRaphson3 solver(x0, tol, maxIter);
    solver.iterar();
}

// Implementación de la función para resolver con Punto Fijo
void resolverConPuntoFijo(double x0, double tol, int maxIter) {
    // Creación de un objeto de la clase MetodoPuntoFijo3
    puntoFijo(x0, tol, maxIter);  // Usar la función de Punto Fijo para resolver
}
