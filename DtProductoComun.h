#ifndef DTPRODUCTOCOMUN
#define DTPRODUCTOCOMUN
#include "DtProducto.h"
#include <iostream>
using namespace std;

class DtProductoComun: public DtProducto{
    public:
    DtProductoComun();
    DtProductoComun(string,string,float,int);
    virtual ~DtProductoComun();
    
};
#endif