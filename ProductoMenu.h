#ifndef PRODUCTOMENU
#define PRODUCTOMENU
#include <iostream>
using namespace std;

class ProductoMenu{
    private:
        int cantidad;
    public:
        ProductoMenu();
        ProductoMenu(int);
        int getCant();
        string getCodigoComun();
        void asignarComun(string);
        float getPrecio();
        ~ProductoMenu();
};
#endif