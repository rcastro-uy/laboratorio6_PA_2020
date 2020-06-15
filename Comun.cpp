#include "Comun.h"

Comun::Comun(){}
Comun::Comun(string codigo,float precio,string desc):Producto(codigo,precio,desc){}
TipoProducto Comun::getTipoProducto(){
    return COMUN;
}
Comun::~Comun(){}