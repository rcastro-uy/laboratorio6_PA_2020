#include <stdexcept> //para el invalid_argument
#include <stdlib.h>  // para el system
#include <iostream>
#include "Fabrica.h"
#include "IControladorAgregarProducto.h"
#include "IControladorQuitarProducto.h"
#include "IControladorAltaProducto.h"
#include "IControladorBajaProducto.h"
#include "IControladorIniciarVenta.h"
#include "TipoProducto.h"
#include "IControladorFacturar.h"
#include "IControladorCargarDatos.h"
Fabrica* fabrica;
IControladorAgregarProducto* iconAP;
IControladorQuitarProducto* iconQP;
IControladorAltaProducto* iconALTAP;
IControladorBajaProducto* iconBAJAP;
IControladorIniciarVenta* iconIV;
IControladorFacturar* iconF;
IControladorCargarDatos* iconDATOS;

// CU Alta Producto
void altaProducto();
void ingresarComun();
void ingresarMenu();
bool existeProductoBase(string, list<DtProductoBase>&);
void imprimirListaProductos(list<DtProductoBase>);

// CU Iniciar Venta
void iniciarVenta();
void imprimirMesasSinVenta(list<int>);
bool mesasEnLista(int,list<int>);

// CU Agregar Producto a una Venta
void agregarProductoAUnaVenta();

// CU Quitar Producto de una Venta
void quitarProductoAUnaVenta();
bool existeProducto(string, list<DtProducto>&);
void imprimirListaDtProductos(list<DtProducto>);

// CU Facturar una Venta
void facturar();

// CU Baja de Producto
void bajaProducto();

// Cargar datos de prueba
void cargarDatos();

// CU Informacion de un Producto
void informacionDeUnProducto();

void menu();

//CU ALTA PRODUCTO
void altaProducto(){
    system("clear");
	cout << endl <<"_____________________________________________" <<endl;
	cout <<"______A L T A__D E__P R O D U C T O_______"<< endl;
    int opcion, opAceptar, opContinua;
	string cod, desc;
	float precio;

    bool hayComun;
    list<DtProductoBase> lstDTPB;

    do{
		lstDTPB = iconALTAP->listarProductosComunes();
		hayComun = (lstDTPB.empty()==false);
        if (hayComun){
            cout <<"\n1. Dar de Alta un Producto"<<endl;
            cout <<"2. Dar de Alta un Menu"<<endl;
            cout <<"3. Terminar"<<endl;
            cin >> opcion;

			switch(opcion){
				case 1:
					imprimirListaProductos(lstDTPB);
					ingresarComun();
				break;
				case 2:
					ingresarMenu();
				break;
				case 3:
				break;
				default:
					cout <<"ATENCION: Opción incorrecta. Intente nuevamente:"<<endl;
				break;
			}
			
        }else{ //NO HAY NINGUN PRODUCTO COMUN
            cout <<"\n1. Dar de Alta un Producto"<<endl;
            cout <<"2. Terminar"<<endl;
			cin >> opcion;

			switch (opcion){
				case 1:
					imprimirListaProductos(lstDTPB);
					ingresarComun();
				break;
				case 2:
				break;
				default:
					cout <<"ATENCION: Opción incorrecta. Intente nuevamente:"<<endl;
				break;
			}

        }
    } while ((hayComun && opcion != 3) || (!hayComun && opcion != 2));
}

