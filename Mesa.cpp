#include "mesa.h"

Mesa::Mesa(){}
Mesa::Mesa(int num){
    this->numero = num;
}

bool Mesa::tieneVenta(){
VentaLocal* vl = this->getVentaLocal();
return vl==NULL;
//return this->ventaLocal==NULL;
}
void Mesa::agregarProducto(pc DtProductoCantidad){
    bool tieneElProducto = this->ventaLocal->tieneElProducto(pc.codigo);
    if(tieneElProducto)
        this->ventaLocal->incrementar(pc);
    else
        this->ventaLocal->agregarProducto(pc);
}
list<DtProducto> Mesa::listarProductos(){
    list<DtProducto> dtproductos = this->ventaLocal->listarProductos();
    return dtproductos;
}
void Mesa::quitarProducto(pc DtProductoCantidad){
this->ventaLocal->quitarProducto(pc);
}



