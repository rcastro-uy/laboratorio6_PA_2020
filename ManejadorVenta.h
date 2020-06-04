#ifndef MANEJADORVENTA
#define MANEJADORVENTA
#include "Venta.h"
#include <iostream>
#include <list>

using namespace std;

class ManejadorVenta{
    private:
        static ManejadorVenta* instancia;
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