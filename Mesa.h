#ifndef MESA
#define MESA
#include <stdio.h>
#include <list>
#include "DtProductoCantidad.h"
#include "VentaLocal.h"
#include "DtProductoCantidad.h"
using namespace std;

class Mozo;
class VentaLocal;
class Mesa{
    private:
        int numero;
        VentaLocal* ventaLocal;
    public:
        Mesa();
        Mesa(int);
        int getNumero();
        void setNumero(int);
        VentaLocal* getVentaLocal();
        void setVentaLocal(VentaLocal*);
        bool tieneVenta();
        void agregarProducto(DtProductoCantidad);
        list<DtProducto> listarProductos();
        void quitarProducto(DtProductoCantidad);
        ~Mesa();
        
};
#endif