void ingresarComun(){
	int opcion;
	string cod, desc;
	float precio;
	
	cout << "\nIngrese un Identificador único para el producto Común: ";
	cin >> cod;
	cout << "Ingrese el Precio para el producto Común: ";
	cin >> precio;
	cout << "Ingrese una Descripción para el producto Común: ";
	cin >> desc;
	iconALTAP->datosProductoComun(cod, desc, precio);

	cout <<"\n1. Confirmar Producto"<<endl;
	cout <<"2. Cancelar Alta"<<endl;
	cin >> opcion;
	switch (opcion){
		case 1:
			try{
				iconALTAP->confirmarProductoComun();
			}catch(invalid_argument& e){
				cout<<e.what()<<endl;
				break;
			}
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

	lstDTPB = iconALTAP->listarProductosMenu();
	imprimirListaProductos(lstDTPB);
	//PARTE datos de menu
	cout << "\nIngrese un Identificador único para el Menú: ";
	cin >> cod;
	cout << "Ingrese una Descripción para el Menú: ";
	cin >> desc;
	iconALTAP->datosProductoMenu(cod, desc);

	//PARTE lista productos
	lstDTPB = iconALTAP->listarProductosComunes();
	imprimirListaProductos(lstDTPB);

	//PARTE agrega comunes al menu
	opcion = 1; 
	while (opcion != 2){
		cout <<"\n1. Ingresar un Producto al Menú"<<endl;
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
					if (cant >0){
						dtPCComun.setCodigo(codComun);
						dtPCComun.setCantidad(cant);
						iconALTAP->agregarAlProductoMenu(dtPCComun);
					}else
						cout << "ATENCION: No se puede ingresar cantidad 0" << endl;
				}else{
					cout << "ATENCION: Ese producto no existe.";
				}
			break;
			case 2:
			break;
			default:
				cout <<"ATENCION: Opción incorrecta. Intente nuevamente:"<<endl;
			break;
		}
	}

	//PARTE aceptar/cancelar
	cout <<"\n1. Confirmar Menu"<<endl;
	cout <<"2. Cancelar Alta"<<endl;
	cin >> opcion;
	switch (opcion){
		case 1:
			try{
				iconALTAP->confirmarProductoMenu();
			}catch(invalid_argument& e){
				cout<<e.what()<<endl;
				break;
			}
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
	cout << endl <<"_____________________________________________" <<endl;
	cout <<"______L I S T A_______"<< endl;
	for (list<DtProductoBase>::iterator it=lProd.begin(); it != lProd.end(); it++){
	 	cout << *it;
	}
}

// CU Iniciar Venta
void iniciarVenta(){
	system("clear");
	cout << endl <<"_____________________________________________" <<endl;
	cout <<"______I N I C I A R__V E N T A__E N__M E S A S______"<< endl;
    int opcion, mesa;
	string mozo;
	list<int> mesasSinVentaDeMozo;
	list<int> mesasSelected;
	bool existe;

	cout << "Ingrese un Identificador de Mozo: ";
	cin >> mozo;
	try{
		mesasSinVentaDeMozo = iconIV->ingresarIdMozo(mozo);
		imprimirMesasSinVenta(mesasSinVentaDeMozo);
		opcion = 0;
		while (opcion != 2){
			cout <<"1. Ingresar una Mesa para iniciar su Venta"<<endl;
			cout <<"2. Finalizar ingreso de Mesas"<<endl;
			cin >> opcion;
			switch (opcion){
				case 1:
					cout << "Ingrese el Identificador de la Mesa a agregar: ";
					cin >> mesa;
					if(mesasEnLista(mesa,mesasSinVentaDeMozo)){
						mesasSelected.push_back(mesa);
					}else{
						cout << "La mesa ya tiene una venta o no corresponde al mozo" << endl;
						break;	
					}
				break;
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
	}catch (invalid_argument& e){
		cout << e.what() << endl;
	}
}

void imprimirMesasSinVenta(list<int> lMesas){
	cout << endl;
	cout <<"_________M E S A S _ D I S P O N I B L E S__________"<< endl;
	for (list<int>::iterator it=lMesas.begin(); it != lMesas.end(); it++){
	 	cout << "-> " << *it << endl;
	}
}

bool mesasEnLista(int idMesa,list<int> listaMesa){ //retorna true si la id de la mesa esta en la lista dada
	 list<int>::iterator it = listaMesa.begin();
    bool encontro=false;
    while ((!encontro)&&(it != listaMesa.end())){
        if(*it == idMesa){
            encontro = true;
        }else{
            it++;
        }  
    }
    return encontro;
}

//CU AGREGAR PRODUCTO A UNA VENTA
void agregarProductoAUnaVenta(){
	system("clear");
	cout << endl <<"_____________________________________________" <<endl;
	cout <<"______A G R E G A R__P R O D U C T O__A__U N A__V E N T A______"<< endl;
    int opcion, mesa, cant;
	string cod;

	DtProductoCantidad dtPC;
	bool existe;
    list<DtProductoBase> lstDTPB;

	cout << "Ingrese un Identificador de Mesa: ";
	cin >> mesa;
	try{
		iconAP->seleccionarMesa(mesa);
		lstDTPB = iconAP->listarProductos();
		imprimirListaProductos(lstDTPB);
		
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
						if(cant > 0){
						dtPC.setCodigo(cod);
						dtPC.setCantidad(cant);
						iconAP->seleccionarProducto(dtPC);
						}else{
							cout << "La cantidad debe ser mayor a 0" << endl;
						}
					}else{
						cout << "ATENCION: Ese producto no existe." << endl;
					}
				break;
				case 2:
					system("clear");
				break;
				default:
					cout <<"ATENCION: Opción incorrecta."<<endl;
				break;
			}
		}

		//PARTE aceptar/cancelar
		cout <<"1. Confirmar Venta de Producto"<<endl;
		cout <<"2. Cancelar Venta de Producto"<<endl;
		cin >> opcion;
		do{
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
		}while(opcion!=1 && opcion!=2);
	}catch (invalid_argument& e){
		cout << e.what() << endl;
	}
}

