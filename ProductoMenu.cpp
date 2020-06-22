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
    return this->comun->getCodigo();
}

string ProductoMenu::getDescComun(){
    return this->comun->getDescripcion();
}

void ProductoMenu::asignarComun(string codigo){
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    Comun *c = dynamic_cast<Comun*>(mP->getProducto(codigo)); 
    if(c != NULL)
        this->comun=c;
}

float ProductoMenu::getPrecio(){

    return this->comun->getPrecio()*this->cantidad;
}
Comun* ProductoMenu::getComun(){
    return this->comun;
}
ProductoMenu::~ProductoMenu(){}