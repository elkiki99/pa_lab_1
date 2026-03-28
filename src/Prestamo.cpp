#include "Prestamo.h"

Prestamo::Prestamo(DtFecha* fechaPrestamo, int dias, Material* material) {
    this->fechaPrestamo = fechaPrestamo;
    this->diasPermitidos = dias;
    this->material = material;
}

Prestamo::~Prestamo() {}

DtFecha* Prestamo::getFecha() {
    return fechaPrestamo;
}

int Prestamo::getDiasPermitidos() {
    return diasPermitidos;
}

Material* Prestamo::getMaterial() {
    return material;
}


