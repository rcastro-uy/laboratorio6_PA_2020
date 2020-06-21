#ifndef ICONTROLADORINICIARVENTA
#define ICONTROLADORINICIARVENTA
#include <iostream>
#include <list>

using namespace std;

class IControladorIniciarVenta{
    
    public:
        virtual list<int> ingresarIdMozo(string) = 0;
        virtual void seleccionarMesa(list<int>) = 0;
        virtual void confirmarIniciarVenta() = 0;
        virtual void cancelarIniciarVenta() = 0;
};

#endif

