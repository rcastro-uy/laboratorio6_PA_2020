#ifndef CONTROLADORINICIARVENTA
#define CONTROLADORINICIARVENTA
#include "IControladorIniciarVenta.h"

using namespace std;

class ControladorIniciarVenta: public IControladorIniciarVenta{
private:
    string mozo;
    list<int> mesas;

public:
    ControladorIniciarVenta();

    list<int> ingresarIDMozo(int);
    void seleccionarMesa(list<int>);
    void confirmarIniciarVenta();
    void cancelarIniciarVenta();

    ~ControladorIniciarVenta();
};

#endif

