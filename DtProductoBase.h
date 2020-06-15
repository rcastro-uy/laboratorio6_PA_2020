#ifndef DTPRODUCTOBASE
#define DTPRODUCTOBASE
#include <stdio.h>
#include <iostream>
using namespace std;

class DtProductoBase{
    private:
        string codigo;
        string descripcion;
    public:
        DtProductoBase();
        DtProductoBase(string,string);
        void setCodigo(string);
        string getCodigo();
        void setDescripcion(string);
        string getDescripcion();
        ~DtProductoBase();
        friend ostream& operator <<(ostream&,const DtProductoBase&);
};
#endif