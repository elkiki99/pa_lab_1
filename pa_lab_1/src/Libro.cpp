#include "Libro.h"
#include "DtLibro.h"

Libro::Libro(string codigo, string titulo, int anio, string autor, int paginas)
    : Material(codigo, titulo, anio), autor(autor), cantPaginas(paginas) {}

Libro::~Libro() {}

float Libro::calcularMulta(int diasAtraso) {
    return diasAtraso * 5;
}

DtMaterial* Libro::getDtMaterial() {
    return new DtLibro(codigo, titulo, anioPublicacion, autor, cantPaginas);
}
