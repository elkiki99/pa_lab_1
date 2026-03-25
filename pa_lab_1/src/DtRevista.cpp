#include "DtRevista.h"
using namespace std;

DtRevista::DtRevista(string codigo, string titulo, int anio, int numero, bool mensual)
    : DtMaterial(codigo, titulo, anio) {
    this->numero = numero;
    this->mensual = mensual;
}

void DtRevista::imprimir() {
    cout << "- Codigo: " << codigo << endl;
    cout << "- Titulo: " << titulo << endl;
    cout << "- Año: " << anio << endl;
    cout << "- Numero: " << numero << endl;
    cout << "- Es mensual: " << (mensual ? "Si" : "No") << endl;
}
