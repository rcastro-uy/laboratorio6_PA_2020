#ifndef DTPRODUCTO
#define DTPRODUCTO
#include "DtProductoBase.h"
#include <iostream>
using namespace std;

class DtProducto: public DtProductoBase{
    private:
        float precio;
        int cantidad;
        
    public:
        DtProducto();
        DtProducto(string,string,float,int);
        void setPrecio(float);
        float getPrecio();
        void setCantidad(int);
        int getCantidad();
        virtual ~DtProducto();
        friend ostream& operator <<(ostream&,const DtProducto&);
};
#endif