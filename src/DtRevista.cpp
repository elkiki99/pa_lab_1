#include "DtRevista.h"
using namespace std;

DtRevista::DtRevista(string codigo, string titulo, int anioPublicacion, int numero, bool mensual)
    : DtMaterial(codigo, titulo, anioPublicacion) {
    this->numero = numero;
    this->mensual = mensual;
}

DtRevista::~DtRevista() {}

int DtRevista::getNumeroEdicion() {
    return numero;
}

bool DtRevista::getEsMensual() {
    return mensual;
}

void DtRevista::imprimir() {
    cout << "- Codigo: " << getCodigo() << endl;
    cout << "- Titulo: " << getTitulo() << endl;
    cout << "- Año: " << getAnioPublicacion() << endl;
    cout << "- Numero: " << getNumeroEdicion() << endl;
    cout << "- Es mensual: " << (getEsMensual() ? "Si" : "No") << endl;
}
