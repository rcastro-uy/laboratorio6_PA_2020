#ifndef VENTA
#define VENTA
#include "VentaProducto.h"
#include "Factura.h"
#include <iostream>

using namespace std;

class Venta{
    private:
        string codigo;
        VentaProducto* ventaProductos;
    public:
        Venta();
        Venta(string);
        string getcodigo();
        void setCodigo(string);
        list<VentaProducto*> getVentaProductos();
        void setVentaProductos (VentaProducto*);
        virtual eliminarProducto (string)=0;
        ~Venta();

};

#endif