#include "ControladorBajaProducto.h"
#include "ManejadorProducto.h"
#include "ManejadorVenta.h"
#include "Menu.h"

ControladorBajaProducto::ControladorBajaProducto(){};
ControladorBajaProducto::~ControladorBajaProducto(){};

list<DtProductoBase> ControladorBajaProducto::listarProductos(){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    list<Producto*> productos=mP->getProductos();
    list<DtProductoBase> dtproductos;
    for (list<Producto*>::iterator it=productos.begin(); it != productos.end(); it++){
        DtProductoBase dtpb=(*it)->getDtProductoBase();
        dtproductos.push_back(dtpb);
    }
    return dtproductos;
}


void ControladorBajaProducto::seleccionarProducto(string cod){
    //this->setCodigo(cod);
    this->codigo=cod;
}

void ControladorBajaProducto::eliminarProducto(){//Recuerda codigo
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    Producto* pro=mP->getProducto(this->codigo);
    ManejadorVenta* mV=ManejadorVenta::getInstancia();
    list<Venta*> ventas=mV->getVentas();
    for (list<Venta*>::iterator it=ventas.begin(); it != ventas.end(); it++){
        (*it)->eliminarProducto(this->codigo);
    }
    TipoProducto tipo=pro->getTipoProducto();
    if(tipo==COMUN){
        list<Producto*> productos=mP->getProductos();
        for (list<Producto*>::iterator it=productos.begin(); it != productos.end(); it++){
            if ((*it)->getTipoProducto() == MENU){
                //Castear m a Menu para eso
                Menu *m = dynamic_cast<Menu*>((*it)); //casteo dinamico
                /* Falta corregir algo en Menu.h/cpp
                int cant = m->eliminarComun(this->codigo);      //ProductoMenu no deberia ser un parametro, solo el string
                
                if (cant==0){
                    string codM=m->getCodigo();
                    for (list<Venta*>::iterator it=ventas.begin(); it != ventas.end(); it++){
                        (*it)->eliminarProducto(m->getCodigo());
                    }
                    mP->removerProducto(m);
                    delete m;
                }
                */
            }
        }
    }
    mP->removerProducto(pro);
    delete pro;
}

void ControladorBajaProducto::cancelarBajaProducto(){
    
}; 