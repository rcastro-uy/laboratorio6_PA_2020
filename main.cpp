#include "Fabrica.h"
#include "IControladorAgregarProducto.h"
#include "IControladorQuitarProducto.h"
#include "IControladorAltaProducto.h"
#include "IControladorBajaProducto.h"
#include "IControladorIniciarVenta.h"
#include "tipoProducto.h"
#include "IControladorFacturar.h"
//#include "IControladorCargarDatos.h"
Fabrica* fabrica;
IControladorAgregarProducto* iconAP;
IControladorQuitarProducto* iconQP;
IControladorAltaProducto* iconALTAP;
IControladorBajaProducto* iconBAJAP;
IControladorIniciarVenta* iconIV;
IControladorFacturar* iconF;
//IControladorCargarDatos* iconDATOS;

void altaProducto();
void ingresarComun();
void ingresarMenu();
bool existeProductoBase(string, list<DtProductoBase>&);
void imprimirListaProductos(list<DtProductoBase>);  //pruebas --> implementar directamente, no como funcion

void iniciarVenta();

void agregarProductoAUnaVenta();

void quitarProductoAUnaVenta();
bool existeProducto(string, list<DtProducto>&);

void facturar();

void bajaProducto();

void cargarDatos(); //pruebas y final

void menu();

//CU ALTA PRODUCTO
//Faltan excepciones para cuando ya existe el producto con el codigo que el usuario esta ingresando (Alta).
void altaProducto(){
    system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______A L T A__D E__P R O D U C T O_______"<< endl;
    int opcion, opAceptar, opContinua;
	string cod, desc;
	float precio;

    bool hayComun;
    list<DtProductoBase> lstDTPB;

    lstDTPB = iconALTAP->listarProductos();
    hayComun = (lstDTPB.empty()==false);
    do{
        if (hayComun){
            cout <<"1. Dar de Alta un Producto"<<endl;
            cout <<"2. Dar de Alta un Menu"<<endl;
            cout <<"3. Terminar"<<endl;
            cin >> opcion;

            if(opcion==1){
				ingresarComun();
			}else if(opcion==2){
				ingresarMenu();
			}else{
                cout <<"ATENCION: Opción incorrecta. Intente nuevamente:"<<endl;
			}
			
        }else{ //NO HAY NINGUN PRODUCTO COMUN
            cout <<"1. Dar de Alta un Producto"<<endl;
            cout <<"2. Terminar"<<endl;
			cin >> opcion;
            if(opcion==1){
				ingresarComun();
			}else{
                cout <<"ATENCION: Opción incorrecta. Intente nuevamente:"<<endl;
			}
        }
    } while ((hayComun && opcion != 3) || (!hayComun && opcion != 2));
};

void ingresarComun(){
	int opcion;
	string cod, desc;
	float precio;
	
	cout << "Ingrese un Identificador único para el producto Común: ";
	cin >> cod;
	cout << "Ingrese el Precio para el producto Común: ";
	cin >> precio;
	cout << "Ingrese una Descripción para el producto Común: ";
	cin >> desc;
	iconALTAP->datosProductoComun(cod, desc, precio);

	cout <<"1. Confirmar Producto"<<endl;
	cout <<"2. Cancelar Alta"<<endl;
	cin >> opcion;
	switch (opcion){
		case 1:
			iconALTAP->confirmarProductoComun();
		break;
		case 2:
			iconALTAP->cancelarProductoComun();
		break;
		default:
			cout <<"ATENCION: Opción incorrecta. Intente nuevamente:"<<endl;
		break;
	}
}

