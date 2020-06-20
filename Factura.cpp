#include "Factura.h"

Factura::Factura(){}
Factura::Factura(float subTotal,list<DtProductoFactura> productos,float descuento,string codVenta){
    this->subTotal=subTotal;
    this->productos=productos;
    this->descuento=descuento;
    this->codVenta=codVenta;
    DtFechaHora fechita = DtFechaHora(21,6,2020,23,59,59);
    this->fecha=fechita;
}
float Factura::getSubTotal(){
    return this->subTotal;
}
void Factura::setSubTotal(float st){
    this->subTotal=st;
}
list<DtProductoFactura> Factura::getProductos(){
    return this->productos;
}
void Factura::setProductos(list<DtProductoFactura> prods){
    this->productos=prods;
}
float Factura::getDescuento(){
    return this->descuento;
}
void Factura::setDescuento(float d){
    this->descuento=d;
}
string Factura::getCodVenta(){
    return this->codVenta;
}
void Factura::setCodVenta(string cv){
    this->codVenta=cv;
}
DtFechaHora Factura::getFechaHora(){
    return this->fecha;
}
void Factura::setFechaHora(DtFechaHora fh){
    this->fecha= fh;
}
Factura::~Factura(){}