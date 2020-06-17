#ifndef ICONTROLADORALTAPRODUCTO
#define ICONTROLADORALTAPRODUCTO
#include <iostream>
#include <string>
#include <list>
#include "DtProductoComun.h"
#include "DtProductoCantidad.h"
#include "DtProductoMenu.h"

using namespace std;

class IControladorAltaProducto{
        
    public:
        virtual list<DtProductoBase> listarProductos() =0;
        virtual list<DtProductoBase> listarProductosComunes() = 0;
        virtual list<DtProductoBase> listarProductosMenu() = 0;
        virtual void datosProductoComun(string, string, float) = 0;
        virtual void confirmarProductoComun() = 0;
        virtual void cancelarProductoComun() = 0;
        virtual void datosProductoMenu(string, string) = 0;
        virtual void agregarAlProductoMenu(DtProductoCantidad) = 0;
        virtual void confirmarProductoMenu() = 0;
        virtual void cancelarProductoMenu() = 0;
        virtual bool existeProducto(string) =0;
        virtual DtProducto detallesProducto(string) =0;
};

#endif
