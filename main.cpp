#include <iostream>
#include <stdio.h>
#include <string>
#include "include/Libro.h"
#include "include/Lector.h"
#include "include/Revista.h"
#include "include/Prestamo.h"
#include "include/DtLibro.h"
#include "include/DtRevista.h"
#include "include/DtMaterial.h"

using namespace std;

const int MAX_MATERIALES = 100;
const int MAX_LECTORES = 100;

Lector** lectores = new Lector*[MAX_LECTORES];
int cantLectores = 0;

Material** materiales = new Material*[MAX_MATERIALES];
int cantMateriales = 0;

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

void imprimirArregloLectores()
{
    for(int i = 0; i < cantLectores; i++)
    {
        Lector* lector = lectores[i];

        cout << lector->getCI() << endl;
        cout << lector->getNombre() << endl;
        cout << "------------------\n";
    }
}

void imprimirPrestamos()
{
    for(int i = 0; i < cantLectores; i++)
    {
        Lector* lector = lectores[i];

        cout << "\nLector: " << lector->getCI() << " - " << lector->getNombre() << endl;

        int cant;
        cant = lector->getCantPrestamos();
        Prestamo** prestamos = lector->getPrestamos();

        if(cant == 0)
        {
            cout << "  (sin préstamos)\n";
        }

        for(int j = 0; j < cant; j++)
        {
            Prestamo* p = prestamos[j];

            Material* m = p->getMaterial(); // 👈 asumo que lo tenés

            cout << "  Material: " << m->getCodigo()
                 << " - " << m->getTitulo() << endl;

            cout << "  Dias permitidos: " << p->getDiasPermitidos() << endl;

            cout << "  ------------------\n";
        }
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

void registrarLector(string ci, string nombre, DtFecha* fechaRegistro)
{
    for(int i = 0; i < cantLectores; i++)
    {
        if(lectores[i]->getCI() == ci)
        {
            cout << "Ya existe un lector con esa CI\n";
            return;
        }
    }

    if(cantLectores == MAX_LECTORES)
    {
        cout << "Capacidad máxima alcanzada\n";
        return;
    }

    Lector* nuevoLector = new Lector(ci, nombre, fechaRegistro);

    lectores[cantLectores++] = nuevoLector;

    cout << "\nNuevo lector registrado correctamente!\n\n";
}

void agregarPrestamo(string ci, string codigoMaterial, DtFecha* fechaPrestamo, int diasPermitidos)
{
    bool existeLector = false;
    Lector* lector = nullptr;
    Material* material = nullptr;

    for(int i = 0; i < cantLectores; i++)
    {
        if(lectores[i]->getCI() == ci)
        {
            existeLector = true;
            lector = lectores[i];
            break;
        }
    }

    bool existeMaterial = false;

    for(int i = 0; i < cantMateriales; i++)
    {
        if(materiales[i]->getCodigo() == codigoMaterial)
        {
            existeMaterial = true;
            material = materiales[i];
            break;
        }
     }

     if(!existeLector && !existeMaterial)
        cout << "\nNo existe ni lector ni material para los datos ingresados";
     else if(!existeLector && existeMaterial)
        cout << "\nNo existe lector para el CI ingresado";
     else if(existeLector && !existeMaterial)
        cout << "\nNo existe material para el código ingresado";
     else
     {
         Prestamo* nuevoPrestamo = new Prestamo(fechaPrestamo, diasPermitidos, material);

         lector->agregarPrestamo(nuevoPrestamo);

         imprimirPrestamos();
     }
}

DtMaterial** obtenerMaterialesPrestados(string ci, int& cantMateriales)
{
    bool existeLector = false;
    Lector* lector = nullptr;

    for(int i = 0; i < cantLectores; i++)
    {
        if(lectores[i]->getCI() == ci)
        {
            existeLector = true;
            lector = lectores[i];
            break;
        }
    }

    if(!existeLector)
    {
        cout << "\nNo existe lector para el CI ingresado";
        cantMateriales = 0;
        return nullptr;
    }
    else
    {
        cantMateriales = lector->getCantPrestamos();
        Prestamo** prestamos_lector = lector->getPrestamos();
        DtMaterial** materiales_prestados = new DtMaterial*[cantMateriales];

        for(int i = 0; i < cantMateriales ; i++)
        {
            materiales_prestados[i] = prestamos_lector[i]->getMaterial()->getDtMaterial();
        }

        for(int i = 0; i < cantMateriales; i++)
        {
            cout << materiales_prestados[i]->getCodigo() << endl;
            cout << materiales_prestados[i]->getTitulo() << endl;
        }

        return materiales_prestados;
    }
}

float consultarMultaMaterial(string ci, string codigoMaterial, int diasAtraso)
{
    bool existeLector = false;
    Lector* lector = nullptr;
    Material* material = nullptr;

    for(int i = 0; i < cantLectores; i++)
    {
        if(lectores[i]->getCI() == ci)
        {
            existeLector = true;
            lector = lectores[i];
            break;
        }
    }

    bool existeMaterial = false;

    for(int i = 0; i < cantMateriales; i++)
    {
        if(materiales[i]->getCodigo() == codigoMaterial)
        {
            existeMaterial = true;
            material = materiales[i];
            break;
        }
     }

     if(!existeLector && !existeMaterial)
     {
        cout << "\nNo existe ni lector ni material para los datos ingresados";
        return -1;
     }
     else if(!existeLector && existeMaterial)
     {
        cout << "\nNo existe lector para el CI ingresado";
        return -1;
     }
     else if(existeLector && !existeMaterial)
     {
        cout << "\nNo existe material para el código ingresado";
        return -1;
     }
     else
     {
         int cant = 0;
         cant = lector->getCantPrestamos();
         bool existePrestamo = false;
         Prestamo** prestamos_lector = lector->getPrestamos();

         for(int i = 0; i < cant; i++)
         {
             if(prestamos_lector[i]->getMaterial()->getCodigo() == codigoMaterial)
             {
                 existePrestamo = true;
                 break;
             }
         }

         if(!existePrestamo)
         {
            cout << "\nNo existe un préstamo asociado a este material y este lector";
            return -1;
         }
         else
         {
             cout << "Multa: $" << material->calcularMulta(diasAtraso) << endl;
             return material->calcularMulta(diasAtraso);
         }
     }
}

DtMaterial** verPrestamosAntesDeFecha(string ci, DtFecha* fecha, int& cantPrestamos)
{
    bool existeLector = false;
    Lector* lector = nullptr;

    for(int i = 0; i < cantLectores; i++)
    {
        if(lectores[i]->getCI() == ci)
        {
            existeLector = true;
            lector = lectores[i];
            break;
        }
    }

    if(!existeLector)
    {
        cout << "\nNo existe lector para el CI ingresado";
        cantPrestamos = 0;
        return nullptr;
    }
    else
    {
        cantPrestamos = lector->getCantPrestamos();
        Prestamo** prestamos_lector = lector->getPrestamos();
        DtMaterial** materiales_antes_de_fecha = new DtMaterial*[cantPrestamos];
        int j = 0;

        for(int i = 0; i < cantPrestamos; i++)
            if(fechaEsMenorA(prestamos_lector[i]->getFecha(), fecha))
                materiales_antes_de_fecha[j++] = prestamos_lector[i]->getMaterial()->getDtMaterial();

        for(int i = 0; i < j; i++)
        {
            cout << materiales_antes_de_fecha[i]->getCodigo() << endl;
            cout << materiales_antes_de_fecha[i]->getTitulo() << endl;
        }

        return materiales_antes_de_fecha;
    }
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
                string ci;
                string nombre;
                int dia;
                int mes;
                int anio;

                cout << "\nIngrese CI: ";
                cin >> ci;

                cout << "\nIngrese un nombre: ";
                cin >> nombre;

                cout << "\nIngrese día de registro: ";
                cin >> dia;

                cout << "\nIngrese mes de registro: ";
                cin >> mes;

                cout << "\nIngrese año de registro: ";
                cin >> anio;

                DtFecha* dt_fecha = new DtFecha(dia, mes, anio);

                registrarLector(ci, nombre, dt_fecha);
                imprimirArregloLectores();

            }
            else if (numMenu == 2)
            {
                string ci;
                string codigoMaterial;
                int dia;
                int mes;
                int anio;
                int diasPermitidos;

                cout << "\nIngrese un CI: ";
                cin >> ci;

                cout << "\nIngrese un código existente de material: ";
                cin >> codigoMaterial;

                cout << "\nIngrese día del préstamo: ";
                cin >> dia;

                cout << "\nIngrese mes del préstamo: ";
                cin >> mes;

                cout << "\nIngrese año del préstamo: ";
                cin >> anio;

                cout << "\nDías permitidos: ";
                cin >> diasPermitidos;

                DtFecha* dt_fecha = new DtFecha(dia, mes, anio);

                agregarPrestamo(ci, codigoMaterial, dt_fecha, diasPermitidos);
            }
            else if (numMenu == 3)
            {
                string ci;

                cout << "\nIngrese una cédula válida: ";
                cin >> ci;

                obtenerMaterialesPrestados(ci, cantMateriales);
            }
            else if (numMenu == 4)
            {
                string ci;
                string codigoMaterial;
                int diasAtraso;

                cout << "\nIngrese una cédula válida: ";
                cin >> ci;

                cout << "\nIngrese un código de material válido: ";
                cin >> codigoMaterial;

                cout << "\nIngrese los días de atraso: ";
                cin >> diasAtraso;

                consultarMultaMaterial(ci, codigoMaterial, diasAtraso);
            }
            else if (numMenu == 5)
            {
                string ci;
                int dia;
                int mes;
                int anio;
                int cantPrestamos;

                cout << "\nIngrese CI: ";
                cin >> ci;

                cout << "\nIngrese día límite: ";
                cin >> dia;

                cout << "\nIngrese mes límite: ";
                cin >> mes;

                cout << "\nIngrese año límite: ";
                cin >> anio;

                DtFecha* dt_fecha = new DtFecha(dia, mes, anio);

                verPrestamosAntesDeFecha(ci, dt_fecha, cantPrestamos);
            }
            else if (numMenu == 6)
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
                DtMaterial* dt = nullptr;

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

                agregarMaterial(dt);
                imprimirArregloMateriales();
            }
        }

    } while(salir == false);

    return 0;
}
