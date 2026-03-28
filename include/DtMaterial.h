#ifndef DTMATERIAL_H
#define DTMATERIAL_H

#include <string>
using namespace std;

class DtMaterial {
    private:
        string codigo;
        string titulo;
        int anioPublicacion;
        float multaBase;
        string tipoMaterial;

    public:
        DtMaterial(string codigo, string titulo, int anioPublicacion);
        virtual ~DtMaterial();

        //Getters
        string getCodigo();
        string getTitulo();
        int getAnioPublicacion();
        string getTipoMaterial();

        float getMultaBase();
        virtual void imprimir() = 0;
};

#endif
