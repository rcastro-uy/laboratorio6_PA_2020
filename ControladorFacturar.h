#ifndef CONTROLADORFACTURAR
#define CONTROLADORFACTURAR
#include "IControladorFacturar.h"

using namespace std;

class ControladorFacturar: public IControladorFacturar{
    public:
        DtFacturaLocal facturar(int, float);
};

#endif