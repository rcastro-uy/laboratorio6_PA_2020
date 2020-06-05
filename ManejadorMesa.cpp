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

list<Mesa*> ManejadorMesa:: getMesas(){}

Mesa* ManejadorMesa:: getMesa(int){}

void ManejadorMesa:: removerMesa(Mesa*){}

void ManejadorMesa:: agregarMesa(Mesa*){}

ManejadorMesa::~ManejadorMesa(){}
