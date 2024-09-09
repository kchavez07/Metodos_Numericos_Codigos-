#pragma once
#include "Prerequisites.h"

// Clase que implementa el M�todo de Bisecci�n
class BisectionMethod {
private:
    double k, w, y;        // Valores de la funci�n
    double t0, t1;         // Valores iniciales del intervalo
    double tolerance;      // Tolerancia para el error
    double prevMid;        // Almacena el valor anterior del punto medio

public:
    // Constructor para inicializar los valores
    BisectionMethod(double kVal, double wVal, double yVal, double tol)
        : k(kVal), w(wVal), y(yVal), tolerance(tol), t0(0), t1(5), prevMid(0) {}

    // M�todo para evaluar la funci�n en el punto t
    double evaluate(double t) {
        return 10 * exp(-k * t) * cos(w * t) - y;
    }

    // M�todo que ejecuta el proceso de bisecci�n
    void execute() {
        double tMid, fMid, f0, errorPercentual = 100;
        int iteration = 1;

        // Configurar la precisi�n para la salida de los valores
        cout << fixed << setprecision(4);

        // Encabezado de la tabla de resultados con formato
        cout << setw(10) << left << "Iteraci�n"
            << setw(10) << "t0"
            << setw(10) << "t1"
            << setw(10) << "tm"
            << setw(15) << "f(tm)"
            << setw(15) << "Error porcentual (%)"
            << endl;

        // Ciclo que contin�a hasta que el intervalo sea menor que la tolerancia
        while (abs(t1 - t0) > tolerance) {
            tMid = (t0 + t1) / 2;   // Calcula el punto medio
            fMid = evaluate(tMid);  // Calcula el valor de la funci�n en el punto medio
            f0 = evaluate(t0);      // Calcula el valor de la funci�n en t0

            // Calcular el error porcentual solo si no es la primera iteraci�n
            if (iteration > 1) {
                errorPercentual = abs((tMid - prevMid) / tMid) * 100;
            }

            // Mostrar resultados de cada iteraci�n con formato
            cout << setw(10) << left << iteration
                << setw(10) << t0
                << setw(10) << t1
                << setw(10) << tMid
                << setw(15) << fMid
                << setw(10) << setprecision(2) << errorPercentual << "%"
                << endl;

            // Verificar el signo para decidir el siguiente intervalo
            if (f0 * fMid < 0) {
                t1 = tMid;  // Si el producto es negativo, cambia el l�mite superior
            }
            else {
                t0 = tMid;  // Si es positivo, cambia el l�mite inferior
            }

            // Almacenar el valor actual del punto medio para la pr�xima iteraci�n
            prevMid = tMid;
            iteration++; // Incrementa el n�mero de iteraci�n
        }

        // Resultado final despu�s de alcanzar la tolerancia
        cout << "\nEl valor aproximado de t es: " << tMid << "\n";
    }
};