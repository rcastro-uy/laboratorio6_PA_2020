#ifndef PRODUCTOMENU
#define PRODUCTOMENU
#include <iostream>
#include "Comun.h"
using namespace std;

class ProductoMenu{
    private:
        int cantidad;
        Comun* comun;
    public:
        ProductoMenu();
        ProductoMenu(int);
        int getCant();
        string getCodigoComun();
        string getDescComun(); //Nic: puede servir para algo (o no), en todo caso se borra
        void asignarComun(string);
        float getPrecio();
        Comun* getComun();
        ~ProductoMenu();
};
#endif