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
#include "include/Helpers.h"

using namespace std;

const int MAX_MATERIALES = 100;
const int MAX_LECTORES = 100;

Lector** lectores = new Lector*[MAX_LECTORES];
int cantLectores = 0;

Material** materiales = new Material*[MAX_MATERIALES];
int cantMateriales = 0;


void registrarLector(string ci, string nombre, DtFecha* fechaRegistro)
{
    for(int i = 0; i < cantLectores; i++)
    {
        if(lectores[i]->getCI() == ci)
        {
            throw std::invalid_argument("Ya existe un lector con esa CI");
        }
    }

    if(cantLectores == MAX_LECTORES)
    {
        throw std::invalid_argument("Capacidad máxima alcanzada");
    }

    Lector* nuevoLector = new Lector(ci, nombre, fechaRegistro);
    lectores[cantLectores++] = nuevoLector;

    cout << "\nNuevo lector registrado correctamente!\n";
    imprimirArregloLectores();
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
        throw std::invalid_argument("No existe ni lector ni material para los datos ingresados");
     else if(!existeLector && existeMaterial)
        throw std::invalid_argument("No existe lector para el CI ingresado");
     else if(existeLector && !existeMaterial)
        throw std::invalid_argument("No existe material para el código ingresado");
     else
     {
         Prestamo* nuevoPrestamo = new Prestamo(fechaPrestamo, diasPermitidos, material);

         lector->agregarPrestamo(nuevoPrestamo);

         cout << "\nNuevo prestamo agregado correctamente!";
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
        throw std::invalid_argument("No existe lector para el CI ingresado");
        cantMateriales = 0;
        return nullptr;
    }
    else
    {
        cantMateriales = lector->getCantPrestamos();
        Prestamo** prestamos_lector = lector->getPrestamos();
        DtMaterial** materiales_prestados = new DtMaterial*[cantMateriales];

        // impresión
        cout << "\n- CI: " << lector->getCI() << " - Nombre: " << lector->getNombre() << endl;

        if(cantMateriales == 0)
        {
            cout << "- Sin préstamos\n";
        }

        for(int i = 0; i < cantMateriales ; i++)
        {
            materiales_prestados[i] = prestamos_lector[i]->getMaterial()->getDtMaterial();
            cout << "- Código: " << materiales_prestados[i]->getCodigo() << endl;
            cout << "- Título: " << materiales_prestados[i]->getTitulo() << endl;
            cout << "------------------";
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
        throw std::invalid_argument("No existe ni lector ni material para los datos ingresados");
        return -1;
     }
     else if(!existeLector && existeMaterial)
     {
        throw std::invalid_argument("No existe lector para el CI ingresado");
        return -1;
     }
     else if(existeLector && !existeMaterial)
     {
        throw std::invalid_argument("No existe material para el código ingresado");
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
            throw std::invalid_argument("No existe un préstamo asociado a este material y este lector");
            return -1;
         }
         else
         {
             cout << "\n- Multa: $" << material->calcularMulta(diasAtraso) << endl;
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
        throw std::invalid_argument("No existe lector para el CI ingresado");
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

        // impresión
        cout << "- Lector: " << lector->getCI() << " - " << lector->getNombre() << endl;

        if(j == 0)
        {
            cout << "\t(sin préstamos)";
        }

        for(int i = 0; i < j; i++)
        {
            cout << "\tCódigo: " << materiales_antes_de_fecha[i]->getCodigo() << endl;
            cout << "\tTítulo: " << materiales_antes_de_fecha[i]->getTitulo() << endl;
            cout << "\t------------------";
        }

        return materiales_antes_de_fecha;
    }
}

void agregarMaterial(DtMaterial* dtMaterial)
{
    string codigo = dtMaterial->getCodigo();

    for(int i = 0; i < cantMateriales; i++)
    {
        if(materiales[i]->getCodigo() == codigo)
        {
            throw std::invalid_argument("Ya existe un material con ese código");
            return;
        }
    }

    if(cantMateriales == MAX_MATERIALES)
    {
        throw std::invalid_argument("Capacidad máxima alcanzada");
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

    cout << "\nNuevo material creado correctamente!\n";
    imprimirArregloMateriales();
}

int main()
{
    bool salir = false;
    int numMenu;

    cout << "\nBienvenido! Elija la opción: ";

    do
    {
        cout << "\n\n1) Registrar lector \n2) Agregar préstamo \n3) Obtener materiales prestados \n4) Consultar multa de material \n5) Ver préstamos antes de fecha \n6) Agregar material \n0) Salir \n\nOpción: ";
        cin >> numMenu;

        if(numMenu == 0)
            salir = true;
        else if (numMenu > 6)
        {
            cout << "\nNúmero inválido, intente nuevamente";
        }
        else
        {
            if(numMenu == 1)
            {
                string ci;
                string nombre;
                int dia;
                int mes;
                int anio;

                cout << "\nIngrese CI: ";
                cin.ignore(); // Limpia el buffer
                getline(cin, ci); // permite espacios para strings

                cout << "\nIngrese un nombre: ";
                getline(cin, nombre);

                cout << "\nIngrese día de registro: ";
                cin >> dia;

                cout << "\nIngrese mes de registro: ";
                cin >> mes;

                cout << "\nIngrese año de registro: ";
                cin >> anio;

                try
                {
                    DtFecha* dt_fecha = validarFecha(dia, mes, anio);
                    registrarLector(ci, nombre, dt_fecha);
                }
                catch(const std::invalid_argument& e)
                {
                    cout << "\nError: " << e.what() << endl;
                }
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
                cin.ignore();
                getline(cin, ci);

                cout << "\nIngrese un código existente de material: ";
                getline(cin, codigoMaterial);

                cout << "\nIngrese día del préstamo: ";
                cin >> dia;

                cout << "\nIngrese mes del préstamo: ";
                cin >> mes;

                cout << "\nIngrese año del préstamo: ";
                cin >> anio;

                cout << "\nDías permitidos: ";
                cin >> diasPermitidos;

                try
                {
                    DtFecha* dt_fecha = validarFecha(dia, mes, anio);
                    agregarPrestamo(ci, codigoMaterial, dt_fecha, diasPermitidos);
                }
                catch(const std::invalid_argument& e)
                {
                    cout << "\nError: " << e.what() << endl;
                }
            }
            else if (numMenu == 3)
            {
                string ci;
                int cantPrestamos;

                cout << "\nIngrese una cédula válida: ";
                cin.ignore(); // Limpia el buffer
                getline(cin, ci);

                try
                {
                    obtenerMaterialesPrestados(ci, cantPrestamos);
                }
                catch(const std::invalid_argument& e)
                {
                    cout << "\nError: " << e.what() << endl;
                }
            }
            else if (numMenu == 4)
            {
                string ci;
                string codigoMaterial;
                int diasAtraso;

                cout << "\nIngrese una cédula válida: ";
                cin.ignore(); // Limpia el buffer
                getline(cin, ci);

                cout << "\nIngrese un código de material válido: ";
                getline(cin, codigoMaterial);

                cout << "\nIngrese los días de atraso: ";
                cin >> diasAtraso;

                try
                {
                    consultarMultaMaterial(ci, codigoMaterial, diasAtraso);
                }
                catch(const std::invalid_argument& e)
                {
                    cout << "\nError: " << e.what() << endl;
                }
            }
            else if (numMenu == 5)
            {
                string ci;
                int dia;
                int mes;
                int anio;
                int cantPrestamos;

                cout << "\nIngrese CI: ";
                cin.ignore(); // Limpia el buffer
                getline(cin, ci);

                cout << "\nIngrese día límite: ";
                cin >> dia;

                cout << "\nIngrese mes límite: ";
                cin >> mes;

                cout << "\nIngrese año límite: ";
                cin >> anio;

                try
                {
                    DtFecha* dt_fecha = validarFecha(dia, mes, anio);
                    verPrestamosAntesDeFecha(ci, dt_fecha, cantPrestamos);
                }
                catch(const std::invalid_argument& e)
                {
                    cout << "\nError: " << e.what() << endl;
                }
            }
            else if (numMenu == 6)
            {
                string codigo;
                string titulo;
                int anioPublicacion;

                cout << "\nIngrese un codigo: ";
                cin.ignore(); // Limpia el buffer
                getline(cin, codigo);

                cout << "\nIngrese un título: ";
                getline(cin, titulo);

                cout << "\nIngrese un año de publicación: ";
                cin >> anioPublicacion;

                string tipoMaterial = "";
                DtMaterial* dt = nullptr;

                do
                {
                    cout << "\nLibro o Revista? (l/r): ";
                    cin >> tipoMaterial;

                    if(tipoMaterial == "l" || tipoMaterial == "L")
                    {
                        string autor;
                        int cantPaginas;

                        cout << "\nIngrese un autor: ";
                        cin.ignore(); // Limpia el buffer
                        getline(cin, autor);

                        cout << "\nIngrese la cantidad de páginas: ";
                        cin >> cantPaginas;

                        dt = new DtLibro(codigo, titulo, anioPublicacion, autor, cantPaginas);

                    } else if(tipoMaterial == "r" || tipoMaterial == "R") {

                        int numeroEdicion;
                        string esMensual = "";

                        bool esMensualBool;

                        cout << "\nIngrese el número de edición: ";
                        cin >> numeroEdicion;

                        do
                        {
                            cout << "\n¿Es mensual? (si/no): ";
                            cin >> esMensual;

                        do
                        {
                            cout << "\n¿Es mensual? (si/no): ";
                            cin >> esMensual;

                        } while(esMensual != "si" && esMensual != "SI" && esMensual != "no" && esMensual != "NO");

                        if(esMensual == "si" || esMensual == "SI")
                            esMensualBool = true;
                        else
                            esMensualBool = false;

                        dt = new DtRevista(codigo, titulo, anioPublicacion, numeroEdicion, esMensualBool);
                    }
                } while (tipoMaterial != "l" && tipoMaterial != "L" && tipoMaterial != "r" && tipoMaterial != "R");

                try
                {
                    agregarMaterial(dt);
                }
                catch(const std::invalid_argument& e)
                {
                    cout << "\nError: " << e.what() << endl;
                }
            }
        }

    } while(salir == false);

    return 0;
}
