#include "ManejadorVenta.h"
#include "Venta.h"
#include <list>
#include <iostream>

using namespace std;

ManejadorVenta* ManejadorVenta:: instancia = NULL;

ManejadorVenta* ManejadorVenta:: getInstancia(){
    if (instancia == NULL) {
        instancia = new ManejadorVenta();
    }
    return instancia;
}

list<Empleado*> ManejadorVenta:: getEmpleados(){}

Empleado* ManejadorVenta:: getEmpleado(string){}

void ManejadorVenta:: removerEmpleado(Empleado*){}

void ManejadorVenta:: agregarEmpleado(Empleado*){}

ManejadorVenta::~ManejadorVenta(){}
