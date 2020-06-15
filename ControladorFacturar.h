#ifndef CONTROLADORFACTURAR
#define CONTROLADORFACTURAR
#include "IControladorFacturar.h"
#include <list>

using namespace std;

class ControladorFacturar: public IControladorFacturar{
    public:
        ControladorFacturar();
        DtFacturaLocal facturar(int, float);
        ~ControladorFacturar();
};

#endif