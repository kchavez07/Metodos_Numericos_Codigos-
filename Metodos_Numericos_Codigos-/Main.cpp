#include "Prerequisites.h"
#include "Biseccion.h"
#include "Biseccion1.h"
#include "Biseccion2.h"
#include "Biseccion3.h"
#include "NewtonRaphson1.h"
#include "NewtonRaphson2.h"
#include "NewtonRaphson3.h"
#include "NewtonRaphson4.h"
#include "NewtonRaphson5.h"
#include "NewtonRaphsonMaximo.h"
#include "NewtonRaphsonTanque.h"

// Declaraciones de funciones
void ejecutarTodosBiseccion();
void ejecutarTodosNewtonRaphson();

// Menú principal
int main() {
    cout << fixed << setprecision(4);  // Mostrar solo 5 dígitos significativos
    int opcion;
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Ejecutar ejercicios de Biseccion\n";
        cout << "2. Ejecutar ejercicios de Newton-Raphson\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            ejecutarTodosBiseccion();  // Llamada para ejecutar todos los ejercicios de Bisección
            break;
        case 2:
            ejecutarTodosNewtonRaphson();  // Llamada para ejecutar todos los ejercicios de Newton-Raphson
            break;
        case 3:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 3);

    return 0;
}

// Función para ejecutar todos los ejercicios de Bisección
void ejecutarTodosBiseccion() {
    cout << fixed << setprecision(5);

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
}

// Función para ejecutar todos los ejercicios de Newton-Raphson
void ejecutarTodosNewtonRaphson() {
    // No imprimimos encabezados generales aquí, lo dejamos a las clases.

    // NewtonRaphson1: x^3 + 2x^2 + 10x - 20 = 0
    cout << "\nResolviendo: x^3 + 2x^2 + 10x - 20 = 0\n";
    NewtonRaphson1 solver1(1.0, 0.001, 100);  // Valor inicial, tolerancia, iteraciones
    solver1.iterar();
    cout << "---------------------------------\n";

    // NewtonRaphson2: 70e^{-1.5t} + 20e^{-0.8t} = 10
    cout << "\nResolviendo: 70e^{-1.5t} + 20e^{-0.8t} = 10\n";
    NewtonRaphson2 solver2(1.5, 0.001, 100);  // Valor inicial, tolerancia, iteraciones
    solver2.iterar();
    cout << "---------------------------------\n";

    // NewtonRaphson3: x^3 - 2x - 2 = 0
    cout << "\nResolviendo: x^3 - 2x - 2 = 0\n";
    NewtonRaphson3 solver3(1.0, 0.001, 100);  // Valor inicial, tolerancia, iteraciones
    solver3.iterar();
    cout << "---------------------------------\n";

    // NewtonRaphson4: e^x + x - 7 = 0
    cout << "\nResolviendo: e^x + x - 7 = 0\n";
    NewtonRaphson4 solver4(1.0, 0.001, 100);  // Valor inicial, tolerancia, iteraciones
    solver4.iterar();
    cout << "---------------------------------\n";

    // NewtonRaphson5: ln(x) + x^2 - 3 = 0
    cout << "\nResolviendo: ln(x) + x^2 - 3 = 0\n";
    NewtonRaphson5 solver5(1.0, 0.001, 100);  // Valor inicial, tolerancia, iteraciones
    solver5.iterar();
    cout << "---------------------------------\n";

    // NewtonRaphsonMaximo: Encontrar el valor máximo de la función
    cout << "\nEncontrando el valor maximo de la funcion...\n";
    NewtonRaphsonMaximo solverMaximo(4.5, 0.001, 100);  // Valor inicial cercano a 4, tolerancia 0.001
    solverMaximo.iterar();
    cout << "---------------------------------\n";

    // NewtonRaphson para el tanque
    cout << "\nResolviendo para el volumen del tanque...\n";
    NewtonRaphsonTanque solverTanque(1.5, 0.001, 3);  // Valor inicial, tolerancia, iteraciones
    solverTanque.iterar();
    cout << "---------------------------------\n";
}
