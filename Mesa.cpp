#include "Mesa.h"

Mesa::Mesa(){}
Mesa::Mesa(int num){
    this->numero = num;
}
int Mesa::getNumero(){
    return this->numero;
}
void Mesa::setNumero(int num){
    this->numero=num;
}
VentaLocal* Mesa::getVentaLocal(){
    return this->ventaLocal;
}
void Mesa::setVentaLocal(VentaLocal* vl){
    this->ventaLocal=vl;
}
bool Mesa::tieneVenta(){
    VentaLocal* vl = this->getVentaLocal();
    return vl==NULL;
    //return this->ventaLocal==NULL;
}
/*void Mesa::agregarProducto(DtProductoCantidad pc){
    bool tieneElProducto = this->ventaLocal->tieneElProducto(pc.codigo);
    if(tieneElProducto)
        this->ventaLocal->incrementar(pc);
    else
        this->ventaLocal->agregarProducto(pc);
}*/
list<DtProducto> Mesa::listarProductos(){
    list<DtProducto> dtproductos = this->ventaLocal->listarProductos();
    return dtproductos;
}
void Mesa::quitarProducto(pc DtProductoCantidad){
    this->ventaLocal->quitarProducto(pc);
}



