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
        cout << (*it) << endl;
        //dtproductos.push_back(dtpb); //esto no es para imprimir
    }
    return dtproductos;
}


void ControladorAgregarProducto::seleccionarProducto(DtProductoCantidad& pc){
    this->productoVenta=pc;
    //this->setProductoVenta(pc);
}

void ControladorAgregarProducto::seleccionarMesa(int idMesa){
    this->mesa=idMesa;
    //this->setMesa(idMesa);
}

void ControladorAgregarProducto::confirmarAgregarProductoVenta(){
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* me = mM->getMesa(this->mesa);
    me->agregarProducto(this->productoVenta);
}

void ControladorAgregarProducto::cancelarAgregarProductoVenta(){
    
};

ControladorAgregarProducto::~ControladorAgregarProducto(){};