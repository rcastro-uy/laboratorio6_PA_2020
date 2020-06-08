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
        list<DtProductoFactura*> productos;
        float descuento;
        int codVenta;
        DtFechaHora* fecha;
    public:
        Factura();
        Factura(float,list<DtProductoFactura*>,float,int);
        float getSubTotal();
        void setSubTotal(float);
        list<DtProductoFactura*> getProductos();
        void setProductos(list<DtProductoFactura*>);
        float getDescuento();
        void setDescuento(float);
        int getCodVenta();
        void setCodVenta(int);
        DtFechaHora* getFechaHora();
        void setFechaHora(DtFechaHora*);
        ~Factura();
};

#endif