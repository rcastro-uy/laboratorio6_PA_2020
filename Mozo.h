#ifndef MOZO
#define MOZO
#include <iostream>
#include "Mesa.h"
#include "VentaLocal.h"
#include "Empleado.h"

using namespace std;

class VentaLocal;
class Mesa;

class Mozo:public Empleado{
    private:
        list<Mesa*> mesas;
    public:
        Mozo();
        Mozo(string,string,list<Mesa*>);
        list<Mesa*> getMesas();
        void setMesas(list<Mesa*>);
        list<int> mesasAsignadasSinVenta();
        void asignarMesas(list<int>, VentaLocal*);
        ~Mozo();
};

#endif