#include "ControladorIniciarVenta.h"
#include "ManejadorEmpleado.h"
#include "ManejadorVenta.h"
#include "DtProductoCantidad.h"
#include "DtProductoBase.h"
#include "VentaLocal.h"
#include "Mozo.h"

ControladorIniciarVenta::ControladorIniciarVenta(){};
ControladorIniciarVenta::~ControladorIniciarVenta(){};

list<int> ControladorIniciarVenta::ingresarIdMozo(string idMozo){
     this->mozo = idMozo;
     ManejadorEmpleado* mE=ManejadorEmpleado::getInstancia();
     Mozo *mo = dynamic_cast<Mozo*>((mE->getEmpleado(idMozo)));
     list<int> mesas=mo->mesasAsignadasSinVenta();
     return mesas;
}

void ControladorIniciarVenta::seleccionarMesa(list<int> idMesas) {
    this->mesas = idMesas;
}

void ControladorIniciarVenta::confirmarIniciarVenta(){
     ManejadorEmpleado* mE=ManejadorEmpleado::getInstancia();
     Mozo *mo = dynamic_cast<Mozo*>((mE->getEmpleado(this->mozo)));

    // VentaLocal* vl= new VentaLocal(mo);
    list<VentaProducto*> ventasp;
    VentaLocal* vl=new VentaLocal(mo->getNombre(),ventasp);

    // mo->asignarMesas(this->mesas, vl);
     ManejadorVenta* mV=ManejadorVenta::getInstancia();
     mV->agregarVenta(vl);
}

void ControladorIniciarVenta::cancelarIniciarVenta(){
    this->mesas.clear();
    this->mozo.clear();
}
