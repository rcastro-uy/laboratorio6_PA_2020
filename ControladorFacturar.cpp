#include "ControladorFacturar.h"
#include "ManejadorProducto.h"
#include "ManejadorVenta.h"
#include "ManejadorMesa.h"
#include "VentaLocal.h"
#include "Factura.h"

using namespace std;

ControladorFacturar::ControladorFacturar(){};
ControladorFacturar::~ControladorFacturar(){};


// No coinciden las definiciones con el pseudocodigo, pero mas que nada no entiendo para que se le pasa 'codVenta' a Factura.
// VentaLocal no tiene ninguna función 'setFactura' (la visibilidad no está representada) 
// -Nic-
// La factura se crea con codVenta, es el controlador el que tiene visibilidad sobre VentaLocal y Mesa. Factura tiene un getcodVenta para crear un identificador
// identico al de la VentaLocal asociada
// -Rodrigo-

DtFacturaLocal ControladorFacturar::facturar(int idMesa, float descuento){
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* me = mM->getMesa(idMesa);
    VentaLocal* v = me->getVentaLocal();
    list<DtProductoFactura> dtProductos = v->getDtProductoFactura();
    if (!dtProductos.empty()){
        float subtotal = v->getSubTotalVenta();
        string codVenta = v->getCodigo();
        Factura* f = new Factura(subtotal,dtProductos,descuento,codVenta);
        v->setFactura(f);
        string nomMozo = v->getNombreMozo();
        DtFechaHora fh = f->getFechaHora();
        cout << "El subtotal que se pasara a factura es: " << subtotal << endl;
        DtFacturaLocal dtf = DtFacturaLocal(codVenta,fh,descuento,dtProductos,subtotal,(subtotal-subtotal*(descuento/100)),(subtotal-subtotal*(descuento/100))*1.22,nomMozo);
        return dtf;
    }
    else{
        throw invalid_argument("ERROR: LA VENTA A FACTURAR NO TIENE PRODUCTOS\n");
    }
    
}