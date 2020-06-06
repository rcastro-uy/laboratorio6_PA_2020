#ifndef PRODUCTO
#define PRODUCTO
#include <stdio.h>
#include "TipoProducto.h"
#include "DtProductoBase.h"
using namespace std;

class Producto{
    private:
        string codigo;
        float precio;
        string descripcion;
    public:
        Producto();
        Producto(string,float,string);
        void setCodigo(string);
        string getCodigo();
        void setPrecio(float);
        float getPrecio();
        void setDescripcion(string);
        string getDescripcion();
        ~Producto();
    
        DtProductoBase getDtProductoBase();
        virtual TipoProducto getTipoProducto()=0;
        
};
#endif