#ifndef HELPERS_H
#define HELPERS_H

#include "Lector.h"
#include "Material.h"

extern Lector** lectores;
extern int cantLectores;

extern Material** materiales;
extern int cantMateriales;

void imprimirArregloMateriales();
void imprimirArregloLectores();
bool fechaEsMenorA(DtFecha* a, DtFecha* b);
DtFecha* validarFecha(int dia, int mes, int anio);

#endif // HELPERS_H
