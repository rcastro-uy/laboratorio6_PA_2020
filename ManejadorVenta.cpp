#include "ManejadorVenta.h"
#include "Venta.h"
#include <list>
#include <iostream>

using namespace std;

ManejadorVenta* ManejadorVenta:: instancia = NULL;

ManejadorVenta::ManejadorVenta(){}

ManejadorVenta* ManejadorVenta:: getInstancia(){
    if (instancia == NULL) {
        instancia = new ManejadorVenta();
    }
    return instancia;
}

list<Venta*> ManejadorVenta:: getVentas(){
    list<Venta*> lstVentas;
    for (map<string,Venta*>::iterator it=this->ventas.begin();it!=ventas.end(); ++it){
        lstVentas.push_back(it->second);
    }
    return lstVentas;
}

Venta* ManejadorVenta:: getVenta(string v){
    map<string,Venta*>::iterator it = this->ventas.find(v);
    return it->second;
}

void ManejadorVenta:: removerVenta(Venta* v){
    map<string,Venta*>::iterator it = this->ventas.find(v->getCodigo());
    this->ventas.erase(it);
}

void ManejadorVenta:: agregarVenta(Venta* v){
    ventas.insert(std::pair<string,Venta*>(v->getCodigo(), v));
}

ManejadorVenta::~ManejadorVenta(){}
