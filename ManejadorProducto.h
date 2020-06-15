#ifndef MANEJADORPRODUCTO
#define MANEJADORPRODUCTO
#include "Producto.h"
#include <iostream>
#include <list>
#include <map>

using namespace std;

class ManejadorProducto{
    private:
        static ManejadorProducto* instancia;
        map<string,Producto*> productos;
        ManejadorProducto();
    public:
        static ManejadorProducto* getInstancia();
        list<Producto*> getProductos();
        Producto* getProducto(string);
        void removerProducto(Producto*);
        void agregarProducto(Producto*);
        bool existeProducto(string);
        virtual ~ManejadorProducto();
};

#endif