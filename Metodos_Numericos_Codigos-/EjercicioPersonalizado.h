// EjercicioPersonalizado.h
#pragma once  // Evita la inclusión múltiple del archivo

#include "Biseccion.h"       // Incluir encabezados de los métodos
#include "NewtonRaphson3.h"
#include "MetodoPuntoFijo3.h"
#include "Prerequisites.h"

// Declaración de la función del menú de ecuación personalizada
void ejecutarEjercicioPersonalizado();  // Prototipo de la función para el menú del ejercicio personalizado

// Declaración de funciones para métodos específicos
void resolverConBiseccion(double a, double b, double tol, int maxIter);  // Resolver con Bisección
void resolverConNewtonRaphson(double x0, double tol, int maxIter);  // Resolver con Newton-Raphson
void resolverConPuntoFijo(double x0, double tol, int maxIter);  // Resolver con Punto Fijo
