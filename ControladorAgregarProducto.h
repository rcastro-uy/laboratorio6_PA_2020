#ifndef CONTROLADORAGREGARPRODUCTO
#define CONTROLADORAGREGARPRODUCTO
#include "iostream"
#include "string"
#include "list"

using namespace std;

class ControladorAgregarProducto
{
private:
    int mesa;
    DtProductoCantidad productoVenta;

public:
    ControladorAgregarProducto();

    list<DtProductoBase> listarProductos();
    void seleccionarProducto();
    void seleccionarMesa(int);
    void confirmarAgregarProductoVenta();


    ~ControladorAgregarProducto();
};


