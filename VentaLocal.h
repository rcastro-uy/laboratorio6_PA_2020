#ifndef VENTALOCAL
#define VENTALOCAL
#include "Venta.h"
#include "DtProductoCantidad.h"
#include "DtProducto.h"
#include "DtProductoFactura.h"
#include "ManejadorProducto.h"
#include "Mozo.h"
#include <iostream>

class Mesa;
class Mozo;
using namespace std;

class VentaLocal: public Venta{
    private:
        Mozo* mozo;
    public:
        VentaLocal();
        VentaLocal(string, Mozo*);
        bool tieneElProducto (string);
        void agregarProducto (DtProductoCantidad);
        void incrementar (DtProductoCantidad);
        list<DtProducto> listarProductos();
        string getNombreMozo();
        float getSubTotalVenta();
        list<DtProductoFactura> getDtProductoFactura();
        void eliminarProducto (string);
        void quitarProducto(DtProductoCantidad pc);
        ~VentaLocal();
};

#endif