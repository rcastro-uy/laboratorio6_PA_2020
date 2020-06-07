#ifndef DTPRODUCTO
#define DTPRODUCTO
#include "DtProductoBase.h"
#include <iostream>
using namespace std;

class DtProducto{
    private:
        float precio;
        int cantidad;
        
    public:
        DtProducto();
        DtProducto(float,int);
        void setPrecio(float);
        float getPrecio();
        void setCantidad(int);
        int getCantidad();
        ~DtProducto();
};
#endif