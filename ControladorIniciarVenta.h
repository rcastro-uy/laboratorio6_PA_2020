#ifndef CONTROLADORINICIARVENTA
#define CONTROLADORINICIARVENTA
#include "IControladorIniciarVenta.h"

using namespace std;

class ControladorIniciarVenta: public IControladorIniciarVenta{
private:
    string mozo;
    int mesa;

public:
    ControladorIniciarVenta();

    list<int> setIngresarIDMozo(int);
    void setSeleccionarMesa(list<int>);
    void confirmarIniciarVenta();
    void cancelarIniciarVenta();

    ~ControladorIniciarVenta();
};

#endif

