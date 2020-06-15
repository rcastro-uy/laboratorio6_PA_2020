#ifndef CONTROLADORBAJAPRODUCTO
#define CONTROLADORBAJAPRODUCTO
#include "IControladorBajaProducto.h"
#include <list>

using namespace std;

class ControladorBajaProducto: public IControladorBajaProducto{
private:
    string codigo;

public:
    ControladorBajaProducto();
    void eliminarProducto();
    list<DtProductoBase> listarProductos();
    void seleccionarProducto(string); 
    void cancelarBajaProducto(); 

    ~ControladorBajaProducto();
};

#endif
