#include "DtMaterial.h"

DtMaterial::DtMaterial(string codigo, string titulo, int anioPublicacion) {
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
}

DtMaterial::~DtMaterial() {}

string DtMaterial::getCodigo() {
    return codigo;
}

string DtMaterial::getTitulo() {
    return titulo;
}

int DtMaterial::getAnioPublicacion() {
    return anioPublicacion;
}
