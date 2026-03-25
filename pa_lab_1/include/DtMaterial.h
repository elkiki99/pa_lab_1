#ifndef DTMATERIAL_H
#define DTMATERIAL_H

#include <string>
using namespace std;

class DtMaterial {
    protected:
        string codigo;
        string titulo;
        int anio;

    public:
        DtMaterial(string codigo, string titulo, int anio);
        virtual ~DtMaterial();

        string getCodigo();
        string getTitulo();
        int getAnio();

        virtual void imprimir() = 0;
};

#endif
