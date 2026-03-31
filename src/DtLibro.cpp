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
    cout << "- Código: " << getCodigo() << endl;
    cout << "- Título: " << getTitulo() << endl;
    cout << "- Año de publicación: " << getAnioPublicacion() << endl;
    cout << "- Autor: " << getAutor() << endl;
    cout << "- Cantidad de páginas: " << getCantPaginas() << endl;
}
