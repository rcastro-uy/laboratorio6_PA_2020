#include "ManejadorEmpleado.h"
#include "Empleado.h"
#include <list>
#include <map>
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

Empleado* ManejadorEmpleado:: getEmpleado(string em){
    map<string,Empleado*>::iterator it = this->empleados.find(em);
    return it->second;
}

void ManejadorEmpleado:: removerEmpleado(Empleado* em){
    map<string,Empleado*>::iterator it = this->empleados.find(em);
    this->empleados.erase(it);
}

void ManejadorEmpleado:: agregarEmpleado(Empleado* em){
    empleados.insert(std::pair<string,Empleado*>(empleados->getidEmpleado(), em));
}

ManejadorEmpleado::~ManejadorEmpleado(){}