//CU QUITAR PRODUCTO DE UNA VENTA
void quitarProductoAUnaVenta(){
	system("clear");
	cout << endl <<"_____________________________________________" <<endl;
	cout <<"______Q U I T A R__P R O D U C T O__D E__U N A__V E N T A______"<< endl;
    int opcion, mesa, cant;
	string cod;

	DtProductoCantidad dtPC;
	bool existe;
    list<DtProducto> lstDTP;

	cout << "Ingrese un Identificador de Mesa: ";
	cin >> mesa;
	try{
		lstDTP = iconQP->listarProductos(mesa);
		imprimirListaDtProductos(lstDTP);
		opcion = 1;
		while (opcion != 2){ 
			cout <<"1. Quitar un Producto a la Venta"<<endl;
			cout <<"2. Finalizar quitar productos"<<endl;
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
				break;
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
		do{
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
		}while(opcion!=1 && opcion!=2);
	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}

bool existeProducto(string cod, list<DtProducto>& listProd){
	bool encontro = false;
	list<DtProducto>::iterator it=listProd.begin();
	while ( (!encontro) && (it != listProd.end())){
		encontro = (cod == it->getCodigo());
		it++;
	}
	return encontro;
}

void imprimirListaDtProductos(list<DtProducto> lDtProd){
	cout << endl <<"_____________________________________________" <<endl;
	cout <<"______L I S T A_______"<< endl;
	for (list<DtProducto>::iterator it=lDtProd.begin(); it != lDtProd.end(); it++){
	 	cout << *it;
	}
}

//CU FACTURAR
void facturar(){
	system("clear");
	cout << endl <<"_____________________________________________" <<endl;
	cout <<"______F A C T U R A R__V E N T A______"<< endl;
    int opcion, mesa;
	float desc;
	DtFacturaLocal dtfl;

	cout << "Ingrese el Identificador de la Mesa: ";
	cin >> mesa;
	cout << "Ingrese el descuento: ";
	cin >> desc;
	
	try{
		dtfl = iconF->facturar(mesa, desc);
		cout << "Factura: "<<endl;
		cout << dtfl << endl;
	}catch (invalid_argument& e){
		cout << e.what() << endl;
	}	
}

//CU BAJA PRODUCTO
void bajaProducto(){
	system("clear");
	cout << endl <<"_____________________________________________" <<endl;
	cout <<"______B A J A__P R O D U C T O______"<< endl;
    int opcion, mesa, cant;
	string cod;
	bool existe;
    list<DtProductoBase> lstDTPB;

	lstDTPB = iconBAJAP->listarProductos();
	imprimirListaProductos(lstDTPB);

	cout << "Ingrese el Identificador del Producto a dar de baja: ";
	cin >> cod;
	existe = existeProductoBase(cod, lstDTPB);
	if (existe){
		iconBAJAP->seleccionarProducto(cod);
		//PARTE aceptar/cancelar
		cout <<"1. Confirmar Baja de Producto"<<endl;
		cout <<"2. Cancelar Baja de Producto"<<endl;
		cin >> opcion;
		switch (opcion){
			case 1:
				try{
					iconBAJAP->eliminarProducto();
				}catch (invalid_argument& e){
					cout << e.what() << endl;
				}
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

//Cargar datos de prueba
void cargarDatos(){
	system("clear");
	try{
		iconDATOS->cargarDatos();
	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
} 

// CU Informacion de un Producto
void informacionDeUnProducto(){
	system("clear");
	cout << endl <<"_____________________________________________" <<endl;
	cout <<"______I N F O R M A C I O N__D E__U N__P R O D U C T O______"<< endl;
    int opcion;
	string cod;
	DtProducto *prod;
    list<DtProductoBase> lstDTPB;

	cout << "Productos en el Sistema: ";

	lstDTPB = iconALTAP->listarProductos();
	imprimirListaProductos(lstDTPB);
	opcion = 1;	
	while (opcion != 2){
		cout <<"1. Ver detalle de un Producto"<<endl;
		cout <<"2. Finalizar consulta de Productos"<<endl;
		cin >> opcion;
		switch (opcion){
			case 1:
				cout << "Ingrese el Identificador del Producto a mostrar: ";
				cin >> cod;
				if (iconALTAP->existeProducto(cod)){
					prod=iconALTAP->detallesProducto(cod);
					if (DtProductoComun* comun = dynamic_cast<DtProductoComun*>(prod)){
						cout << *comun << endl;
					}else{
						DtProductoMenu* menu = dynamic_cast<DtProductoMenu*>(prod);
						cout << *menu << endl;
					}		
				}else{
					cout << "ATENCION: Ese producto no existe." << endl;
				}
			break;
			case 2:
				system("clear");
			break;
			default:
				cout <<"ATENCION: Opción incorrecta. Intente nuevamente:"<<endl;
			break;
		}
	}
}

void menu(){
		cout << endl <<"_____________________________________________" <<endl;
		cout <<"____________K E A T O R R A N T____________"<< endl;
		cout <<"1. Dar de Alta un Producto"<<endl;
		cout <<"2. Iniciar una Venta"<<endl;
		cout <<"3. Agregar un Producto a una Venta"<<endl;
		cout <<"4. Quitar un Producto de una Venta"<<endl;
		cout <<"5. Facturar una venta"<<endl;
		cout <<"6. Dar de Baja un Producto"<<endl;
        cout <<"7. Cargar Datos de Prueba"<<endl;
		cout <<"8. Informacion de Producto"<<endl;
		cout <<"9. Salir"<<endl;
		cout <<"_____________________________________________" <<endl;
		cout <<"OPCION: ";
}

int main(){
	fabrica = Fabrica::getInstancia();
    iconAP = fabrica->getIControladorAgregarProducto();
    iconQP = fabrica->getIControladorQuitarProducto();
    iconALTAP = fabrica->getIControladorAltaProducto();
    iconBAJAP = fabrica->getIControladorBajaProducto();
    iconIV = fabrica->getIControladorIniciarVenta();
    iconF = fabrica->getIControladorFacturar();
    iconDATOS = fabrica->getIControladorCargarDatos();
	int opcion;
	menu();
	cin >> opcion;
	while(opcion != 9){
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
			case 8: informacionDeUnProducto();
				break;
			case 9: system("exit");
			break;
			default:
				cout << "OPCIÓN INCORRECTA" << endl;
			break;
		}
		menu();
		cin >> opcion;
	}
	return 0;
}
