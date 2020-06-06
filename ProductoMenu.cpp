#include "ProductoMenu.h"
#include "ManejadorProducto.h"
ProductoMenu::ProductoMenu(){}
ProductoMenu::ProductoMenu(int){
    
}
int ProductoMenu::getCant(){
    return this->cantidad;
}
string ProductoMenu::getCodigoComun(){
    //this->comun es un Comun*, pseudoatibuto
    return this->comun->getCodigo();
}

/*void ProductoMenu::asignarComun(String codigo){
    ManejadorProducto mP = ManejadorProducto::getInstancia();
    Producto c = mP->getProducto(c);
    this->setComun(c);
    //this->comun=c;
} falta arreglar*/

float ProductoMenu::getPrecio(){
    //this->comun es un Comun*, pseudoatibuto
    return this->comun->getPrecio()*this->cantidad;
}
