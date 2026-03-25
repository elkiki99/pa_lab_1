#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
using namespace std;

class DtMaterial;

class Material
{
    public:
        Material(string codigo, string titulo, int anio);
        virtual ~Material();

        string getCodigo();
        string getTitulo();
        int getAnio();

        virtual float calcularMulta(int diasAtraso) = 0;
        virtual DtMaterial* getDtMaterial() = 0;

    protected:
        string codigo;
        string titulo;
        int anioPublicacion;
};

#endif // MATERIAL_H
