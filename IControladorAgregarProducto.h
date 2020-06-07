#ifndef ICONTROLADORAGREGARPRODUCTO
#define ICONTROLADORAGREGARPRODUCTO
#include <iostream>
#include <list>
#include "DtProductoCantidad.h"
#include "DtProductoBase.h"

using namespace std;

class IControladorAgregarProducto{

    public:
        virtual list<DtProductoBase> listarProductos() = 0;
        virtual void seleccionarProducto(DtProductoCantidad&) = 0;
        virtual void seleccionarMesa(int) = 0;
        virtual void confirmarAgregarProductoVenta() = 0;
        virtual void cancelarAgregarProductoVenta() = 0;
};

#endif