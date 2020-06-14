#ifndef ICONTROLADORALTAPRODUCTO
#define ICONTROLADORALTAPRODUCTO
#include <iostream>
#include <string>
#include <list>
#include "DtProducto.h"
#include "DtProductoCantidad.h"
#include "DtProductoBase.h"

using namespace std;

class IControladorAltaProducto{
        
    public:
        virtual list<DtProductoBase> listarProductosComunes() = 0;
        virtual void datosProductoComun(string, string, float) = 0;
        virtual void confirmarProductoComun() = 0;
        virtual void cancelarProductoComun() = 0;
        virtual void datosProductoMenu(string, string) = 0;
        virtual void agregarAlProductoMenu(DtProductoCantidad) = 0;
        virtual void confirmarProductoMenu() = 0;
        virtual void cancelarProductoMenu() = 0;
};

#endif
