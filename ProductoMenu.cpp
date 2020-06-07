#include "ProductoMenu.h"
#include "ManejadorProducto.h"
ProductoMenu::ProductoMenu(){}
ProductoMenu::ProductoMenu(int cant){
    this->cantidad = cant;
}
int ProductoMenu::getCant(){
    return this->cantidad;
}
string ProductoMenu::getCodigoComun(){
    //this->comun es un Comun*, pseudoatibuto
    return this->comun->getCodigo();
}

void ProductoMenu::asignarComun(string codigo){
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    if(mP->getProducto(codigo)->getTipoProducto() == TipoProducto.COMUN){
        Comun *c = mP->getProducto(codigo); //casteo dinamico
        this->comun=c;
    }
} //falta arreglar

float ProductoMenu::getPrecio(){
    //this->comun es un Comun*, pseudoatributo
    return this->comun->getPrecio()*this->cantidad;
}
Comun* ProductoMenu::getComun(){
    return this->comun;
}
ProductoMenu::~ProductoMenu(){}