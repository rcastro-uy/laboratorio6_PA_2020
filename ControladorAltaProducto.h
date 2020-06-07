#ifndef CONTROLADORALTAPRODUCTO
#define CONTROLADORALTAPRODUCTO
#include "iostream"
#include "string"
#include <list>
#include "DtProductoBase.h"
#include "DtProductoCantidad.h"

using namespace std;

class ControladorAltaProducto{
    private:
        string codMenu;
        string descMenu;
        list<DtProductoCantidad*> ProductoComun;
        string codComun;
        string descComun;
        float precioComun;    
        
    public:
        ControladorAltaProducto();
        list<DtProductoBase*> listarProductos();
        void datosProductoComun(string, string, string);
        void confirmarProductoComun();
        void cancelarProductoComun();
        void datosProductoMenu(string, string);
        void agregarAlProductoMenu(DtProductoCantidad*);
        void confirmarProductoMenu();
        void cancelarProductoMenu();



        ~ControladorAltaProducto();
};


#endif
