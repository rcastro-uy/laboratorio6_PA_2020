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

DtProductoMenu::~DtProductoMenu(){}