#ifndef MANEJADORVENTA
#define MANEJADORVENTA
#include "Venta.h"
#include <iostream>
#include <list>
#include <map>

using namespace std;

class ManejadorVenta{
    private:
        static ManejadorVenta* instancia;
        map<string,Venta*> ventas;
        ManejadorVenta();
    public:
        static ManejadorVenta* getInstancia();
        list<Venta*> getVentas();
        Venta* getVenta(string);
        void removerVenta(Venta*);
        void agregarVenta(Venta*);
        virtual ~ManejadorVenta();
};

#endif