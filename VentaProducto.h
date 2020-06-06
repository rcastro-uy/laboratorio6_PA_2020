#ifndef VENTAPRODUCTO
#define VENTAPRODUCTO
#include "Producto.h"
#include "DtProducto.h"
#include "DtProductoFactura.h"

using namespace std;

class VentaProducto{
    private:
        int cantidad;
        Producto* producto;
    public:
        VentaProducto();
        VentaProducto(int, Producto*);
        int getCantidad();
        void setCantidad(int);
        Producto* getProducto();
        void setProducto(Producto*);
        string getCodigoProducto();
        void incrementarCantidad(int);
        int decrementarCantidad(int);
        DtProductoFactura getDtProductoFactura();
        float getPrecioProductoEnVenta ();
        DtProducto getDtProducto();
        ~VentaProducto();
};

#endif