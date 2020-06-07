#include "DtProducto.h"

DtProducto::DtProducto(){}
DtProducto::DtProducto(float precio,string cant){
    this->precio = precio;
    this->cantidad = cant;
}
void DtProducto::setPrecio(float precio){
    this->precio = precio;
}
float DtProducto::getPrecio(){
    return this->precio;
}
void DtProducto::setCantidad(string cant){
    this->cantidad = cant;
}
string DtProducto::getCantidad(){
    return this->cantidad;
}
DtProducto::~DtProducto(){}