#ifndef ICONTROLADORQUITARPRODUCTO
#define ICONTROLADORQUITARPRODUCTO
#include <iostream>
#include <list>
#include "DtProductoCantidad.h"
#include "DtProducto.h"

using namespace std;

class IControladorQuitarProducto{

    public:
        virtual list<DtProducto> listarProductos(int) = 0;
        virtual void seleccionarProductoEliminar(DtProductoCantidad) = 0;
        virtual void cancelarQuitarProductoVenta() = 0;
        virtual void confirmarQuitarProductoVenta() = 0;
};

#endif