void ingresarMenu(){
	int opcion, cant;
	string cod, codComun, desc;
	list<DtProductoBase> lstDTPB;
	DtProductoCantidad dtPCComun;
	bool existe;

	//PARTE datos de menu
	cout << "Ingrese un Identificador único para el Menú: ";
	cin >> cod;
	cout << "Ingrese una Descripción para el Menú: ";
	cin >> desc;
	iconALTAP->datosProductoMenu(cod, desc);

	//PARTE lista productos
	lstDTPB = iconALTAP->listarProductos();
	imprimirListaProductos(lstDTPB);

	//PARTE agrega comunes al menu
	opcion = 1;	//para entrar al wihle 
	while (opcion != 2){
		cout <<"1. Ingresar un Producto al Menú"<<endl;
		cout <<"2. Finalizar ingreso de productos"<<endl;
		cin >> opcion;
		switch (opcion){
			case 1:
				cout << "Ingrese el Identificador del Producto (solamente Común) a agregar: ";
				cin >> codComun;
				existe = existeProductoBase(codComun, lstDTPB);
				if (existe){
					cout << "Ingrese la cantidad: ";
					cin >> cant;
					dtPCComun.setCodigo(codComun);
					dtPCComun.setCantidad(cant);
					iconALTAP->agregarAlProductoMenu(dtPCComun);
				}else{
					cout << "ATENCION: Ese producto no existe.";
				}
			case 2:
			break;
			default:
				cout <<"ATENCION: Opción incorrecta. Intente nuevamente:"<<endl;
			break;
		}
	}

	//PARTE aceptar/cancelar
	cout <<"1. Confirmar Menu"<<endl;
	cout <<"2. Cancelar Alta"<<endl;
	cin >> opcion;
	switch (opcion){
		case 1:
			iconALTAP->confirmarProductoMenu();
		break;
		case 2:
			iconALTAP->cancelarProductoMenu();
		break;
		default:
			cout << "ATENCION: Opción incorrecta. Intente nuevamente:" << endl;
		break;
	}
}

bool existeProductoBase(string cod, list<DtProductoBase>& listProd){
	bool encontre = false;
	for (list<DtProductoBase>::iterator it=listProd.begin(); it != listProd.end(); it++){
		if (!encontre)	//mientras no coincidan los codigos con la lista de productos
			encontre = (cod == it->getCodigo());
	}
	return encontre;
}

void imprimirListaProductos(list<DtProductoBase> lProd){
	// for (list<DtProductoBase>::iterator it=lProd.begin(); it != lProd.end(); it++){
	// 	cout << *it << endl;
	// }
}




//CU AGREGAR PRODUCTO A UNA VENTA
//Faltan excepciones para cuando la Venta asociada a esa Mesa ya fue Facturada
void agregarProductoAUnaVenta(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______A G R E G A R__P R O D U C T O__A__U N A__V E N T A______"<< endl;
    int opcion, mesa, cant;
	string cod;

	DtProductoCantidad dtPC;
	bool existe;
    list<DtProductoBase> lstDTPB;

	cout << "Ingrese un Identificador de Mesa: ";
	cin >> mesa;
	lstDTPB = iconAP->listarProductos();
	for (list<DtProductoBase>::iterator it = lstDTPB.begin(); it != lstDTPB.end(); it++){
		//cout << (*it) << endl;
	}

	opcion = 1;	//para entrar al wihle 
	while (opcion != 2){
		cout <<"1. Ingresar un Producto a la Venta"<<endl;
		cout <<"2. Finalizar ingreso de productos"<<endl;
		cin >> opcion;
		switch (opcion){
			case 1:
				cout << "Ingrese el Identificador del Producto a agregar: ";
				cin >> cod;
				existe = existeProductoBase(cod, lstDTPB);
				if (existe){
					cout << "Ingrese la cantidad: ";
					cin >> cant;
					dtPC.setCodigo(cod);
					dtPC.setCantidad(cant);
					iconAP->seleccionarProducto(dtPC);
				}else{
					cout << "ATENCION: Ese producto no existe.";
				}
			case 2:
			break;
			default:
				cout <<"ATENCION: Opción incorrecta. Intente nuevamente:"<<endl;
			break;
		}
	}

	//PARTE aceptar/cancelar
	cout <<"1. Confirmar Venta de Producto"<<endl;
	cout <<"2. Cancelar Venta de Producto"<<endl;
	cin >> opcion;
	switch (opcion){
		case 1:
			iconAP->confirmarAgregarProductoVenta();
		break;
		case 2:
			iconAP->cancelarAgregarProductoVenta();
		break;
		default:
			cout << "ATENCION: Opción incorrecta. Intente nuevamente:" << endl;
		break;
	}
};




