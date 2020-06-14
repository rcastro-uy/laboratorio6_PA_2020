#include "ControladorFacturar.h"
#include "ManejadorProducto.h"
#include "ManejadorVenta.h"
#include "ManejadorMesa.h"
#include "VentaLocal.h"
#include "Factura.h"

using namespace std;

/*
No coinciden las definiciones con el pseudocodigo, pero mas que nada no entiendo para que se le pasa 'codVenta' a Factura.
VentaLocal no tiene ninguna función 'setFactura' (la visibilidad no está representada) 
-Nic-
La factura se crea con codVenta, es el controlador el que tiene visibilidad sobre VentaLocal y Mesa. Factura tiene un getcodVenta para crear un identificador
identico al de la VentaLocal asociada
-Rodrigo-

DtFacturaLocal ControladorFacturar::facturar(int idMesa, float descuento){
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* me = mM->getMesa(idMesa);
    VentaLocal* v = me->getVentaLocal();
    list<DtProducto> dtProductos = v->getDtProductoFactura();
    float subtotal = v->getSubTotalVenta();
    Factura* f = new Factura(subtotal,dtProductos,descuento);
    v->setFactura(f);
    string nomMozo = v->getNombreMozo();
    string cod = f->getCodVenta();
    DtFechaHora fh = f->getFechaHora();
    DtFacturaLocal dtf = DtFacturaLocal(cod,fh,descuento,dtProductos,subtotal,subtotal*(1-descuento),subtotal*(1-descuento)*1.22,nomMozo);
}
*/