#include "DtLibro.h"

using namespace std;

DtLibro::DtLibro(string codigo, string titulo, int anioPublicacion, string autor, int paginas)
    : DtMaterial(codigo, titulo, anioPublicacion) {
    this->autor = autor;
    this->paginas = paginas;
}

DtLibro::~DtLibro() {}

string DtLibro::getAutor() {
    return autor;
}

int DtLibro::getCantPaginas() {
    return paginas;
}

void DtLibro::imprimir() {
    cout << "- Codigo: " << getCodigo() << endl;
    cout << "- Titulo: " << getTitulo() << endl;
    cout << "- Año: " << getAnioPublicacion() << endl;
    cout << "- Autor: " << getAutor() << endl;
    cout << "- Paginas: " << getCantPaginas() << endl;
}
