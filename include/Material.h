#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "DtMaterial.h"

using namespace std;

class Material
{
    private:
        string codigo;
        string titulo;
        int anioPublicacion;
        string tipoMaterial = "";

    public:
        Material(string codigo, string titulo, int anioPublicacion);
        virtual ~Material();

        // Getters
        string getCodigo();
        string getTitulo();
        int getAnioPublicacion();
        string getTipoMaterial();

        // Setters
        void setCodigo(string codigo);
        void setTitulo(string titulo);
        void setAnioPublicacion(int anioPublicacion);
        void setTipoMaterial(string tipoMaterial);

        virtual float calcularMulta(int diasAtraso) = 0;
        virtual DtMaterial* getDtMaterial() = 0;
};

#endif
