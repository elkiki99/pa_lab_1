#include "DtMaterial.h"

DtMaterial::DtMaterial(string codigo, string titulo, int anio) {
    this->codigo = codigo;
    this->titulo = titulo;
    this->anio = anio;
}

DtMaterial::~DtMaterial() {}

string DtMaterial::getCodigo() {
    return codigo;
}

string DtMaterial::getTitulo() {
    return titulo;
}

int DtMaterial::getAnio() {
    return anio;
}
