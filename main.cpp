#include <iostream>
#include <stdio.h>
#include <string>
#include "include/Libro.h"
#include "include/Revista.h"

using namespace std;

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
            if(numMenu == 6)
            {
                cout << "\nIngrese un codigo: ";
                string codigo;
                cin >> codigo;

                cout << "\nIngrese un título: ";
                string titulo;
                cin >> titulo;

                cout << "\nIngrese un año de publicación: ";
                int anioPublicacion;
                cin >> anioPublicacion;

                string tipoMaterial = "";

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

                        Libro* libro = new Libro(codigo, titulo, anioPublicacion, autor, cantPaginas);

                        DtMaterial* dt_libro = libro->getDtMaterial();

                        cout << "" << endl;
                        dt_libro->imprimir();
                        cout << "" << endl;

                    } else if(tipoMaterial == "r") {

                        cout << "\nIngrese el número de edición: ";
                        int numeroEdicion;
                        cin >> numeroEdicion;

                        string esMensual = "";

                        do
                        {
                            cout << "\n¿Es mensual? (si/no): ";
                            cin >> esMensual;

                        } while(esMensual != "si" && esMensual != "no");

                        bool esMensualBool;

                        if(esMensual == "si")
                            esMensualBool = true;
                        else
                            esMensualBool = false;

                        Revista* revista = new Revista(codigo, titulo, anioPublicacion, numeroEdicion, esMensualBool);

                        DtMaterial* dt_revista = revista->getDtMaterial();

                        cout << "" << endl;
                        dt_revista->imprimir();
                        cout << "" << endl;
                    }

                } while (tipoMaterial != "l" && tipoMaterial != "r");
            }
        }

    } while(salir == false);

    return 0;
}
