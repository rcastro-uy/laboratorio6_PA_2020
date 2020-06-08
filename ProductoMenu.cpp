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
    Comun *c = dynamic_cast<Comun*>(mP->getProducto(codigo)); //casteo dinamico
    if(c != NULL)
        this->comun=c;
}

float ProductoMenu::getPrecio(){
    //this->comun es un Comun*, pseudoatributo
    return this->comun->getPrecio()*this->cantidad;
}
Comun* ProductoMenu::getComun(){
    return this->comun;
}
ProductoMenu::~ProductoMenu(){}