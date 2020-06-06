#include "ControladorBajaProducto.h"

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


void seleccionarProducto(cod:String){
    this->setCodigo(cod);
    //this->codigo=cod;
}

void eliminarProducto(){//Recuerda codigo
    ManejadorProducto mP=ManejadorProduto::getInstancia();
    Producto* pro=mP->getProducto(this->codigo);
    ManejadorVenta mV=ManejadorVenta::getInstancia();
    Set(Venta) ventas=mV->getVentas();
    foreach v in ventas{
        v->eliminarProducto(this->codigo);
    }
    TipoProducto tipo=pro->getTipoProducto();
    if(tipo==COMUN){
        Set(Producto) productos=mP->getProductos();
        foreach m in Producto{
            int cant = (Menu)m->eliminarComun(pro,this->codigo);
            //Castear m a Menu para eso
            if (cant==0){
            string codM=m->getCodigo();
            foreach v in ventas{
                v->eliminarProducto(codM);
            }
            mP->removerProducto(m);
            delete m;
            }
        }
    }
    mP->removerProducto(pro);
    delete pro;
}

