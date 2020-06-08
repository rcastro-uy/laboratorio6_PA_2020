#ifndef CONTROLADORQUITARPRODUCTO
#define CONTROLADORQUITARPRODUCTO
#include "IControladorQuitarProducto.h"


using namespace std;

class ControladorQuitarProducto: public IControladorQuitarProducto{
private:
    int mesa;
    DtProductoCantidad productoVenta;

public:
    ControladorQuitarProducto();

    list<DtProducto> listarProductos(int);
    void seleccionarProductoEliminar(DtProductoCantidad);
    void cancelarQuitarProductoVenta();
    void confirmarQuitarProductoVenta();


    ~ControladorQuitarProducto();
};

#endif