#ifndef CONTROLADORAGREGARPRODUCTO
#define CONTROLADORAGREGARPRODUCTO
#include "IControladorAgregarProducto.h"

using namespace std;

class ControladorAgregarProducto: public IControladorAgregarProducto{
private:
    int mesa;
    DtProductoCantidad productoVenta;

public:
    ControladorAgregarProducto();

    list<DtProductoBase> listarProductos();
    void seleccionarProducto(DtProductoCantidad&);
    void seleccionarMesa(int);
    void confirmarAgregarProductoVenta();
    void cancelarAgregarProductoVenta();


    ~ControladorAgregarProducto();
};


#endif