#ifndef REVISTA_H
#define REVISTA_H

#include "Material.h"
#include "DtMaterial.h"

class Revista : public Material
{
    private:
        int numeroEdicion;
        bool esMensual;
        string tipoMaterial = "revista";

    public:
        Revista(string codigo, string titulo, int anio, int numero, bool mensual);
        virtual ~Revista();

        //Getters
        int getNumeroEdicion();
        bool getEsMensual();
        string getTipoMaterial();

        //Setters
        void setNumeroEdicion();
        void setEsMensual();
        void setTipoMaterial();

        float calcularMulta(int diasAtraso);
        DtMaterial* getDtMaterial();
};

#endif // REVISTA_H
