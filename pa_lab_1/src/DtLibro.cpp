#include "DtLibro.h"

using namespace std;

DtLibro::DtLibro(string codigo, string titulo, int anio, string autor, int paginas)
    : DtMaterial(codigo, titulo, anio) {
    this->autor = autor;
    this->paginas = paginas;
}

void DtLibro::imprimir() {
    cout << "- Codigo: " << codigo << endl;
    cout << "- Titulo: " << titulo << endl;
    cout << "- Año: " << anio << endl;
    cout << "- Autor: " << autor << endl;
    cout << "- Paginas: " << paginas << endl;
}
