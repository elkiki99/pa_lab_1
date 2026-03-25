#include "DtFecha.h"

DtFecha::DtFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DtFecha::getDia() { return dia; }
int DtFecha::getMes() { return mes; }
int DtFecha::getAnio() { return anio; }

bool DtFecha::esAnterior(DtFecha* otra) {
    if (anio < otra->anio) return true;
    if (anio == otra->anio && mes < otra->mes) return true;
    if (anio == otra->anio && mes == otra->mes && dia < otra->dia) return true;
    return false;
}
