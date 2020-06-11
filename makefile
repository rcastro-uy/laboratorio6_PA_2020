main: comun.o ControladorAgregarProducto.o ControladorAltaProducto.o ControladorBajaProducto.o ControladorIniciarVenta.o ControladorQuitarProducto.o DtFacturaLocal.o DtFecha.o DtFechaHora.o DtProducto.o DtProductoBase.o DtProductoCantidad.o DtProductoFactura.o Empleado.o Fabrica.o Factura.o IControladorAgregarProducto.o  IcontroladorAltaProducto.o IControladorBajaProduco.o IcontroladorFactura.o IControladorIniciarVenta.o IControladorQuitarProducto.o ManejadorEmpleado.o ManejadorMesa.o ManejadorProducto.o ManejadorVenta.o Menu.o Mesa.o Mozo.o Producto.o ProductoMenu.o Venta.o VentaLocal.o VentaProducto.o main.o
	g++ comun.o ControladorAgregarProducto.o ControladorAltaProducto.o ControladorBajaProducto.o ControladorIniciarVenta.o ControladorQuitarProducto.o DtFacturaLocal.o DtFecha.o DtFechaHora.o DtProducto.o DtProductoBase.o DtProductoCantidad.o DtProductoFactura.o Empleado.o Fabrica.o Factura.o IControladorAgregarProducto.o IControladorAltaProducto.o IControladorBajaProduco.o IcontroladorFactura.o IControladorIniciarVenta.o IControladorQuitarProducto.o ManejadorEmpleado.o ManejadorMesa.o ManejadorProducto.o ManejadorVenta.o Menu.o Mesa.o Mozo.o Producto.o ProductoMenu.o Venta.o VentaLocal.o VentaProducto.o main.o -o labo

comun.o: Comun.cpp

ControladorAgregarProducto.o: ControladorAgregarProducto.cpp

ControladorAltaProducto.o: ControladorAltaProducto.cpp

ControladorBajaProducto.o: ControladorBajaProducto.cpp

ControladorIniciarVenta.o: ControladorIniciarVenta.cpp

ControladorQuitarProducto.o: ControladorQuitarProducto.cpp

DtFacturaLocal.o: DtFacturaLocal.cpp

DtFecha.o: DtFecha.cpp

DtFechaHora.o: DtFechaHora.cpp

DtProducto.o: DtProducto.cpp

DtProductoBase.o: DtProductoBase.cpp

DtProductoCantidad.o: DtProductoCantidad.cpp

DtProductoFactura.o: DtProductoFactura.cpp

Empleado.o: Empleado.cpp

Fabrica.o: Fabrica.cpp

Factura.o: Factura.cpp

IControladorAgregarProducto.o: IControladorAgregarProducto.cpp

IcontroladorAltaProducto.o: IcontroladorAltaProducto.cpp

IControladorBajaProduco.o: IControladorBajaProduco.cpp

IcontroladorFactura.o: IcontroladorFactura.cpp

IControladorIniciarVenta.o: IControladorIniciarVenta.cpp

IControladorQuitarProducto.o: IControladorQuitarProducto.cpp

ManejadorEmpleado.o: ManejadorEmpleado.cpp

ManejadorMesa.o: ManejadorMesa.cpp

ManejadorProducto.o: ManejadorProducto.cpp

ManejadorVenta.o: ManejadorVenta.cpp

Menu.o: Menu.cpp

Mesa.o: Mesa.cpp

Mozo.o: Mozo.cpp

Producto.o: Producto.cpp

ProductoMenu.o: ProductoMenu.cpp

Venta.o: Venta.cpp

VentaLocal.o: VentaLocal.cpp

VentaProducto.o: VentaProducto.cpp


main.o: main.cpp

clean:
	rm -rf *.o labo