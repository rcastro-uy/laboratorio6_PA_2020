#include "VentaLocal.h"

VentaLocal::VentaLocal(){}
VentaLocal::VentaLocal(string codigo):Venta(codigo){}

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

bool VentaLocal::tieneElProducto(string cod){
    bool tiene=false;
    int i=0;
    list<VentaProducto*> lista = this->getVentaProductos();
    for (list<VentaProducto*>::iterator it=lista.begin(); it!=lista.end(); ++it)
        if (!tiene){ // && i<lista.size()
            string codigo = (*it)->getCodigoProducto();
            tiene = codigo==cod;
            i++;
        }
        else{
            break;
        }
    return tiene;
}

void VentaLocal::incrementar(DtProductoCantidad pc){
    list<VentaProducto*> lista = this->getVentaProductos();
    for (list<VentaProducto*>::iterator it=lista.begin(); it!=lista.end(); ++it){
        string codigo = (*it)->getCodigoProducto();
        if(codigo==pc.getCodigo())
            (*it)->incrementarCantidad(pc.getCantidad());
    //this->cantidad=this->cantidad+pc.cantidad;
    }
}

void VentaLocal::agregarProducto(DtProductoCantidad pc){
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    Producto* pro=mP->getProducto(pc.getCodigo());
    VentaProducto* vp = new VentaProducto(pc.getCantidad(),pro);
    list<VentaProducto*> lista = this->getVentaProductos();
    lista.push_back(vp); 
}

list<DtProducto> VentaLocal::listarProductos(){
    list<DtProducto> dtproductos;
    list<VentaProducto*> lista = this->getVentaProductos();
    for (list<VentaProducto*>::iterator it=lista.begin(); it!=lista.end(); ++it){
        DtProducto dtp = (*it)->getDtProducto();
        dtproductos.push_back(dtp);
    }
    return dtproductos; 
}

void VentaLocal::quitarProducto(DtProductoCantidad pc){
    list<VentaProducto*> lista = getVentaProductos();
    for (list<VentaProducto*>::iterator it=lista.begin(); it!=lista.end(); ++it){
        string codigo = (*it)->getCodigoProducto();
        int queda;
        if(codigo == pc.getCodigo()){
            queda=(*it)->decrementarCantidad(pc.getCantidad());
        }
        if(queda<=0){
            lista.remove(*it);
            delete (*it);
        }
    }
}

list<DtProductoFactura> VentaLocal::getDtProductoFactura(){
    list<DtProductoFactura> dtproductosFact;
    list<VentaProducto*> lista = getVentaProductos();
    for (list<VentaProducto*>::iterator it=lista.begin(); it!=lista.end(); ++it){
        DtProductoFactura dtpf = (*it)->getDtProductoFactura();
        dtproductosFact.push_back(dtpf);
    }
    return dtproductosFact;
}

VentaLocal::~VentaLocal(){}