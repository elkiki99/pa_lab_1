#include "Libro.h"
#include "DtLibro.h"

Libro::Libro(string codigo, string titulo, int anioPublicacion, string autor, int cantPaginas): Material(codigo, titulo, anioPublicacion)
{
    this->autor = autor;
    this->cantPaginas = cantPaginas;
}

Libro::~Libro() {}

string Libro::getAutor() {
    return autor;
}

int Libro::getCantPaginas() {
    return cantPaginas;
}

float Libro::calcularMulta(int diasAtraso) {
    return diasAtraso * 5;
}

DtMaterial* Libro::getDtMaterial() {
    return new DtLibro(getCodigo(), getTitulo(), getAnioPublicacion(), getAutor(), getCantPaginas());
}
