#include "ControladorIniciarVenta.h"
#include "ManejadorEmpleado.h"
#include "ManejadorVenta.h"
#include "DtProductoCantidad.h"
#include "DtProductoBase.h"
#include "VentaLocal.h"
#include "Mozo.h"

list<int> ControladorIniciarVenta::ingresarIDMozo(int idMozo){
    this->mozo = idMozo;
    ManejadorEmpleado* mE=ManejadorEmpleado::getInstancia();
    Mozo *mo = dynamic_cast<Mozo*>((mE->getEmpleado(idMozo)));      //idMozo es string o int?¿?¿?¿?¿?
    list<int> mesas=mo->mesasAsignadasSinVenta();
    return mesas;
}
void ControladorIniciarVenta::seleccionarMesa(list<int> idMesas) {
    this->mesas = idMesas;
}
void ControladorIniciarVenta::confirmarIniciarVenta(){
    ManejadorEmpleado* mE=ManejadorEmpleado::getInstancia();
    Mozo *mo = dynamic_cast<Mozo*>((mE->getEmpleado(idMozo)));      //idMozo es string o int?¿?¿?¿?¿?
    VentaLocal* vl= new VentaLocal(mo);
    mo->asignarMesas(this->mesas, vl);
    ManejadorVenta* mV=ManejadorVenta::getInstancia();
    mV->agregarVenta(vl);
}
void ControladorIniciarVenta::cancelarIniciarVenta(){
    this->mesas.clear();
    this->mozo.clear();
}