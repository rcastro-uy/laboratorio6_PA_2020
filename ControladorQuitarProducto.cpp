#include "ControladorQuitarProducto.h"
#include "ManejadorProducto.h"
#include "ManejadorMesa.h"

list<DtProducto> ControladorQuitarProducto::listarProductos(int idMesa){
    //this->setMesa(idMesa);
    this->mesa=idMesa;
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* me = mM->getMesa(idMesa);
    list<DtProducto> dtProductos = me->listarProductos();
    return dtProductos;
}

void ControladorQuitarProducto::seleccionarProductoEliminar(DtProductoCantidad pc){
    this->productoVenta=pc;
    //this->setProductoVenta(pc);
}

void ControladorQuitarProducto::confirmarQuitarProductoVenta(){
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* me = mM->getMesa(this->mesa);
    me->quitarProducto(this->productoVenta);
}

void ControladorQuitarProducto::cancelarQuitarProductoVenta(){
    //this->productoVenta.~DtProductoCantidad();
}