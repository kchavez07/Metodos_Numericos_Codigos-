#include "Biseccion.h"
#include "Biseccion2.h"
#include "Biseccion3.h"

// Declarar la funci�n func2 para el ejercicio 2
double func2(double i);

int main() {

    // Bisecci�n 1
    /*
    {
        // Clase principal para ejecutar el programa
        // Crear una instancia del m�todo de la bisecci�n con los par�metros dados
        double k = 0.5, w = 2, y = 4, tolerance = 0.0002;

        // Instancia de la clase BisectionMethod
        BisectionMethod method(k, w, y, tolerance);

        // Ejecutar el m�todo de bisecci�n
        method.execute();

        return 0;
    };
    */

    // Bisecci�n 2
    /*
    {
        Biseccion2 bis2;
        double t0 = 0.0;
        double t1 = 0.1;  // Intervalo inicial donde buscamos la ra�z
        double tol = 0.0002;  // Tolerancia
        int maxIter = 100;

        // Ejecutar el m�todo de bisecci�n para el ejercicio 2
        bis2.bisectionMethod(func2, t0, t1, tol, maxIter);

        return 0;
    }
    */

    //Bisecci�n 3
    {
        Biseccion3 bis3;
        double t0 = 0.0;   // Intervalo inicial donde buscamos la ra�z
        double t1 = 3.0;   // Cambia los valores de acuerdo al ejercicio 3
        double tol = 0.0002; // Tolerancia
        int maxIter = 100;

        // Usar una lambda para capturar la funci�n miembro funcion3
        auto func3 = [&bis3](double x) { return bis3.funcion3(x); };

        // Ejecutar el m�todo de bisecci�n para el ejercicio 3 usando la lambda
        bis3.biseccionMethod(func3, t0, t1, tol, maxIter);
    }
}

// Definir la funci�n func2 para el ejercicio 2
double func2(double i) {
    const double P = 20000;
    const double A = 4000;
    const int n = 6;

    // Ecuaci�n: A = P * (1 + i/n)^(n*t)
    return P * pow(1 + i / n, n) - A;
}
