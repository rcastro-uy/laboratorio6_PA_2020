#include "ManejadorProducto.h"
#include "Producto.h"
#include <list>
#include <iostream>

using namespace std;

ManejadorProducto* ManejadorProducto:: instancia = NULL;

ManejadorProducto* ManejadorProducto:: getInstancia(){
    if (instancia == NULL) {
        instancia = new ManejadorProducto();
    }
    return instancia;
}

list<Producto*> ManejadorProducto:: getProductos(){}

Producto* ManejadorProducto:: getProducto(string){}

void ManejadorProducto:: removerProducto(Producto*){}

void ManejadorProducto:: agregarProducto(Producto*){}

ManejadorProducto::~ManejadorProducto(){}
