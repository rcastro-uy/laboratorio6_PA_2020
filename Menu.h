#ifndef MEN
#define MEN
#include "Producto.h"
#include "ProductoMenu.h"
#include "DtProductoCantidad.h"
#include <list>
using namespace std;

class Menu: public Producto{
    private:
        list<ProductoMenu*> listaProductos;
    public:
        int cantComunes;

        Menu();
        Menu(string,float,string,int);
        void setCantComunes(int);
        int getCantComunes();
        TipoProducto getTipoProducto();
        int eliminarComun(string);
        void decrementarCantComunes(int);
        void agregarComunes(list<DtProductoCantidad>);
        void calcularPrecio();
        void incrementarPrecio(float);
        void aplicarDescuento();
        void incrementarCantComunes(int);
        ~Menu();
};
#endif