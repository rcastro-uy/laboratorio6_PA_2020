#include "DtProductoComun.h"

DtProductoComun::DtProductoComun(){}
DtProductoComun::DtProductoComun(string codigo,string desc,float precio,int cant):DtProducto(codigo, desc,precio,cant){}

ostream& operator <<(ostream& salida,const DtProductoComun& dtpb){
	cout << (DtProducto)dtpb << endl;
    return salida;
}

DtProductoComun::~DtProductoComun(){}