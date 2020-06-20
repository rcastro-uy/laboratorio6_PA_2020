#ifndef FACTURA
#define FACTURA
#include <iostream>
#include "DtFechaHora.h"
#include "DtProductoFactura.h"
#include <list>

using namespace std;

class Factura{
    private:
        float subTotal;
        list<DtProductoFactura> productos;
        float descuento;
        string codVenta;
        DtFechaHora fecha;
    public:
        Factura();
        Factura(float,list<DtProductoFactura>,float,string);
        float getSubTotal();
        void setSubTotal(float);
        list<DtProductoFactura> getProductos();
        void setProductos(list<DtProductoFactura>);
        float getDescuento();
        void setDescuento(float);
        string getCodVenta();
        void setCodVenta(string);
        DtFechaHora getFechaHora();
        void setFechaHora(DtFechaHora);
        ~Factura();
};

#endif