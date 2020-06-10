#include "ControladorAltaProducto.h"
#include "Menu.h"
#include "ManejadorProducto.h"


Set(DtProductoBase) ControladorAltaProducto::listarProductos(){
    ManejadorProducto mP=ManejadorProduto::getInstancia();
    Set(Producto) productos=mP->getProductos();
    Set(DtProductoBase) dtproductos;
    foreach c in productos{
        //Hay que castear al Producto c a Comun
        DtProductoBase dtpb=(COMUN)c->getDtProductoBase();
        dtproductos.add(dtpb);
}
return dtproductos;
}


void ControladorAltaProducto::datosProductoComun(cod:string, desc:string, precio:string){
    this->codComun=cod;
    this->descComun=desc;
    this->precioComun=precio;
}


void ControladorAltaProducto::confirmarProductoComun(){
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    Comun* c=new Comun(this->codComun,this->descComun,this->precioComun)
    mP->agregarProducto(c);
}

void ControladorAltaProducto::datosProductoMenu(cod:string, desc:string){
    this->codMenu=cod;
    this->descMenu=desc;
}

void ControladorAltaProducto::agregarAlProductoMenu(pc:DtProductoCantidad){
    this->productosComun.add(pc);
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