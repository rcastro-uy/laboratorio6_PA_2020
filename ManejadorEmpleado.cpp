#include "ManejadorEmpleado.h"
#include "Empleado.h"
#include <list>
#include <iostream>

using namespace std;

ManejadorEmpleado* ManejadorEmpleado:: instancia = NULL;

ManejadorEmpleado* ManejadorEmpleado:: getInstancia(){
    if (instancia == NULL) {
        instancia = new ManejadorEmpleado();
    }
    return instancia;
}

list<Empleado*> ManejadorEmpleado:: getEmpleados(){
    list<Empleado*> lstEmpleados;
    for (map<string,Empleado*>::iterator it=this->empleados.begin();it!=empleados.end(); ++it){
        lstEmpleados.push_back(it->second);
    }
    return lstEmpleados;
}

Empleado* ManejadorEmpleado:: getEmpleado(string empleado){
    map<string,Empleado*>::iterator it = this->empleados.find(empleado);
    return it->second;
}

void ManejadorEmpleado:: removerEmpleado(Empleado* empleado){
    map<string,Empleado*>::iterator it = this->empleados.find(empleado);
    this->empleados.erase(it);
}

void ManejadorEmpleado:: agregarEmpleado(Empleado* empleado){
    empleados.insert(std::pair<string,Empleado*>(empleados->getidEmpleado(),empleado))
}

ManejadorEmpleado::~ManejadorEmpleado(){}
