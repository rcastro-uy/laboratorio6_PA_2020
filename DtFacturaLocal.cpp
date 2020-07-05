#include "DtFacturaLocal.h"
DtFacturaLocal::DtFacturaLocal(){}
DtFacturaLocal::DtFacturaLocal(string codVenta, DtFechaHora fechaEmision, float descuento,list<DtProductoFactura> productosfac, float subtotal,float montoTotalVenta,float montoTotalVentaConIVA,string nombreMozo){
    this->codVenta=codVenta;
    this->fechaEmision=fechaEmision;
    this->descuento=descuento;
    this->productos=productosfac;
    this->subtotal=subtotal;
    this->montoTotalVenta=montoTotalVenta;
    this->montoTotalVentaConIVA=montoTotalVentaConIVA;
    this->nombreMozo=nombreMozo;

}
string DtFacturaLocal::getCodVenta(){
    return this->codVenta;
}
void DtFacturaLocal::setCodVenta(string cv){
    this->codVenta=cv;
}
DtFechaHora DtFacturaLocal::getFechaEmision(){
    return this->fechaEmision;
}
void DtFacturaLocal::setFechaEmision(DtFechaHora fe){
    this->fechaEmision=fe;
}
float DtFacturaLocal::getDescuento(){
    return this->descuento;
}
void DtFacturaLocal::setDescuento(float desc){
    this->descuento=desc;
}
list<DtProductoFactura> DtFacturaLocal::getProductos(){
    return this->productos;
}
void DtFacturaLocal::setProductos(list<DtProductoFactura> prods){
    this->productos=prods;
}
float DtFacturaLocal::getSubtotal(){
    return this->subtotal;
}
void DtFacturaLocal::setSubtotal(float st){
    this->subtotal=st;
}
float DtFacturaLocal::getMontoTotalVenta(){
    return this->montoTotalVenta;
}
void DtFacturaLocal::setMontoTotalVenta(float mtv){
    this->montoTotalVenta=mtv;
}
float DtFacturaLocal::getMontoTotalVentaConIVA(){
    return this->montoTotalVentaConIVA;
}
void DtFacturaLocal::setMontoTotalVentaConIVA(float mtvci){
    this->montoTotalVentaConIVA=mtvci;
}
string DtFacturaLocal::getNombreMozo(){
    return this->nombreMozo;
}
void DtFacturaLocal::setNombreMozo(string nombre){
    this->nombreMozo=nombre;
}

ostream& operator <<(ostream& salida,const DtFacturaLocal& dfl){
    list<DtProductoFactura> lista = dfl.productos;
	cout << "Codigo: " << dfl.codVenta << "\nFecha de Emision: " << dfl.fechaEmision << "\nDescuento aplicado: " << dfl.descuento << "\nProductos: " << endl;
    for (list<DtProductoFactura>::iterator it=lista.begin(); it != lista.end(); ++it){
        cout << *it;
    }
    cout << "\n" << "Subtotal: " << dfl.subtotal << "\nMonto Total de la Venta sin IVA: " << dfl.montoTotalVenta << "\nMonto Total de la Venta con IVA incl. : " << dfl.montoTotalVentaConIVA << "\nUd. fue atendido por: " << dfl.nombreMozo << endl;
    return salida;
}

DtFacturaLocal::~DtFacturaLocal(){}