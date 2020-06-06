#ifndef DTPRODUCTO
#define DTPRODUCTO
#include <iostream>
using namespace std;

class DtProducto{
    private:
        float precio;
        string cantidad;
    public:
        DtProducto();
        DtProducto(float,string);
        setPrecio(float);
        float getPrecio();
        setCantidad(string);
        string getCantidad();
        ~DtProducto();
}
#endif