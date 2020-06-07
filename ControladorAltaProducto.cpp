#include "ControladorAltaProducto.h"
#include "DtProducto.h"
#include "DtProductoBase.h"


Set(DtProductoBase) listarProductos(){
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


void datosProductoComun(cod:string, desc:string, precio:string){
    this->codComun=cod;
    this->descComun=desc;
    this->precioComun=precio;
}


void confirmarProductoComun(){
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    Comun* c=new Comun(this->codComun,this->descComun,this->precioComun)
    mP->agregarProducto(c);
}

void datosProductoMenu(cod:string, desc:string){
    this->codMenu=cod;
    this->descMenu=desc;
}

void agregarAlProductoMenu(pc:DtProductoCantidad){
    this->productosComun.add(pc);
}

void confirmarProductoMenu(){
    Menu* m=new Menu(this->codMenu,this->descMenu,0,0);
    //this->cantComunes=0, this->precio=0;
    m->agregarComunes(this->productosComun);
    m->calcularPrecio();
    ManejadorProducto* mP=ManejadorPorducto::getInstancia();
    mP->agregarProducto(Producto);
}






