#ifndef VENTALOCAL
#define VENTALOCAL
#include "Venta.h"
#include "DtProductoCantidad.h"
#include "DtProducto.h"
#include "DtProductoFactura.h"
#include <iostream>

using namespace std;

class VentaLocal: public Venta{
    public:
        VentaLocal();
        bool tieneElProducto (string);
        void agregarProducto (DtProductoCantidad);
        void incrementar (DtProductoCantidad);
        list<DtProducto*> listarProductos();
        string getNombreMozo();
        float getSubTotalVenta();
        list<DtProductoFactura*> getDtProductoFactura();
        ~VentaLocal();
};

#endif