#ifndef CONTROLADORALTAPRODUCTO
#define CONTROLADORALTAPRODUCTO
#include "IControladorAltaProducto.h"


using namespace std;

class ControladorAltaProducto: public IControladorAltaProducto{
    private:
        string codMenu;
        string descMenu;
        list<DtProductoCantidad> ProductoComun;
        string codComun;
        string descComun;
        float precioComun;    
        
    public:
        ControladorAltaProducto();
        list<DtProductoBase> listarProductos();
        list<DtProductoBase> listarProductosComunes();
        list<DtProductoBase> listarProductosMenu();
        void datosProductoComun(string, string, float);
        void confirmarProductoComun();
        void cancelarProductoComun();
        void datosProductoMenu(string, string);
        void agregarAlProductoMenu(DtProductoCantidad);
        void confirmarProductoMenu();
        void cancelarProductoMenu();
        bool existeProducto(string);
        DtProducto detallesProducto(string);



        ~ControladorAltaProducto();
};


#endif
