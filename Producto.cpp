#include "Producto.h"

Producto::Producto(){}
Producto::Producto(string codigo,float precio,string desc,TipoProducto tipo){
    this->codigo = codigo;
    this->precio = precio;
    this->descripcion = desc;
    this->tipo = tipo;
}

void Producto::setCodigo(string codigo){
    this->codigo = codigo;
}
string Producto::getCodigo(){
    return this->codigo;
}
void Producto::setPrecio(float precio){
    this->precio =precio;
}
float Producto::getPrecio(){
    return this->precio;
}
void Producto::setDescripcion(string desc){
    this->descripcion = desc;
}
string Producto::getDescripcion(){
    return this->descripcion;
}
void Producto::setTipoProducto(TipoProducto tipo){ //tiene que pasar el para crearlo o se lo da? DUDA
    this->tipo =tipo;
}
TipoProducto Producto::getTipoProducto(){
    return this->tipo;
}
DtProductoBase Producto::getDtProductoBase(){
    DtProductoBase prod;
    prod.setCodigo(this->codigo);
    prod.setDescripcion(this->descripcion);
    return prod;
}
Producto::~Producto(){}