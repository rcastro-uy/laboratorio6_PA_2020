#ifndef MANEJADORMESA
#define MANEJADORMESA
#include "Mesa.h"
#include <iostream>
#include <list>

using namespace std;

class ManejadorMesa{
    private:
        static ManejadorMesa* instancia;
        list<Mesa*> mesas;
        ManejadorMesa();
    public:
        static ManejadorMesa* getInstancia();
        list<Mesa*> getMesas();
        Mesa* getMesa(int);
        void removerMesa(Mesa*);
        void agregarMesa(Mesa*);
        virtual ~ManejadorMesa();
};

#endif