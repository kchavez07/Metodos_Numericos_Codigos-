// EjercicioPersonalizado.h
#pragma once  // Evita la inclusi�n m�ltiple del archivo

#include "Biseccion.h"       // Incluir encabezados de los m�todos
#include "NewtonRaphson3.h"
#include "MetodoPuntoFijo3.h"
#include "Prerequisites.h"

// Declaraci�n de la funci�n del men� de ecuaci�n personalizada
void ejecutarEjercicioPersonalizado();  // Prototipo de la funci�n para el men� del ejercicio personalizado

// Declaraci�n de funciones para m�todos espec�ficos
void resolverConBiseccion(double a, double b, double tol, int maxIter);  // Resolver con Bisecci�n
void resolverConNewtonRaphson(double x0, double tol, int maxIter);  // Resolver con Newton-Raphson
void resolverConPuntoFijo(double x0, double tol, int maxIter);  // Resolver con Punto Fijo
