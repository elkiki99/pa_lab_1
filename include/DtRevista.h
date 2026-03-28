#ifndef DTREVISTA_H
#define DTREVISTA_H

#include "DtMaterial.h"
#include <iostream>

class DtRevista : public DtMaterial {
    private:
        int numero;
        bool mensual;

    public:
        DtRevista(string codigo, string titulo, int anioPublicacion, int numero, bool mensual);
        virtual ~DtRevista();

        //Getters
        int getNumeroEdicion();
        bool getEsMensual();

        void imprimir() override;
};

#endif
