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
    cout << "- Código: " << getCodigo() << endl;
    cout << "- Título: " << getTitulo() << endl;
    cout << "- Año de publicación: " << getAnioPublicacion() << endl;
    cout << "- Número de edición: " << getNumeroEdicion() << endl;
    cout << "- Es mensual: " << (getEsMensual() ? "Si" : "No") << endl;
}
