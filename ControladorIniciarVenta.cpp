#include "ControladorIniciarVenta.h"
#include "ManejadorEmpleado.h"
#include "ManejadorVenta.h"
#include "DtProductoCantidad.h"
#include "DtProductoBase.h"
#include "VentaLocal.h"
#include "Mozo.h"

//Al final el idMozo es 'int' o 'string'? Hay que llegar a un consenso porque sino no podemos seguir. -Nic-
/*
list<int> ControladorIniciarVenta::ingresarIDMozo(int idMozo){
    this->mozo = idMozo;
    ManejadorEmpleado* mE=ManejadorEmpleado::getInstancia();
    Mozo *mo = dynamic_cast<Mozo*>((mE->getEmpleado(idMozo)));      //idMozo es string o int?¿?¿?¿?¿?  idMozo es un string
    list<int> mesas=mo->mesasAsignadasSinVenta();
    return mesas;
}
*/
void ControladorIniciarVenta::seleccionarMesa(list<int> idMesas) {
    this->mesas = idMesas;
}
/*
void ControladorIniciarVenta::confirmarIniciarVenta(){
    ManejadorEmpleado* mE=ManejadorEmpleado::getInstancia();
    Mozo *mo = dynamic_cast<Mozo*>((mE->getEmpleado(idMozo)));      //idMozo es string o int?¿?¿?¿?¿? idMozo es un string
    VentaLocal* vl= new VentaLocal(mo);
    mo->asignarMesas(this->mesas, vl);
    ManejadorVenta* mV=ManejadorVenta::getInstancia();
    mV->agregarVenta(vl);
}
*/
void ControladorIniciarVenta::cancelarIniciarVenta(){
    this->mesas.clear();
    this->mozo.clear();
}