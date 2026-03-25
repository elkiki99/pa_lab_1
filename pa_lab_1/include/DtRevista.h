#ifndef DTREVISTA_H
#define DTREVISTA_H

#include "DtMaterial.h"
#include <iostream>

class DtRevista : public DtMaterial {
    private:
        int numero;
        bool mensual;

    public:
        DtRevista(string codigo, string titulo, int anio, int numero, bool mensual);

        void imprimir() override;
};

#endif
