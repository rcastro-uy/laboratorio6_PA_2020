#include "ManejadorMesa.h"
#include "Mesa.h"
#include <list>
#include <iostream>

using namespace std;

ManejadorMesa* ManejadorMesa:: instancia = NULL;

ManejadorMesa* ManejadorMesa:: getInstancia(){
    if (instancia == NULL) {
        instancia = new ManejadorMesa();
    }
    return instancia;
}

list<Mesa*> ManejadorMesa:: getMesas(){
    list<Mesa*> lstMesas;
    for (list<Mesa*>::iterator it=this->mesas.begin();it!=mesas.end(); ++it){
        lstMesas.push_back(it->second);
    }
    return lstEmpleados;
}

Mesa* ManejadorMesa:: getMesa(int mesas){
    list<Mesa*>::iterator it = this->mesas.find(mesas);
    return it->second;
}

void ManejadorMesa:: removerMesa(Mesa*){
    map<string,Empleado*>::iterator it = this->empleados.find(empleado);
    this->empleados.erase(it);
}

void ManejadorMesa:: agregarMesa(Mesa* mesas){
    mesas.insert(std::pair<string,Empleado*>(empleados->getidEmpleado(),empleado))
}

ManejadorMesa::~ManejadorMesa(){}
