#include "DtFecha.h"

DtFecha::DtFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DtFecha::getDia() { return dia; }
int DtFecha::getMes() { return mes; }
int DtFecha::getAnio() { return anio; }
