#ifndef DTLIBRO_H
#define DTLIBRO_H

#include "DtMaterial.h"
#include <iostream>

class DtLibro : public DtMaterial {
    private:
        string autor;
        int paginas;

    public:
        DtLibro(string codigo, string titulo, int anioPublicacion, string autor, int paginas);
        virtual ~ DtLibro();

        //Getters
        string getAutor();
        int getCantPaginas();

        void imprimir() override;
};

#endif // DTLIBRO_H
