#ifndef FACTURA
#define FACTURA
#include <iostream>
#include "DtFechaHora.h"
#include "DtProductoFactura.h"

using namespace std;

class Factura{
    private:
        float subTotal;
        list<DtProductoFactura*> productos;
        float descuento;
        int codVenta;
    public:
        Factura();
        Factura(float,list<DtProductoFactura*>,float,int);
        float getSubTotal();
        void setSubTotal(float);
        list<DtProductoFactura*> getProductos();
        void setProductos(DtProductoFactura*);
        float getDescuento();
        void setDescuento(float);
        int getCodVenta();
        void setCodVenta();
        DtFechaHora* getFechaHora();
        ~Factura();
};

#endif