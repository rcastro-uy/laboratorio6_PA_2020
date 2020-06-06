#include "ControladorQuitarProducto.h"

Set(DtProducto) listarProductos(idMesa int){
    this->setMesa(idMesa);
    //this->mesa=idMesa;
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* me = mM->getMesa(idMesa);
    Set(DtProductos) dtProductos = me->listarProductos();
    return dtProductos;
}

void seleccionarProductoEliminar(pc:DtProductoCantidad){
    //this->productoVenta=pc;
    this->setProductoVenta(pc);
}

void confirmarQuitarProductoVenta(){
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* me = mM->getMesa(this->mesa);
    me->quitarProducto(this->productoVenta);
}