#include "ControladorIniciarVenta.h"
#include "ManejadorEmpleado.h"
#include "ManejadorVenta.h"
#include "ManejadorMesa.h"
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
    ManejadorVenta* mV=ManejadorVenta::getInstancia();
    string codVenta = to_string(mV->getUniqueCodVenta());
    VentaLocal* vl=new VentaLocal(codVenta,mo);
    mV->agregarVenta(vl);
    mo->asignarMesas(this->mesas, vl);     
}

void ControladorIniciarVenta::cancelarIniciarVenta(){
    this->mesas.clear();
    this->mozo.clear();
}

bool ControladorIniciarVenta::mesaEsDeMozo(int idMesa,string idMozo){
    ManejadorEmpleado* mE=ManejadorEmpleado::getInstancia();
    Mozo *mo = dynamic_cast<Mozo*>((mE->getEmpleado(idMozo)));
    list<Mesa*> mesasMozo = mo->getMesas();
    list<Mesa*>::iterator it = mesasMozo.begin();
    bool encontro=false;
    while ((!encontro)||(it != mesasMozo.end())){
        if((*it)->getNumero() == idMesa){
            encontro = true;
        }else{
            it++;
        }  
    }
    return encontro;
}
