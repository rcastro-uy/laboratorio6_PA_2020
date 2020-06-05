#ifndef MANEJADORPRODUCTO
#define MANEJADORPRODUCTO
#include "Producto.h"
#include <iostream>
#include <list>

using namespace std;

class ManejadorProducto{
    private:
        static ManejadorProducto* instancia;
        ManejadorProducto();
    public:
        static ManejadorProducto* getInstancia();
        list<Producto*> getProductos();
        Producto* getProducto(string);
        void removerProducto(Producto*);
        void agregarProducto(Producto*);
        virtual ~ManejadorProducto();
};

#endif