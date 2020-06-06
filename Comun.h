#ifndef COMUN
#define COMUN
#include <iostream>
#include "Producto.h"
using namespace std;

class Comun: public Producto{
    public:
        Comun();
        Comun(string,float,string);
        TipoProducto getTipoProducto();
        ~Comun();
};
#endif