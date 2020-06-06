#include "ControladorAgregarVenta.h"

Set(DtProductoBase) listarProductos(){
    ManejadorProducto mP=ManejadorProduto::getInstancia();
    Set(Producto) productos=mP->getProductos();
    Set(DtProductoBase) dtproductos;
    foreach p in productos{
        DtProductoBase dtpb=p->getDtProductoBase();
        dtproductos.add(dtpb);
    }
return dtproductos;
}


void seleccionarProducto(pc:DtProductoCantidad){
    //this->productoVenta=pc;
    this->setProductoVenta(pc);
}

void seleccionarMesa(idMesa int){
    //this->mesa=idMesa;
    this->setMesa(idMesa);
}

void confirmarAgregarProductoVenta(){
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* me = mM->getMesa(this->mesa);
    me->agregarProducto(this->productoVenta);
}
