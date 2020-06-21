#include "ControladorAgregarProducto.h"
#include "ManejadorProducto.h"
#include "ManejadorMesa.h"

ControladorAgregarProducto::ControladorAgregarProducto(){};

list<DtProductoBase> ControladorAgregarProducto::listarProductos(){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    list<Producto*> productos=mP->getProductos();
    list<DtProductoBase> dtproductos;
    for (list<Producto*>::iterator it=productos.begin(); it != productos.end(); it++){
        DtProductoBase dtpb=(*it)->getDtProductoBase();
        dtproductos.push_back(dtpb);
    }
    return dtproductos;
}


void ControladorAgregarProducto::seleccionarProducto(DtProductoCantidad& pc){
    this->productoVenta.push_back(pc);
    //this->setProductoVenta(pc);
}

void ControladorAgregarProducto::seleccionarMesa(int idMesa){
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    if (mM->mesaTieneVenta(idMesa)){
        this->mesa=idMesa;
    }else{
        throw invalid_argument ("LA MESA SELECCIONADA NO TIENE UNA VENTA ASOCIADA");
    }
    
    //this->setMesa(idMesa);
}

void ControladorAgregarProducto::confirmarAgregarProductoVenta(){
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* me = mM->getMesa(this->mesa);
    for (list<DtProductoCantidad>::iterator it=this->productoVenta.begin(); it != this->productoVenta.end(); it++){
        me->agregarProducto(*it);
    }
    this->productoVenta.clear();
}

void ControladorAgregarProducto::cancelarAgregarProductoVenta(){
    
};

ControladorAgregarProducto::~ControladorAgregarProducto(){};