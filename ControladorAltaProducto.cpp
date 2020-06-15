#include "ControladorAltaProducto.h"
#include "Menu.h"
#include "ManejadorProducto.h"


ControladorAltaProducto::ControladorAltaProducto(){};

list<DtProductoBase> ControladorAltaProducto::listarProductosComunes(){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    list<Producto*> productos=mP->getProductos();
    list<DtProductoBase> dtproductos;
    for (list<Producto*>::iterator it=productos.begin(); it != productos.end(); it++){
        DtProductoBase dtpb=(*it)->getDtProductoBase();
        if ((*it)->getTipoProducto() == COMUN )
            dtproductos.push_back(dtpb);
    }
    return dtproductos;
}


void ControladorAltaProducto::datosProductoComun(string cod, string desc, float precio){
    this->codComun=cod;
    this->descComun=desc;
    this->precioComun=precio;
}


void ControladorAltaProducto::confirmarProductoComun(){
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    Comun* c=new Comun(this->codComun,this->precioComun,this->descComun);
    mP->agregarProducto(c);
}

void ControladorAltaProducto::cancelarProductoComun(){
    this->codComun.clear();
    this->descComun.clear();
}

void ControladorAltaProducto::datosProductoMenu(string cod, string desc){
    this->codMenu=cod;
    this->descMenu=desc;
}

void ControladorAltaProducto::agregarAlProductoMenu(DtProductoCantidad pc){
    this->ProductoComun.push_back(pc);
}

void ControladorAltaProducto::confirmarProductoMenu(){
    Menu* m=new Menu(this->codMenu,0,this->descMenu,0);
    m->agregarComunes(this->ProductoComun);
    m->calcularPrecio();
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    mP->agregarProducto(m);
}

void ControladorAltaProducto::cancelarProductoMenu(){
    this->codMenu.clear();
    this->descMenu.clear();
    this->ProductoComun.clear();
}

ControladorAltaProducto::~ControladorAltaProducto(){};