//CU INICIAR VENTA EN MESA
//Falta excepcion para cuando la/s mesa/s ingresada/s por el usuario ya tienen una venta iniciada
//No hay que controlar que el mozo exista porque ya viene cargado.
//Supongo que controlar que el usuario ingrese las mesas que el mozo tiene asignadas se controla acá... no lo tengo claro
void iniciarVenta(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______I N I C I A R__V E N T A__E N__M E S A S______"<< endl;
    int opcion, mozo, mesa;
	list<int> mesasSinVentaDeMozo;
	list<int> mesasSelected;
	bool existe;

	cout << "Ingrese un Identificador de Mozo: ";
	cin >> mozo;
	mesasSinVentaDeMozo = iconIV->ingresarIDMozo(mozo);

	opcion = 0;	//para entrar al wail
	while (opcion != 2){
		cout <<"1. Ingresar una Mesa para iniciar su Venta"<<endl;
		cout <<"2. Finalizar ingreso de Mesas"<<endl;
		cin >> opcion;
		switch (opcion){
			case 1:
				cout << "Ingrese el Identificador de la Mesa a agregar: ";
				cin >> mesa;
				mesasSelected.push_back(mesa);
			case 2:
			break;
			default:
				cout <<"ATENCION: Opción incorrecta. Intente nuevamente:"<<endl;
			break;
		}
	}
	if (mesasSelected.empty() == false){
		iconIV->seleccionarMesa(mesasSelected);

		//PARTE aceptar/cancelar
		cout <<"1. Confirmar Inicio de Venta"<<endl;
		cout <<"2. Cancelar Inicio de Venta"<<endl;
		cin >> opcion;
		switch (opcion){
			case 1:
				iconIV->confirmarIniciarVenta();
			break;
			case 2:
				iconIV->cancelarIniciarVenta();
			break;
			default:
				cout << "ATENCION: Opción incorrecta. Intente nuevamente:" << endl;
			break;
		}
	}
};





//CU QUITAR PRODUCTO DE UNA VENTA
//Faltan excepciones para cuando la Venta asociada a esa Mesa ya fue Facturada
//El producto a quitar tiene que estar en la Venta, sino no se cumple la precondicion de 'seleccionarProductoEliminar'. Excepcion?
void quitarProductoAUnaVenta(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______Q U I T A R__P R O D U C T O__D E__U N A__V E N T A______"<< endl;
    int opcion, mesa, cant;
	string cod;

	DtProductoCantidad dtPC;
	bool existe;
    list<DtProducto> lstDTP;

	cout << "Ingrese un Identificador de Mesa: ";
	cin >> mesa;
	lstDTP = iconQP->listarProductos(mesa);
	for (list<DtProducto>::iterator it = lstDTP.begin(); it != lstDTP.end(); it++){
		//cout << (*it) << endl;
	}

	opcion = 1;	//para entrar al wihle 
	while (opcion != 2){
		cout <<"1. Quitar un Producto a la Venta"<<endl;
		cout <<"2. Finalizar ingreso de productos"<<endl;
		cin >> opcion;
		switch (opcion){
			case 1:
				cout << "Ingrese el Identificador del Producto a quitar: ";
				cin >> cod;
				existe = existeProducto(cod, lstDTP);
				if (existe){
					cout << "Ingrese la cantidad: ";
					cin >> cant;
					dtPC.setCodigo(cod);
					dtPC.setCantidad(cant);
					iconQP->seleccionarProductoEliminar(dtPC);
				}else{
					cout << "ATENCION: Ese producto no existe en esa Venta.";
				}
			case 2:
			break;
			default:
				cout <<"ATENCION: Opción incorrecta. Intente nuevamente:"<<endl;
			break;
		}
	}

	//PARTE aceptar/cancelar
	cout <<"1. Confirmar Borrado de Producto de la Venta"<<endl;
	cout <<"2. Cancelar Borrado de Producto de la Venta"<<endl;
	cin >> opcion;
	switch (opcion){
		case 1:
			iconQP->confirmarQuitarProductoVenta();
		break;
		case 2:
			iconQP->cancelarQuitarProductoVenta();
		break;
		default:
			cout << "ATENCION: Opción incorrecta. Intente nuevamente:" << endl;
		break;
	}
};

