#include <stdexcept> //para el invalid_argument
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
    TipoProducto tp= pro->getTipoProducto();
    ManejadorVenta* mV=ManejadorVenta::getInstancia();
    list<VentaProducto*> vpList;
    list<Venta*> ventas=mV->getVentas();
    string codDeComAEliminar;
    for (list<Venta*>::iterator it=ventas.begin(); it != ventas.end(); it++){
        if((*it)->getFactura()==NULL){ //todas las ventas deben cumplir que no hayan sido facturadas
            vpList=(*it)->getVentaProductos();
            for (list<VentaProducto*>::iterator itb=vpList.begin(); itb !=vpList.end(); itb++){
                if(tp == MENU){
                    if((*itb)->getCodigoProducto()==this->codigo){// y si tiene el producto buscado
                        throw invalid_argument ("No se puede eliminar el producto; pertenece a una venta aun no facturada");
                    }
                }else{ //es comun
                    list<Producto*> listaDeMenus = mP->getProductos();
                    for (list<Producto*>::iterator itm=listaDeMenus.begin(); itm !=listaDeMenus.end(); itm++){
                        if((*itm)->getTipoProducto()==MENU){
                            Menu* men = dynamic_cast<Menu*>((*itm));
                            list<ProductoMenu*> comDeMenu = men->getListaProductos();
                            for (list<ProductoMenu*>::iterator itcm=comDeMenu.begin(); itcm !=comDeMenu.end(); itcm++){
                                codDeComAEliminar = (*itcm)->getCodigoComun();
                                if(codDeComAEliminar==this->codigo){
                                    throw invalid_argument ("No se puede eliminar el producto; pertenece a una venta aun no facturada");
                                }
                            }
                        }
                    }
                    if((*itb)->getCodigoProducto()==this->codigo){
                        throw invalid_argument ("No se puede eliminar el producto; pertenece a una venta aun no facturada");
                    }    
                //
                }
                
            }
        }                
    }
    for (list<Venta*>::iterator it=ventas.begin(); it != ventas.end(); it++){
        (*it)->eliminarProducto(this->codigo);
    }
    TipoProducto tipo=pro->getTipoProducto();
    if(tipo==COMUN){
        list<Producto*> productos=mP->getProductos();
        for (list<Producto*>::iterator it=productos.begin(); it != productos.end(); it++){
            if ((*it)->getTipoProducto() == MENU){
                Menu *m = dynamic_cast<Menu*>((*it));
                int cant = m->eliminarComun(this->codigo);
                if (cant==0){
                    string codM=m->getCodigo();
                    for (list<Venta*>::iterator it=ventas.begin(); it != ventas.end(); it++){
                        (*it)->eliminarProducto(m->getCodigo());
                    }
                    mP->removerProducto(m);
                    delete m;
                }
                
            }
        }
    }
    mP->removerProducto(pro);
    delete pro;
}

bool ControladorBajaProducto::existeProducto(string){
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    bool existe=mP->existeProducto(this->codigo);
    if (!existe){
		throw invalid_argument("ERROR: NO EXISTE UN PRODUCTO CON ESE IDENTIFICADOR\n");
    }else{
        return true;
    }
}

void ControladorBajaProducto::cancelarBajaProducto(){
    
}; 