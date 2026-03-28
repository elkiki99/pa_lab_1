#ifndef DTFECHA_H
#define DTFECHA_H

class DtFecha {
    private:
        int dia;
        int mes;
        int anio;

    public:
        DtFecha(int dia, int mes, int anio);

        int getDia();
        int getMes();
        int getAnio();

        //bool esAnterior(DtFecha* otra);
};

#endif // DTFECHA_H
