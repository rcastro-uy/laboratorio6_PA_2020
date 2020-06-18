#include "Mozo.h"
#include "ManejadorMesa.h"

Mozo::Mozo(){}
Mozo::Mozo(string id,string nombre, list<Mesa*> mesas):Empleado(id,nombre){
    this->mesas=mesas;
}

list<Mesa*> Mozo::getMesas(){
    return this->mesas;
}

void Mozo::setMesas(list<Mesa*> mesas){
    this->mesas=mesas;
}

list<int> Mozo::mesasAsignadasSinVenta(){
    list<int> mesasSinVenta;
    for (list<Mesa*>::iterator it=mesas.begin(); it!=mesas.end(); ++it){
        bool tieneVenta=(*it)->tieneVenta();
        if(!tieneVenta){
            int num = (*it)->getNumero();
            mesasSinVenta.push_back(num);
        }
    }
    return mesasSinVenta;
}

//pendiente - rcastro
void Mozo::asignarMesas(list<int> listamesas, VentaLocal* vl){
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    int me;
    Mesa* m;
    for (list<int>::iterator it=listamesas.begin(); it!=listamesas.end(); ++it){
        me=*it;
        m = mM->getMesa(me);
        mesas.push_back(m);
    }
    m->setVentaLocal(vl);
}

Mozo::~Mozo(){}