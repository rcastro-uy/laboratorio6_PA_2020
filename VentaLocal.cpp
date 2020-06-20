#include "VentaLocal.h"

VentaLocal::VentaLocal(){}
VentaLocal::VentaLocal(string codigo, Mozo* mozo):Venta(codigo){
    this->mozo=mozo;
}

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
    this->setVentaProductos(lista);
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
        int queda = 0;
        if(codigo == pc.getCodigo()){
            cout << "Se decrementará de la lista" << endl;
            queda=(*it)->decrementarCantidad(pc.getCantidad());
            if(queda<=0){
                cout << "Se va a remover de la lista ya que queda vale <=0" << endl;
                lista.remove(*it);
                delete (*it);
                cout << "Termina de eliminar" << endl;
            }
        break;
        }
    }
    this->setVentaProductos(lista);
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

string VentaLocal::getNombreMozo(){
    return this->mozo->getNombre();
}
float VentaLocal::getSubTotalVenta(){
    list<VentaProducto*> prods(this->getVentaProductos());
    int lista_venta_productos = (this->getVentaProductos()).size();
    int tam_nueva_lista = prods.size();
    cout << "El largo de lista_venta_productos es: " << lista_venta_productos << endl;
    cout << "El largo de tam_nueva_lista es: " << tam_nueva_lista << endl; 
    float suma =0;
    float costoItem = 0;
    for (list<VentaProducto*>::iterator it=prods.begin(); it!=prods.end(); ++it){
        cout << "El costo de este producto es: " << (*it)->getPrecioProductoEnVenta() <<endl;
        costoItem = (*it)->getPrecioProductoEnVenta();
        suma=suma+costoItem;
    }
    cout << "Se retornará el subtotal: " << suma << endl;
    return suma;
}

VentaLocal::~VentaLocal(){}