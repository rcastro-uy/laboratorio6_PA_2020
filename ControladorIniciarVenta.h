#ifndef CONTROLADORINICIARVENTA
#define CONTROLADORINICIARVENTA
#include "iostream"
#include "string"
#include "list"

using namespace std;

class ControladorIniciarVenta
{
private:
    string mozo;
    int mesa;

public:
    ControladorIniciarVenta();

    void setIngresarIDMozo(int);
    void setSeleccionarMesa(int);
    void confirmarIniciarVenta();
    void cancelarIniciarVenta();

    ~ControladorIniciarVenta();
};

#endif

