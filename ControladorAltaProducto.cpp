#include <stdexcept> //para el invalid_argument
#include "ControladorAltaProducto.h"
#include "Menu.h"
#include "ManejadorProducto.h"
#include "ManejadorVenta.h"



ControladorAltaProducto::ControladorAltaProducto(){};

list<DtProductoBase> ControladorAltaProducto::listarProductos(){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    list<Producto*> productos=mP->getProductos();
    list<DtProductoBase> dtproductos;
    for (list<Producto*>::iterator it=productos.begin(); it != productos.end(); it++){
        DtProductoBase dtpb=(*it)->getDtProductoBase();
        dtproductos.push_back(dtpb);
    }
    return dtproductos;
}

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

list<DtProductoBase> ControladorAltaProducto::listarProductosMenu(){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    list<Producto*> productos=mP->getProductos();
    list<DtProductoBase> dtproductos;
    for (list<Producto*>::iterator it=productos.begin(); it != productos.end(); it++){
        DtProductoBase dtpb=(*it)->getDtProductoBase();
        if ((*it)->getTipoProducto() == MENU )
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
    bool existe=mP->existeProducto(this->codComun);
    //try catch antes de confirmarlo
    if(!existe){
        Comun* c=new Comun(this->codComun,this->precioComun,this->descComun);
        mP->agregarProducto(c);
    }else
        throw invalid_argument("ERROR: YA EXISTE UN PRODUCTO CON ESE IDENTIFICADOR\n");
    
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
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    bool existe=mP->existeProducto(this->codMenu);
    //try catch antes de confirmarlo
    if(!existe){
        Menu* m=new Menu(this->codMenu,0,this->descMenu,0);
        m->agregarComunes(this->ProductoComun);
        m->calcularPrecio();
        mP->agregarProducto(m);
        cancelarProductoMenu();
    }else
        throw invalid_argument("ERROR: YA EXISTE UN PRODUCTO CON ESE IDENTIFICADOR\n");
}

void ControladorAltaProducto::cancelarProductoMenu(){
    this->codMenu.clear();
    this->descMenu.clear();
    this->ProductoComun.clear();
}

bool ControladorAltaProducto::existeProducto(string cod){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    return mP->existeProducto(cod);
}

DtProducto* ControladorAltaProducto::detallesProducto(string cod){
    //find del Producto buscado y retorno en un DtProductoBase
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    ManejadorVenta* mV = ManejadorVenta::getInstancia();
    list<Venta*> ventas;
    Producto* prod;
    int cant_productos_facturada=0;
    if(mP->existeProducto(cod)){
        prod = mP->getProducto(cod);
            //Una vez tengo el producto, debo buscar las ventas que tienen venta producto con ese producto y a su vez tienen factura !=NULL
            //Me traigo todas las ventas para preguntarles
            ventas = mV->getVentas();
            for (list<Venta*>::iterator it=ventas.begin(); it != ventas.end(); it++){
                if((*it)->getFactura()!=NULL){
                    list<VentaProducto*> vp_list=(*it)->getVentaProductos();
                    for (list<VentaProducto*>::iterator it_vp=vp_list.begin(); it_vp != vp_list.end(); it_vp++){
                        if((*it_vp)->getCodigoProducto()==cod){
                            cant_productos_facturada+=(*it_vp)->getCantidad();
                        }
                    }
                }
            }
            if(prod->getTipoProducto()==COMUN){
                DtProductoComun* dtprod = new DtProductoComun (cod,prod->getDescripcion(),prod->getPrecio(),cant_productos_facturada);
                return dtprod;
            }
            else{ //SI ES MENU
                //castear
                Menu *menu = dynamic_cast<Menu*>(prod);
                list<DtProductoComun*> prod_comunes_menu;
                list<ProductoMenu*> prod_menu = menu->getListaProductos();
                for (list<ProductoMenu*>::iterator it_pm=prod_menu.begin(); it_pm != prod_menu.end(); it_pm++){
                    DtProductoComun* com = new DtProductoComun((*it_pm)->getCodigoComun(),(*it_pm)->getDescComun(),(*it_pm)->getPrecio(),(*it_pm)->getCant());
                    prod_comunes_menu.push_back(com);
                }
                DtProductoMenu* dtmenu = new DtProductoMenu(cod,prod->getDescripcion(),prod->getPrecio(),cant_productos_facturada,prod_comunes_menu);
                return dtmenu;
            }
        
        //Recorro las ventas obteniendo su VentaProducto, para luego preguntarle a cada una por sus ventaProducto, y a cada uno preguntarle si su Producto* matchea con el str cod
            
    }
    else
        throw invalid_argument("ERROR: NO EXISTE UN PRODUCTO CON ESE IDENTIFICADOR\n");
}

ControladorAltaProducto::~ControladorAltaProducto(){};