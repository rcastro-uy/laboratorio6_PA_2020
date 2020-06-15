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


//NIC: estaba probando eliminar asi que no se asusten con los cout, son debug
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
                cout << ">>>>TIPO MENU" << endl;
                //Castear m a Menu para eso
                Menu *m = dynamic_cast<Menu*>((*it)); //casteo dinamico
                cout << ">>>>TIPO MENU CASTEADO" << endl;
                cout << ">>>>" << m->getCodigo() << endl;
                // Falta corregir algo en eliminarComun (se caga aca)
                int cant = m->eliminarComun(this->codigo);      //ProductoMenu no deberia ser un parametro, solo el string
                cout << ">>>>" << m->getCodigo() << endl;
                if (cant==0){
                    cout << ">>>>MENU TIENE 0 PRODUCTOS" << endl;
                    string codM=m->getCodigo();
                    for (list<Venta*>::iterator it=ventas.begin(); it != ventas.end(); it++){
                        (*it)->eliminarProducto(m->getCodigo());
                    }
                    mP->removerProducto(m);
                    cout << ">>>>MENU FUERA DE COLECCION" << endl;
                    delete m;
                    cout << ">>>>MENU BORRADO" << endl;
                }
                
            }
        }
    }
    mP->removerProducto(pro);
    delete pro;
}

void ControladorBajaProducto::cancelarBajaProducto(){
    
}; 