#include "Material.h"

Material::Material(string codigo, string titulo, int anio)
    : codigo(codigo), titulo(titulo), anioPublicacion(anio) {}

Material::~Material() {}

string Material::getCodigo() {
    return codigo;
}

string Material::getTitulo() {
    return titulo;
}

int Material::getAnio() {
    return anioPublicacion;
}
