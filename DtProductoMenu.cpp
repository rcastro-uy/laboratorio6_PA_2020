#include "DtProductoMenu.h"

DtProductoMenu::DtProductoMenu(){}
DtProductoMenu::DtProductoMenu(string codigo,string desc,float precio,int cant, list<DtProductoComun*> productos):DtProducto(codigo, desc,precio,cant){
    this->productos=productos;
}
list<DtProductoComun*> DtProductoMenu::getProductos(){
    return this->productos;
}

void DtProductoMenu::setProductos(list<DtProductoComun*> prods){
    this->productos=prods;
}

ostream& operator <<(ostream& salida,const DtProductoMenu& dtpb){
    list<DtProductoComun*> lista = dtpb.productos;
	cout << (DtProducto)dtpb << endl;
    for (list<DtProductoComun*>::iterator it=lista.begin(); it != lista.end(); ++it){
        cout << *(*it);
    }
	return salida;
}
DtProductoMenu::~DtProductoMenu(){}