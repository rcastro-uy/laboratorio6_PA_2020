#ifndef CONTROLADORQUITARPRODUCTO
#define CONTROLADORQUITARPRODUCTO
#include "iostream"
#include "string"
#include <list>
#include "DtProducto.h"
#include "DtProductoCantidad.h"


using namespace std;

class ControladorQuitarProducto
{
private:
    int mesa;
    DtProductoCantidad productoVenta;

public:
    ControladorQuitarProducto();

    list<DtProducto*> listarProductos(int);
    void seleccionarProductoEliminar();
    void cancelarQuitarProductoVenta();
    void confirmarQuitarProductoVenta();


    ~ControladorQuitarProducto();
};

#endif