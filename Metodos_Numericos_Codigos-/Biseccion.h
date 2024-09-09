#pragma once
#include "Prerequisites.h"

// Clase que implementa el Método de Bisección
class BisectionMethod {
private:
    double k, w, y;        // Valores de la función
    double t0, t1;         // Valores iniciales del intervalo
    double tolerance;      // Tolerancia para el error
    double prevMid;        // Almacena el valor anterior del punto medio

public:
    // Constructor para inicializar los valores
    BisectionMethod(double kVal, double wVal, double yVal, double tol)
        : k(kVal), w(wVal), y(yVal), tolerance(tol), t0(0), t1(5), prevMid(0) {}

    // Método para evaluar la función en el punto t
    double evaluate(double t) {
        return 10 * exp(-k * t) * cos(w * t) - y;
    }

    // Método que ejecuta el proceso de bisección
    void execute() {
        double tMid, fMid, f0, errorPercentual = 100;
        int iteration = 1;

        // Configurar la precisión para la salida de los valores
        cout << fixed << setprecision(4);

        // Encabezado de la tabla de resultados con formato
        cout << setw(10) << left << "Iteración"
            << setw(10) << "t0"
            << setw(10) << "t1"
            << setw(10) << "tm"
            << setw(15) << "f(tm)"
            << setw(15) << "Error porcentual (%)"
            << endl;

        // Ciclo que continúa hasta que el intervalo sea menor que la tolerancia
        while (abs(t1 - t0) > tolerance) {
            tMid = (t0 + t1) / 2;   // Calcula el punto medio
            fMid = evaluate(tMid);  // Calcula el valor de la función en el punto medio
            f0 = evaluate(t0);      // Calcula el valor de la función en t0

            // Calcular el error porcentual solo si no es la primera iteración
            if (iteration > 1) {
                errorPercentual = abs((tMid - prevMid) / tMid) * 100;
            }

            // Mostrar resultados de cada iteración con formato
            cout << setw(10) << left << iteration
                << setw(10) << t0
                << setw(10) << t1
                << setw(10) << tMid
                << setw(15) << fMid
                << setw(10) << setprecision(2) << errorPercentual << "%"
                << endl;

            // Verificar el signo para decidir el siguiente intervalo
            if (f0 * fMid < 0) {
                t1 = tMid;  // Si el producto es negativo, cambia el límite superior
            }
            else {
                t0 = tMid;  // Si es positivo, cambia el límite inferior
            }

            // Almacenar el valor actual del punto medio para la próxima iteración
            prevMid = tMid;
            iteration++; // Incrementa el número de iteración
        }

        // Resultado final después de alcanzar la tolerancia
        cout << "\nEl valor aproximado de t es: " << tMid << "\n";
    }
};