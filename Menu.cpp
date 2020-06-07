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
int Menu::eliminarComun(Comun pro,string codigo){
    for (list<Comun*>::iterator it=this->comunes.begin(); it != this->comunes.end(); it++){
        string cod=(*it)->getCodigo();
        if(cod==codigo){
            this->comunes.remove(*it);
            delete *it;
            this->decrementarCantComunes(1);//this->cantComunes--;
        }
    }
    //int cant = getCantComunes();
    //return cant;
    return this->cantComunes;
}
void Menu::incrementarPrecio(float precio){
    float p = getPrecio();
    p = p + precio;
    setPrecio(p);
    //this->precio = this->precio + precio;
}
void Menu::aplicarDescuento(){
    float p = getPrecio();
    p = p*0.90;
    setPrecio(p);
    //this->precio=this->precio*0.90;
}
/*void Menu::agregarComunes(list<DtProducto> productosComunes){
    for (list<Comun*>::iterator it=this->comunes.begin(); it != this->comunes.end(); it++){
        Comun* pm = new Comun((*it)->cantidad);
        pm->asignarComun(pc.codigo);
        this->productosMenu.add(pm);
        this->incrementarCantComunes(1);//this->cantComunes++;
    }
}*/

void Menu::calcularPrecio(){
    for (list<Comun*>::iterator it=this->comunes.begin(); it != this->comunes.end(); it++){
        float precioCom = (*it)->getPrecio();
        this->incrementarPrecio(precioCom);
    }
    this->aplicarDescuento();
}
Menu::~Menu(){}