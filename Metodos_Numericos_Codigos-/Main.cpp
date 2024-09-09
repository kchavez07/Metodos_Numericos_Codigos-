#include "Biseccion.h"
#include "Biseccion2.h"

int main() {

    // Biseccion 1
    // Clase principal para ejecutar el programa
    {
        // Crear una instancia del método de la bisección con los parámetros dados
        double k = 0.5, w = 2, y = 4, tolerance = 0.0002;

        // Instancia de la clase BisectionMethod
        BisectionMethod method(k, w, y, tolerance);

        // Ejecutar el método de bisección
        method.execute();

        return 0;
    };

    // Biseccion 2
    {
        double t0 = 0.0;  // Limite inferior
        double t1 = 0.1;  // Limite superior
        double tolerancia = 0.0002;  // Tolerancia del 0.02%

        Biseccion(t0, t1, tolerancia);

        return 0;
    };

}