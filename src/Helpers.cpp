#include "Helpers.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void imprimirArregloMateriales()
{
    for(int i = 0; i < cantMateriales; i++)
    {
        DtMaterial* dt = materiales[i]->getDtMaterial();

        dt->imprimir();

        delete dt;
    }
}

void imprimirArregloLectores()
{
    for(int i = 0; i < cantLectores; i++)
    {
        Lector* lector = lectores[i];

        cout << "\n- CI: " << lector->getCI() << endl;
        cout << "- Nombre: " << lector->getNombre() << endl;
        cout << "------------------";
    }
}

bool fechaEsMenorA(DtFecha* a, DtFecha* b)
{
    if(a->getAnio() < b->getAnio())
        return true;
    else if(a->getAnio() > b->getAnio())
        return false;

    if(a->getMes() < b->getMes())
        return true;
    else if(a->getMes() > b->getMes())
        return false;

    return a->getDia() < b->getDia();
}

DtFecha* validarFecha(int dia, int mes, int anio)
{
    if(anio < 1900 || anio > 2026)
        throw invalid_argument("Año inválido");

    if(mes < 1 || mes > 12)
        throw invalid_argument("Mes inválido");

    int diasMax = 31;

    switch(mes)
    {
        case 4: case 6: case 9: case 11:
            diasMax = 30;
            break;

        case 2:
        {
            bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
            // es bisiesto si es divisible entre 4 y no divisible entre 100, al menos que también sea divisible por 400

            if(esBisiesto)
                diasMax = 29;
            else
                diasMax = 28;

            break;
        }

        default:
            diasMax = 31;
    }

    if(dia < 1 || dia > diasMax)
        throw invalid_argument("Día inválido para el mes ingresado");

    return new DtFecha(dia, mes, anio);
}
