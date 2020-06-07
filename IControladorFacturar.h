#ifndef ICONTROLADORFACTURAR
#define ICONTROLADORFACTURAR
#include <iostream>
#include "DtFacturaLocal.h"

using namespace std;

class IControladorFacturar{

    public:
        virtual DtFacturaLocal facturar(int, float) = 0;
};

#endif