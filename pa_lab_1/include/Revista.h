#ifndef REVISTA_H
#define REVISTA_H

#include "Material.h"

class DtMaterial;

class Revista : public Material
{
    public:
        Revista();
        virtual ~Revista();

        Revista(string codigo, string titulo, int anio, int numero, bool mensual);

        float calcularMulta(int diasAtraso) override;
        DtMaterial* getDtMaterial() override;
    protected:

    private:
        int numeroEdicion;
        bool esMensual;
};

#endif // REVISTA_H
