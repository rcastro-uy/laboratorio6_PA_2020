#include "DtProducto.h"

DtProducto::DtProducto(){}
DtProducto::DtProducto(float precio,int cant){
    this->precio = precio;
    this->cantidad = cant;
}
void DtProducto::setPrecio(float precio){
    this->precio = precio;
}
float DtProducto::getPrecio(){
    return this->precio;
}
void DtProducto::setCantidad(int cant){
    this->cantidad = cant;
}
int DtProducto::getCantidad(){
    return this->cantidad;
}
DtProducto::~DtProducto(){}