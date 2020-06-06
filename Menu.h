#ifndef MENU
#define MENU
#include "Producto.h"
#include "Comun.h"
#include "DtProducto.h"
#include <list>
using namespace std;

class Menu: public Producto{
    public:
        int cantComunes;

        Menu();
        Menu(string,float,string,int);
        void setCantComunes(int);
        int getCantComunes();
        TipoProducto getTipoProducto();
        int eliminarComun(Comun,string);
        void decrementarCantComunes(int);
        void agregarComunes(list<DtProducto>);
        void calcularPrecio();
        void incrementarPrecio(float);
        void aplicarDescuento();
        void incrementarCantComunes(int);
        ~Menu();
};
#endif