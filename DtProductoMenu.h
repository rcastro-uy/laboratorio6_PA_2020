#ifndef DTPRODUCTOMENU
#define DTPRODUCTOMENU
#include "DtProducto.h"
#include "DtProductoComun.h"
#include <iostream>
#include <list>
using namespace std;

class DtProductoMenu: public DtProducto{
    private:
    list<DtProductoComun*> productos;
    public:
    DtProductoMenu();
    DtProductoMenu(string,string,float,int,list<DtProductoComun*>);
    virtual ~DtProductoMenu();
    list<DtProductoComun*> getProductos();
    void setProductos(list<DtProductoComun*>);
    friend ostream& operator <<(ostream&,const DtProductoMenu&);
};

#endif