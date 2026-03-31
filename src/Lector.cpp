#include "Lector.h"

Lector::Lector(string ci, string nombre, DtFecha* fecha) {
    this->ci = ci;
    this->nombre = nombre;
    this->fechaRegistro = fecha;
    this->cantPrestamos = 0;
}

Lector::~Lector() {}

string Lector::getCI() {
    return ci;
}

string Lector::getNombre() {
    return nombre;
}

int Lector::getCantPrestamos() {
    return cantPrestamos;
}

void Lector::agregarPrestamo(Prestamo* p) {
    if (cantPrestamos < MAX_PRESTAMOS) {
        prestamos[cantPrestamos++] = p;
    }
}

Prestamo** Lector::getPrestamos() {
    return prestamos;
}
