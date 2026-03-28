#include "Revista.h"
#include "DtRevista.h"

Revista::Revista(string codigo, string titulo, int anioPublicacion, int numeroEdicion, bool esMensual): Material(codigo, titulo, anioPublicacion)
{
    this->numeroEdicion = numeroEdicion;
    this->esMensual = esMensual;
}

Revista::~Revista() {}

bool Revista::getEsMensual() {
    return esMensual;
}

int Revista::getNumeroEdicion() {
    return numeroEdicion;
}

float Revista::calcularMulta(int diasAtraso) {
    return diasAtraso * 2;
}

DtMaterial* Revista::getDtMaterial() {
    return new DtRevista(getCodigo(), getTitulo(), getAnioPublicacion(), getNumeroEdicion(), getEsMensual());
}
