#ifndef LECTOR_H
#define LECTOR_H

#include <string>
#include "Prestamo.h"

#define MAX_PRESTAMOS 100

using namespace std;

class Lector {
    private:
        string ci;
        string nombre;
        DtFecha* fechaRegistro;

        Prestamo* prestamos[MAX_PRESTAMOS];
        int cantPrestamos;

    public:
        Lector(string ci, string nombre, DtFecha* fecha);
        virtual ~Lector();

        // Getters
        string getCI();
        string getNombre();
        DtFecha getFechaRegistro();

        void agregarPrestamo(Prestamo* p);

        Prestamo** getPrestamos(int& cantidad);
};

#endif // LECTOR_H
