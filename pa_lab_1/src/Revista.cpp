#include "Revista.h"
#include "DtRevista.h"

Revista::Revista(string codigo, string titulo, int anio, int numero, bool mensual)
    : Material(codigo, titulo, anio), numeroEdicion(numero), esMensual(mensual) {}

Revista::~Revista() {}

float Revista::calcularMulta(int diasAtraso) {
    return diasAtraso * 2;
}

DtMaterial* Revista::getDtMaterial() {
    return new DtRevista(codigo, titulo, anioPublicacion, numeroEdicion, esMensual);
}
