#ifndef DTLIBRO_H
#define DTLIBRO_H

#include "DtMaterial.h"
#include <iostream>

class DtLibro : public DtMaterial {
    private:
        string autor;
        int paginas;

    public:
        DtLibro(string codigo, string titulo, int anio, string autor, int paginas);

        void imprimir() override;
};

#endif // DTLIBRO_H
