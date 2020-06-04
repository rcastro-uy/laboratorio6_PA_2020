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

list<Empleado*> ManejadorEmpleado:: getEmpleados(){}

Empleado* ManejadorEmpleado:: getEmpleado(string){}

void ManejadorEmpleado:: removerEmpleado(Empleado*){}

void ManejadorEmpleado:: agregarEmpleado(Empleado*){}

ManejadorEmpleado::~ManejadorEmpleado(){}
