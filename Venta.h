#ifndef VENTA
#define VENTA
#include "VentaProducto.h"
#include "Factura.h"
#include <iostream>
#include <list>

using namespace std;

class Venta{
    private:
        string codigo;
        list<VentaProducto*> ventaProductos;
    public:
        Venta();
        Venta(string, list<VentaProducto*>);
        string getcodigo();
        void setCodigo(string);
        list<VentaProducto*> getVentaProductos();
        void setVentaProductos (VentaProducto*);
        virtual void eliminarProducto (string)=0;
        ~Venta();

};

#endif