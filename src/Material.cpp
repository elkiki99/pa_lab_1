#include "Material.h"

Material::Material(string codigo, string titulo, int anioPublicacion) {
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
}

Material::~Material() {}

string Material::getCodigo() {
    return codigo;
}

string Material::getTitulo() {
    return titulo;
}

int Material::getAnioPublicacion() {
    return anioPublicacion;
}

string Material::getTipoMaterial() {
    return tipoMaterial;
}

void Material::setCodigo(string codigo) {
    this->codigo = codigo;
}

void Material::setTitulo(string titulo) {
    this->titulo = titulo;
}

void Material::setAnioPublicacion(int anioPublicacion) {
    this->anioPublicacion = anioPublicacion;
}

void Material::setTipoMaterial(string tipoMaterial) {
    this->tipoMaterial = tipoMaterial;
}


