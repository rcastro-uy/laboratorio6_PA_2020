#include "ControladorCargarDatos.h"
#include "ControladorAltaProducto.h"
#include "ControladorAgregarProducto.h"
#include "ControladorIniciarVenta.h"
#include "ManejadorMesa.h"
#include "ManejadorEmpleado.h"
#include "ManejadorVenta.h"

#include "Mozo.h"

using namespace std;

ControladorCargarDatos::ControladorCargarDatos(){};

void ControladorCargarDatos::cargarDatos(){
	ControladorAgregarProducto* conAP = new ControladorAgregarProducto();
	ControladorAltaProducto* conALTA = new ControladorAltaProducto();
	ControladorIniciarVenta* conIV = new ControladorIniciarVenta();
	
	conALTA->datosProductoComun("p01", "QUESO CREMA", 30);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p02", "RUCULA", 10);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p03", "OLIVAS NEGRAS", 20);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p04", "JAMON", 25);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p05", "FILETE", 70);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p06", "SALSA CHEDDAR", 50);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p07", "CHAMPI�ONES", 40);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p08", "HUEVO", 5);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p09", "ENSALADA MIXTA", 50);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p10", "PURE", 30);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p11", "PAPAS FRITAS", 30);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p12", "PAPAS NOISETTE", 35);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p13", "HUEVO FRITO", 15);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p14", "PANCETA", 20);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p15", "MILANESA DE CARNE", 80);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p16", "MILANESA DE POLLO", 80);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p17", "ARROZ", 10);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p18", "HELADO ARTESANAL", 100);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p19", "FLAN CON DULCE DE LECHE", 100);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p20", "BROWNIE", 100);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p21", "AGUA MINERAL", 5);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p22", "COCA-COLA", 10);
	conALTA->confirmarProductoComun();
	conALTA->datosProductoComun("p23", "REFRESCO", 10);
	conALTA->confirmarProductoComun();
	DtProductoCantidad m1pc1 = DtProductoCantidad("p02", 3);
	DtProductoCantidad m1pc2 = DtProductoCantidad("p03", 2);
	DtProductoCantidad m1pc3 = DtProductoCantidad("p04", 3);
	conALTA->datosProductoMenu("m01", "BRUSCHETA MEDITERRANEA");
	conALTA->agregarAlProductoMenu(m1pc1);
	conALTA->agregarAlProductoMenu(m1pc2);
	conALTA->agregarAlProductoMenu(m1pc3);
	conALTA->confirmarProductoMenu();
	DtProductoCantidad m2pc1 = DtProductoCantidad("p06", 1);
	DtProductoCantidad m2pc2 = DtProductoCantidad("p11", 1);
	conALTA->datosProductoMenu("m02", "FRITAS CON SALSA");
	conALTA->agregarAlProductoMenu(m2pc1);
	conALTA->agregarAlProductoMenu(m2pc2);
	conALTA->confirmarProductoMenu();
	DtProductoCantidad m3pc1 = DtProductoCantidad("p15", 2);
	DtProductoCantidad m3pc2 = DtProductoCantidad("p09", 1);
	conALTA->datosProductoMenu("m03", "MILANESA CON ENSALADA");
	conALTA->agregarAlProductoMenu(m3pc1);
	conALTA->agregarAlProductoMenu(m3pc2);
	conALTA->confirmarProductoMenu();
	DtProductoCantidad m4pc1 = DtProductoCantidad("p05", 2);
	DtProductoCantidad m4pc2 = DtProductoCantidad("p10", 1);
	conALTA->datosProductoMenu("m04", "FILETE CON PURE");
	conALTA->agregarAlProductoMenu(m4pc1);
	conALTA->agregarAlProductoMenu(m4pc2);
	conALTA->confirmarProductoMenu();
	DtProductoCantidad m5pc1 = DtProductoCantidad("p15", 2);
	DtProductoCantidad m5pc2 = DtProductoCantidad("p13", 2);
	DtProductoCantidad m5pc3 = DtProductoCantidad("p14", 2);
	DtProductoCantidad m5pc4 = DtProductoCantidad("p04", 2);
	conALTA->datosProductoMenu("m05", "KETOMILANESA");
	conALTA->agregarAlProductoMenu(m5pc1);
	conALTA->agregarAlProductoMenu(m5pc2);
	conALTA->agregarAlProductoMenu(m5pc3);
	conALTA->agregarAlProductoMenu(m5pc4);
	conALTA->confirmarProductoMenu();
	
	ManejadorMesa* mP=ManejadorMesa::getInstancia();
	Mesa* a = new Mesa(1);
	Mesa* b = new Mesa(2);
	Mesa* c = new Mesa(3);
	Mesa* d = new Mesa(4);
	Mesa* e = new Mesa(5);
	Mesa* f = new Mesa(6);
	Mesa* g = new Mesa(7);
	Mesa* h = new Mesa(8);
	Mesa* i = new Mesa(9);
	Mesa* j = new Mesa(10);
	Mesa* k = new Mesa(11);
	Mesa* l = new Mesa(12);
	Mesa* m = new Mesa(13);
	Mesa* o = new Mesa(14);
	Mesa* p = new Mesa(15);
	mP->agregarMesa(a);
	mP->agregarMesa(b);
	mP->agregarMesa(c);
	mP->agregarMesa(d);
	mP->agregarMesa(e);
	mP->agregarMesa(f);
	mP->agregarMesa(g);
	mP->agregarMesa(h);
	mP->agregarMesa(i);
	mP->agregarMesa(j);
	mP->agregarMesa(k);
	mP->agregarMesa(l);
	mP->agregarMesa(m);
	mP->agregarMesa(o);
	mP->agregarMesa(p);
	
	ManejadorEmpleado* mE = ManejadorEmpleado::getInstancia();
	Mozo* m1 = new Mozo("m1","Nicolas",mP->getMesas());
	Mozo* m2 = new Mozo("m2","Mauricio",mP->getMesas());
	Mozo* m3 = new Mozo("m3","Valentin",mP->getMesas());
	Mozo* m4 = new Mozo("m4","Rodrig",mP->getMesas());
	Mozo* m5 = new Mozo("m5","Juan",mP->getMesas());

	list<Mesa*> mdm1;
	mdm1.push_back(a);
	mdm1.push_back(b);
	mdm1.push_back(c);
	mdm1.push_back(d);
	m1->setMesas(mdm1);

	mdm1.clear();
	mdm1.push_back(e);
	mdm1.push_back(f);
	mdm1.push_back(g);
	mdm1.push_back(h);
	m2->setMesas(mdm1);

	mdm1.clear();
	mdm1.push_back(i);
	mdm1.push_back(j);
	mdm1.push_back(k);
	m3->setMesas(mdm1);

	mdm1.clear();
	mdm1.push_back(l);
	mdm1.push_back(m);
	m4->setMesas(mdm1);

	mdm1.clear();
	mdm1.push_back(o);
	mdm1.push_back(p);
	m5->setMesas(mdm1);

	mE->agregarEmpleado(m1);
	mE->agregarEmpleado(m2);
	mE->agregarEmpleado(m3);
	mE->agregarEmpleado(m4);
	mE->agregarEmpleado(m5);




	// ManejadorVenta* mV = ManejadorVenta::getInstancia();
	// Venta* v1 = new VentaLocal("vl1",m1);
	// Venta* v2 = new VentaLocal("vl2",m2);
	// Venta* v3 = new VentaLocal("vl3",m3);
	// Venta* v4 = new VentaLocal("vl4",m4);
	// Venta* v5 = new VentaLocal("vl5",m5);
	// mV->agregarVenta(v1);
	// mV->agregarVenta(v2);
	// mV->agregarVenta(v3);
	// mV->agregarVenta(v4);
	// mV->agregarVenta(v5);


	//Faltan las mesas y los mozos o empleados, y asignarles mesas...
	
	//Hay que hacer delete? IDK
	//delete conAP;
	//delete conALTA;
	//delete conIV;
}

ControladorCargarDatos::~ControladorCargarDatos(){};
