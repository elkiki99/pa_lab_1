#include <iostream>
#include <stdio.h>
#include <string>
#include "include/Libro.h"
#include "include/Revista.h"
#include "include/DtLibro.h"
#include "include/DtRevista.h"
#include "include/DtMaterial.h"

using namespace std;

const int MAX_MATERIALES = 100;

Material** materiales = new Material*[MAX_MATERIALES];
int cantMateriales = 0;

// no se pide esta función, es para probar nomas que funca bien jaja
void imprimirArregloMateriales()
{
    for(int i = 0; i < cantMateriales; i++)
    {
        DtMaterial* dt = materiales[i]->getDtMaterial();

        dt->imprimir();
        cout << "------------------\n";

        delete dt;
    }
}

// agrega un nuevo material al array dinámico
void agregarMaterial(DtMaterial* dtMaterial)
{
    string codigo = dtMaterial->getCodigo();

    for(int i = 0; i < cantMateriales; i++)
    {
        if(materiales[i]->getCodigo() == codigo)
        {
            cout << "Ya existe un material con ese código\n";
            return;
        }
    }

    if(cantMateriales == MAX_MATERIALES)
    {
        cout << "Capacidad máxima alcanzada\n";
        return;
    }

    Material* nuevo = nullptr;

    if(DtLibro* l = dynamic_cast<DtLibro*>(dtMaterial))
    {
        nuevo = new Libro(
            l->getCodigo(),
            l->getTitulo(),
            l->getAnioPublicacion(),
            l->getAutor(),
            l->getCantPaginas()
        );
    }
    else if(DtRevista* r = dynamic_cast<DtRevista*>(dtMaterial))
    {
        nuevo = new Revista(
            r->getCodigo(),
            r->getTitulo(),
            r->getAnioPublicacion(),
            r->getNumeroEdicion(),
            r->getEsMensual()
        );
    }

    materiales[cantMateriales++] = nuevo;

    cout << "\nMaterial creado correctamente!\n\n";
}

int main()
{
    bool salir = false;
    int numMenu;

    cout << "\nBienvenido! Elija la opción: ";

    do
    {
        cout << "\n1) Registrar lector \n2) Agregar préstamo \n3) Obtener materiales prestados \n4) Consultar multa de material \n5) Ver préstamos antes de fecha \n6) Agregar material \n0) Salir \nOpción: ";
        cin >> numMenu;

        if(numMenu == 0)
            salir = true;
        else if (numMenu > 6)
        {
            cout << "\nNúmero inválido\nIntente nuevamente: \n" << endl;
        }
        else {
            if(numMenu == 1)
            {

            }
            if(numMenu == 6)
            {
                string codigo;
                string titulo;
                int anioPublicacion;

                cout << "\nIngrese un codigo: ";
                cin >> codigo;

                cout << "\nIngrese un título: ";
                cin >> titulo;

                cout << "\nIngrese un año de publicación: ";
                cin >> anioPublicacion;

                string tipoMaterial = "";
                DtMaterial* dt = nullptr; // puntero a null del data type material

                do
                {
                    cout << "\nLibro o Revista? (l/r): ";
                    cin >> tipoMaterial;

                    if(tipoMaterial == "l")
                    {
                        cout << "\nIngrese un autor: ";
                        string autor;
                        cin >> autor;

                        cout << "\nIngrese la cantidad de páginas: ";
                        int cantPaginas;
                        cin >> cantPaginas;

                        dt = new DtLibro(codigo, titulo, anioPublicacion, autor, cantPaginas);

                    } else if(tipoMaterial == "r") {

                        int numeroEdicion;
                        string esMensual = "";
                        bool esMensualBool;

                        cout << "\nIngrese el número de edición: ";
                        cin >> numeroEdicion;

                        do
                        {
                            cout << "\n¿Es mensual? (si/no): ";
                            cin >> esMensual;

                        } while(esMensual != "si" && esMensual != "no");

                        if(esMensual == "si")
                            esMensualBool = true;
                        else
                            esMensualBool = false;

                        dt = new DtRevista(codigo, titulo, anioPublicacion, numeroEdicion, esMensualBool);
                    }

                } while (tipoMaterial != "l" && tipoMaterial != "r");

                agregarMaterial(dt); // agregamos el material dinámicamente pasandole el datatype
                imprimirArregloMateriales();
            }
        }

    } while(salir == false);

    return 0;
}
