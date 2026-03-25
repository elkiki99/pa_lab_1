#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "DtFecha.h"
#include "Material.h"

class Prestamo {
private:
    DtFecha* fecha;
    int diasPermitidos;
    Material* material;

public:
    Prestamo(DtFecha* fecha, int dias, Material* material);
    virtual ~Prestamo();

    DtFecha* getFecha();
    Material* getMaterial();
};

#endif
