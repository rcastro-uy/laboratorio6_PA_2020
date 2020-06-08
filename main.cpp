#include "Fabrica.h"
#include "IControladorAgregarProducto.h"
#include "IControladorQuitarProducto.h"
#include "IControladorAltaProducto.h"
#include "IControladorBajaProducto.h"
#include "IControladorIniciarVenta.h"
#include "tipoProducto.h"
//#include "IControladorFacturar.h"
//#include "IControladorCargarDatos.h"
Fabrica* fabrica;
IControladorAgregarProducto* iconAP;
IControladorQuitarProducto* iconQP;
IControladorAltaProducto* iconALTAP;
IControladorBajaProducto* iconBAJAP;
IControladorIniciarVenta* iconIV;
//IControladorFacturar* iconF;
//IControladorCargarDatos* iconDATOS;

void altaProducto();
void ingresarComun();
void ingresarMenu();
bool existeComun(string);
void imprimirListaProductos(list<DtProductoBase>);

void iniciarVenta();

void agregarProductoAUnaVenta();

void quitarProductoAUnaVenta();

void facturar();

void bajaProducto();

void cargarDatos();

void menu();

//CU ALTA PRODUCTO
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
				existe = existeComun(codComun);
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

bool existeComun(string codComun){
	bool encontre = false;
	list<DtProductoBase> listProd;
	listProd = iconALTAP->listarProductos();
	for (list<DtProductoBase>::iterator it=listProd.begin(); it != listProd.end(); it++){
		if (!encontre)	//mientras no coincidan los codigos con la lista de productos
			encontre = (codComun == it->getCodigo());
	}
	return encontre;
}

void imprimirListaProductos(list<DtProductoBase> lProd){
	// for (list<DtProductoBase>::iterator it=lProd.begin(); it != lProd.end(); it++){
	// 	cout << *it << endl;
	// }
}

//CU INICIAR VENTA EN MESA
void iniciarVenta(){

};

//CU AGREGAR PRODUCTO A UNA VENTA
void agregarProductoAUnaVenta(){

};

//CU QUITAR PRODUCTO DE UNA VENTA
void quitarProductoAUnaVenta(){

};

//CU FACTURAR
void facturar(){

};

//CU BAJA PRODUCTO
void bajaProducto(){

};

//Carga de datos de prueba
void cargarDatos(){

};


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
    //iconF = fabrica->getIControladorFacturar();
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