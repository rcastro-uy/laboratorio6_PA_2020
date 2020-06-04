#ifndef PRODUCTO
#define PRODUCTO
#include <stdio.h>
#include <iostream>
#include "tipoProducto.h"
#include "DtProductoBase.h"
using namespace std;

class Producto{
    private:
        string codigo;
        float precio;
        string descripcion;
        TipoProducto tipo;
    public:
        Producto();
        Producto(string,float,string,TipoProducto);
        void setCodigo(string);
        string getCodigo();
        void setPrecio(float);
        float getPrecio();
        void setDescripcion(string);
        string getDescripcion();
        void setTipoProducto(TipoProducto);
        TipoProducto getTipoProducto();
        DtProductoBase getDtProductoBase();
        ~Producto();
        
};
#endif