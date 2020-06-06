#include "VentaLocal.h"

VentaLocal::VentaLocal(){}
VentaLocal::VentaLocal(string codigo, list<VentaProducto*> ventaProductos):Venta(codigo, ventaProductos){}

void VentaLocal::eliminarProducto(string codigo){
//this->ventaProductos es un Set(VentaProducto*), pseudoatibuto
    list<VentaProducto*> lstVtaProd = getVentaProductos();
    for (list<VentaProducto*>::iterator vp=lstVtaProd.begin(); vp != lstVtaProd.end(); ++vp){
        string cod = (*vp)->getCodigoProducto();
        if(cod == codigo){
            lstVtaProd.erase(vp);
            //delete vp; ^-- se elimina aqui?
        
        }
    }
}