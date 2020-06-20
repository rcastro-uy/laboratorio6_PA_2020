#ifndef DTFACTURALOCAL
#define DTFACTURALOCAL
#include "DtFechaHora.h"
#include "DtProductoFactura.h"
#include <iostream>
#include <list>

using namespace std;

class DtFacturaLocal{
    private:
        string codVenta;
        DtFechaHora fechaEmision;
        float descuento;
        list<DtProductoFactura> productos;
        float subtotal;
        float montoTotalVenta;
        float montoTotalVentaConIVA;
        string nombreMozo;
    public:
        DtFacturaLocal();
        DtFacturaLocal(string, DtFechaHora, float,list<DtProductoFactura>,float,float,float,string);
        string getCodVenta();
        void setCodVenta(string);
        DtFechaHora getFechaEmision();
        void setFechaEmision(DtFechaHora);
        float getDescuento();
        void setDescuento(float);
        list<DtProductoFactura> getProductos();
        void setProductos(list<DtProductoFactura>);
        float getSubtotal();
        void setSubtotal(float);
        float getMontoTotalVenta();
        void setMontoTotalVenta(float);
        float getMontoTotalVentaConIVA();
        void setMontoTotalVentaConIVA(float);
        string getNombreMozo();
        void setNombreMozo(string);
        ~DtFacturaLocal();
};
#endif