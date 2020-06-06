#include "VentaProducto.h"

VentaProducto::VentaProducto(){}
VentaProducto::VentaProducto(int cant, Producto* prod){
    this->cantidad=cant;
    this->producto=prod;
}

VentaProducto::~VentaProducto(){}

int VentaProducto::getCantidad(){
    return this->cantidad;
}

Producto* VentaProducto::getProducto(){
    return this->producto;
}

string VentaProducto::getCodigoProducto(){
//this->producto es un Producto*, pseudoatibuto
    return this->producto->getCodigo(); 
}

void VentaProducto::incrementarCantidad(int cantidad){
    this->cantidad=this->cantidad+cantidad; 
}

DtProducto VentaProducto::getDtProducto(){
    float precio = this->producto->getPrecio();
    string desc = this->producto->getDescripcion();
    string cod = this->producto->getCodigo();
    int cant = this->getCantidad();
    DtProducto dtp = DtProducto(cod,precio,desc,cant);
    return dtp; 
}

int VentaProducto::decrementarCantidad(int cantidad){
    this->cantidad=this->cantidad-cantidad;
    return this->cantidad;   
}

DtProductoFactura VentaProducto::getDtProductoFactura(){
    float precio = this->producto->getPrecio();
    string desc = this->producto->getDescripcion();
    int cant = this->getCantidad();
    DtProductoFactura dtpf = DtProductoFactura(precio,desc,cant);
    return dtpf; 
}

float VentaProducto::getPrecioProductoEnVenta(){
    float precio=this->producto->getPrecio();
    return this->cantidad*precio; 
}


