#ifndef VENTAPRODUCTO
#define VENTAPRODUCTO
#include "Producto.h"

using namespace std;

class VentaProducto{
    private:
        int cantidad;
    public:
        VentaProducto();
        VentaProducto(int);
        int getCantidad();
        void setCantidad(int);
        string getCodigoProducto();
        void incrementarCantidad(int);
        int decrementarCantidad(int);
        DtProductoFactura* getDtProductoFactura();
        float getPrecioProductoEnVenta ();
        DtProducto* getDtProducto();
        ~VentaProducto();
};

#endif