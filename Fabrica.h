#ifndef FABRICA
#define FABRICA
#include "IControladorAltaProducto.h"
#include "IControladorAgregarProducto.h"
#include "IControladorBajaProducto.h"
#include "IControladorQuitarProducto.h"
#include "IControladorIniciarVenta.h"
#include "IControladorFacturar.h"
class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        IControladorAltaProducto* getIControladorAltaProducto();
        IControladorBajaProducto* getIControladorBajaProducto();
        IControladorAgregarProducto* getIControladorAgregarProducto();
        IControladorQuitarProducto* getIControladorQuitarProducto();
        IControladorIniciarVenta* getIControladorIniciarVenta();
        IControladorFacturar* getIControladorFacturar();
        ~Fabrica();
};
#endif
