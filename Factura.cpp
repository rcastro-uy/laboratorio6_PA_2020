#include "Factura.h"

Factura::Factura(){}
Factura::Factura(float subTotal,list<DtProductoFactura*> productos,float descuento,int codVenta){
    this->subTotal=subTotal;
    this->productos=productos;
    this->descuento=descuento;
    this->codVenta=codVenta;
}
float Factura::getSubTotal(){
    return this->subTotal;
}
void Factura::setSubTotal(float st){
    this->subTotal=st;
}
list<DtProductoFactura*> Factura::getProductos(){
    return this->productos;
}
void Factura::setProductos(list<DtProductoFactura*> prods){
    this->productos=prods;
}
float Factura::getDescuento(){
    return this->descuento;
}
void Factura::setDescuento(float d){
    this->descuento=d;
}
int Factura::getCodVenta(){
    return this->codVenta;
}
void Factura::setCodVenta(int cv){
    this->codVenta=cv;
}
DtFechaHora* Factura::getFechaHora(){
    //pendiente - rcastro
}
void Factura::setFechaHora(DtFechaHora*){
    //pendiente - rcastro 
}
Factura::~Factura(){}