bool existeProducto(string cod, list<DtProducto>& listProd){
	bool encontre = false;
	for (list<DtProducto>::iterator it=listProd.begin(); it != listProd.end(); it++){
		if (!encontre)	//mientras no coincidan los codigos con la lista de productos
			encontre = (cod == it->getCodigo());
	}
	return encontre;
}






//CU BAJA PRODUCTO
//Falta comprobar que el producto exista en el sistema (manejador), con try catch para excepcion, o un simple if.
void bajaProducto(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______B A J A__P R O D U C T O______"<< endl;
    int opcion, mesa, cant;
	string cod;

	bool existe;
    list<DtProductoBase> lstDTPB;

	lstDTPB = iconBAJAP->listarProductos();
	for (list<DtProductoBase>::iterator it = lstDTPB.begin(); it != lstDTPB.end(); it++){
		//cout << (*it) << endl;
	}

	cout << "Ingrese el Identificador del Producto a dar de baja: ";
	cin >> cod;
	existe = existeProductoBase(cod, lstDTPB);
	if (existe){
		//PARTE aceptar/cancelar
		cout <<"1. Confirmar Baja de Producto"<<endl;
		cout <<"2. Cancelar Baja de Producto"<<endl;
		cin >> opcion;
		switch (opcion){
			case 1:
				iconBAJAP->eliminarProducto();
			break;
			case 2:
				iconBAJAP->cancelarBajaProducto();
			break;
			default:
				cout << "ATENCION: Opción incorrecta. Intente nuevamente:" << endl;
			break;
		}	
	}else{
		cout << "ATENCION: Ese producto no existe.";
	}
}





//CU FACTURAR
//incompleto: falta imprimir && controlar que la mesa ingresada tenga una Venta asociada.
void facturar(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______F A C T U R A R__V E N T A______"<< endl;
    int opcion, mesa, desc;
	DtFacturaLocal dtfl;

	cout << "Ingrese el Identificador de la Mesa: ";
	cin >> mesa;
	cout << "Ingrese el descuento: ";
	cin >> desc;

	
	dtfl = iconF->facturar(mesa, desc);
	//cout << "Factura: "<<endl;
	//cout << dtfl << endl;
}



//Carga de datos de prueba
void cargarDatos(){

}


void menu(){
		//system("clear");
		cout <<"_____________________________________________" <<endl;
		cout <<"____________K E T O R A N T____________"<< endl;
		cout <<"1. Dar de Alta un Producto"<<endl;
		cout <<"2. Iniciar una Venta"<<endl;
		cout <<"3. Agregar un Producto a una Venta"<<endl;
		cout <<"4. Quitar un Producto de una Venta"<<endl;
		cout <<"5. Facturar una venta"<<endl;
		cout <<"6. Dar de Baja un Producto"<<endl;
        cout <<"7. «Cargar Datos de Prueba»"<<endl;
		cout <<"8. Salir"<<endl;
		cout <<"_____________________________________________" <<endl;
		cout <<"OPCION: ";
}

main(){
	fabrica = Fabrica::getInstancia();
    iconAP = fabrica->getIControladorAgregarProducto();
    iconQP = fabrica->getIControladorQuitarProducto();
    iconALTAP = fabrica->getIControladorAltaProducto();
    iconBAJAP = fabrica->getIControladorBajaProducto();
    iconIV = fabrica->getIControladorIniciarVenta();
    iconF = fabrica->getIControladorFacturar();
    //iconDATOS = fabrica->getIControladorCargarDatos(blablablalbabl);
	int opcion;
	//iconDATOS->cargarDatos();
	menu();
	cin >> opcion;
	while(opcion != 8){
		switch(opcion){
			case 1: altaProducto();
				break;
			case 2: iniciarVenta();
				break;
			case 3: agregarProductoAUnaVenta();
				break;
			case 4: quitarProductoAUnaVenta();
				break;
			case 5: facturar();
				break;
			case 6: bajaProducto();
				break;
           	case 7: cargarDatos();
				break;  
			case 8: system("exit");
				cout << "SALIENDO..." << endl;
			default:
				cout << "OPCIÓN INCORRECTA" << endl;
		}
		//system("sleep 1");
		menu();
		cin >> opcion;
	}
}