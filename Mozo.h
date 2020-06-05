#ifndef MOZO
#define MOZO
#include <iostream>
#include "Mesa.h"
#include "VentaLocal.h"

using namespace std;

class Mozo{
    private:
        int idMozo;
        string nombre;
        list<Mesa*> mesas;
        string nombre;
    public:
        Mozo();
        Mozo(int,string,list<Mesa*>,string);
        int getIdMozo();
        void setIdMozo(int);
        string getNombre();
        void setNombre(string);
        list<Mesa*> getMesas();
        void setMesas(list<Mesa*>);
        string getNombre();
        void setNombre(string);
        list<int> mesasAsignadasSinVenta();
        void asignarMesas(list<int>,VentaLocal);
        ~Mozo();
};

#endif