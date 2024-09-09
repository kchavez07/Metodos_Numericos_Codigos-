#include "Biseccion.h"
#include "Biseccion2.h"

int main() {

    // Biseccion 1
    // Clase principal para ejecutar el programa
    {
        // Crear una instancia del m�todo de la bisecci�n con los par�metros dados
        double k = 0.5, w = 2, y = 4, tolerance = 0.0002;

        // Instancia de la clase BisectionMethod
        BisectionMethod method(k, w, y, tolerance);

        // Ejecutar el m�todo de bisecci�n
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