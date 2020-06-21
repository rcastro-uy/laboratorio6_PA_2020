#ifndef MANEJADORMESA
#define MANEJADORMESA
#include "Mesa.h"
#include <iostream>
#include <list>
#include <map>

using namespace std;

class ManejadorMesa{
    private:
        static ManejadorMesa* instancia;
        map<int,Mesa*> mesas;
        ManejadorMesa();
    public:
        static ManejadorMesa* getInstancia();
        list<Mesa*> getMesas();
        Mesa* getMesa(int);
        void removerMesa(Mesa*);
        void agregarMesa(Mesa*);
        bool mesaTieneVenta(int idMesa);
        virtual ~ManejadorMesa();
        
};

#endif