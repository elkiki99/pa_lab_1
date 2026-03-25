#include "Prestamo.h"

Prestamo::Prestamo(DtFecha* fecha, int dias, Material* material) {
    this->fecha = fecha;
    this->diasPermitidos = dias;
    this->material = material;
}

Prestamo::~Prestamo() {}

DtFecha* Prestamo::getFecha() {
    return fecha;
}

Material* Prestamo::getMaterial() {
    return material;
}
