#ifndef LIBRO_H
#define LIBRO_H

#include "Material.h"
#include "DtMaterial.h"

class Libro : public Material
{
    private:
        string autor;
        int cantPaginas;
        string tipoMaterial = "libro";

    public:
        Libro(string codigo, string titulo, int anioPublicacion, string autor, int paginas);
        virtual ~Libro();

        //Getters
        string getAutor();
        int getCantPaginas();
        string getTipoMaterial();

        //Setters
        void setAutor();
        void setCantPaginas();
        void setTipoMaterial();

        float calcularMulta(int diasAtraso);
        DtMaterial* getDtMaterial();

};

#endif // LIBRO_H
