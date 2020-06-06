#include "Menu.h"

Menu::Menu(){}
Menu::Menu(string codigo,float precio,string desc,int cant):Producto(codigo,precio,desc){
    cantComunes = cant;
}
void Menu::setCantComunes(int cant){
    this->cantComunes = cant;
}
int Menu::getCantComunes(){
    return this->cantComunes;
}
TipoProducto Menu::getTipoProducto(){
    return TipoProducto.MENU;
}
void Menu::incrementarCantComunes(int cant){
    this->cantComunes = this->cantComunes + cant; 
}
void Menu::decrementarCantComunes(int cant){
    this->cantComunes = this->cantComunes - cant;  
}
/*int Menu::eliminarComun(Comun pro,string codigo){
    foreach pm in ProductoMenu{
        string cod=getCodigoComun();
        if(cod==codigo){
            this->productosMenu.remover(pm);
            delete pm;
            this->decrementarCantComunes(1);//this->cantComunes--;
        }
    }
    int cant = getCantComunes();
    return cant;
    //return this->cantComunes;
} como vamos a listar los productos comunes dentro de menu*/
void Menu::incrementarPrecio(float precio){
    this->precio = this->precio + precio;
}
void Menu::aplicarDescuento(){
    this->precio=this->precio*0.90;
}
/*void Menu::agregarComunes(Set(DtProductoCantidad) productosComun){
    foreach pc in productosComun
    ProductoMenu* pm = new ProductoMenu(pc.cantidad);
    pm->asignarComun(pc.codigo);
    this->productosMenu.add(pm);
    this->incrementarCantComunes();
    //this->cantComunes++;
} Lo mismo que arriba 

void Menu::calcularPrecio(){
    foreach pm in this->productosMenu{
    float precioCom = pm->getPrecio();
    this->incrementarPrecio(precioCom);
    }
    this->aplicarDescuento();
}*/
Menu::~Menu(){}