#ifndef LIBRO_H
#define LIBRO_H

#include "Material.h"

class DtMaterial;

class Libro : public Material
{
    public:
    Libro(string codigo, string titulo, int anio, string autor, int paginas);
    ~Libro();

    float calcularMulta(int diasAtraso) override;
    DtMaterial* getDtMaterial() override;

    protected:

    private:
        string autor;
        int cantPaginas;
};

#endif // LIBRO_H
