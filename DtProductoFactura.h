#ifndef DTPRODUCTOFACTURA
#define DTPRODUCTOFACTURA
#include <iostream>

using namespace std;

class DtProductoFactura{
    private:
        string descripcion;
        float precio;
        int cantidad;
    public:
        DtProductoFactura();
        DtProductoFactura(string,float,int);
        string getDescripcion();
        void setDescripcion(string);
        float getPrecio();
        void setPrecio(float);
        int getCantidad();
        void setCantidad(int);
        ~DtProductoFactura();
        friend ostream& operator <<(ostream&,const DtProductoFactura&);
};

#endif