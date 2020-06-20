#include "DtProductoFactura.h"

DtProductoFactura::DtProductoFactura(){}
DtProductoFactura::DtProductoFactura(string descripcion,float precio,int cantidad){
    this->descripcion=descripcion;
    this->cantidad=cantidad;
    this->precio=precio;
}

string DtProductoFactura::getDescripcion(){
    return this->descripcion;
}
void DtProductoFactura::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}
float DtProductoFactura::getPrecio(){
    return this->precio;
}
void DtProductoFactura::setPrecio(float precio){
    this->precio=precio;
}
int DtProductoFactura::getCantidad(){
    return this->cantidad;
}
void DtProductoFactura::setCantidad(int cantidad){
    this->cantidad=cantidad;
}

ostream& operator <<(ostream& salida,const DtProductoFactura& dpf){
	cout << "Descripcion: " << dpf.descripcion << "\tPrecio: " << dpf.precio << "\tCantidad: " << dpf.cantidad <<endl;
	return salida;
}

DtProductoFactura::~DtProductoFactura(){}

