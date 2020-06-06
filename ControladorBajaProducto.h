#ifndef CONTROLADORBAJAPRODUCTO
#define CONTROLADORBAJAPRODUCTO
#include "iostream"
#include "string"
#include "list"

using namespace std;

class ControladorBajaProducto
{
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
