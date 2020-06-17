#include "Venta.h"

Venta::Venta(){}
Venta::Venta (string codigo){
    this->codigo=codigo;
}

string Venta::getCodigo(){
    return this->codigo;
}

void Venta::setCodigo(string codigo){
    this->codigo=codigo;
}

list<VentaProducto*> Venta::getVentaProductos(){
    list<VentaProducto*> lstVtaProd;
    for (list<VentaProducto*>::iterator it=this->ventaProductos.begin(); it!=ventaProductos.end(); ++it)
        lstVtaProd.push_back(*it);
    return lstVtaProd;
}

void Venta::setVentaProductos (list<VentaProducto*> vp){
    this->ventaProductos=vp;
}

Factura* Venta::getFactura(){
    return this->factura;
}

void Venta::setFactura (Factura* fac){
    this->factura=fac;
}

Venta::~Venta(){}
