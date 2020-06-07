#ifndef DTPRODUCTO
#define DTPRODUCTO
#include "DtProductoBase.h"
#include <iostream>
using namespace std;

class DtProducto{
    private:
        float precio;
        string cantidad;
        
    public:
        DtProducto();
        DtProducto(float,string);
        void setPrecio(float);
        float getPrecio();
        void setCantidad(string);
        string getCantidad();
        ~DtProducto();
};
#endif