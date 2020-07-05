#include "ControladorQuitarProducto.h"
#include "ManejadorProducto.h"
#include "ManejadorMesa.h"

ControladorQuitarProducto::ControladorQuitarProducto(){}

list<DtProducto> ControladorQuitarProducto::listarProductos(int idMesa){
    //this->setMesa(idMesa);
    this->mesa=idMesa;
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* me = mM->getMesa(idMesa);
    if(me->getVentaLocal()!=NULL){
        list<DtProducto> dtProductos = me->listarProductos();
        return dtProductos;
    }else{
        throw invalid_argument("ERROR: ESTA MESA NO TIENE VENTA ASOCIADA O NO TIENE NINGUN PRODUCTO\n");
    }
}

void ControladorQuitarProducto::seleccionarProductoEliminar(DtProductoCantidad pc){
    this->productoVenta.push_back(pc);
    //this->setProductoVenta(pc);
}

void ControladorQuitarProducto::confirmarQuitarProductoVenta(){
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* me = mM->getMesa(this->mesa);
    for (list<DtProductoCantidad>::iterator it=this->productoVenta.begin(); it != this->productoVenta.end(); ++it){
        me->quitarProducto(*it);
    }
    this->productoVenta.clear();
}

void ControladorQuitarProducto::cancelarQuitarProductoVenta(){
    this->productoVenta.clear();
}

ControladorQuitarProducto::~ControladorQuitarProducto(){}