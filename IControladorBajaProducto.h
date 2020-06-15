#ifndef ICONTROLADORBAJAPRODUCTO
#define ICONTROLADORBAJAPRODUCTO
#include <iostream>
#include <string>
#include <list>
#include "DtProductoBase.h"

using namespace std;

class IControladorBajaProducto{
    
    public:
        virtual void eliminarProducto() = 0;
        virtual list<DtProductoBase> listarProductos() = 0;
        virtual void seleccionarProducto(string) = 0; 
        virtual void cancelarBajaProducto() = 0; 
        virtual bool existeProducto(string) =0;
};

#endif
