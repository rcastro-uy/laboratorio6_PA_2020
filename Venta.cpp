#include "Venta.h"

Venta::Venta(){}
Venta::Venta (string codigo, list<VentaProducto*> ventaProductos){
    this->codigo=codigo;
    this->ventaProductos=ventaProductos; // *SE INICIALIZA LA LISTA? COMO?
}

string Venta::getcodigo(){
    return this->codigo;
}

void Venta::setCodigo(string codigo){
    this->codigo=codigo;
}

list<VentaProducto*> Venta::getVentaProductos(){
    list<VentaProducto*> lstVtaProd;
    for (list<VentaProducto*>::iterator it=this->ventaProductos.begin(); it!=ventaProductos.end(); ++it)
        lstVtaProd.push_back(*it); //revisar
    return lstVtaProd;
}
Venta::~Venta(){}
