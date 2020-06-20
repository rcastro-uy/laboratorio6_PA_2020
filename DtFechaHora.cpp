#include "DtFechaHora.h"
DtFechaHora::DtFechaHora(){}
DtFechaHora::DtFechaHora(int dia,int mes,int anio,int hora,int min,int seg):DtFecha(dia,mes,anio){
	this->hora=hora;
	this->min=min;
	this->seg=seg;
}
int DtFechaHora::getHora(){
	return this->hora;
}
int DtFechaHora::getMin(){
	return this->min;
}
int DtFechaHora::getSeg(){
	return this->seg;
}
DtFechaHora::~DtFechaHora(){}

bool operator <(const DtFechaHora& dtf1,const DtFechaHora& dtf2){
	bool retorno;
	if (dtf1.hora < dtf2.hora){
		retorno=true;
	}else if(dtf1.hora == dtf2.hora){
		if (dtf1.min < dtf2.min){
			retorno=true;
		}else if(dtf1.min == dtf2.min){
			if (dtf1.seg < dtf2.seg){
				retorno=true;
			}else{ 
				retorno=false;
			}
		}
	}
	return retorno;
}
ostream& operator <<(ostream& salida,const DtFechaHora& dtf){
	cout << DtFecha(dtf);
	cout << dtf.hora << "/" << dtf.min << "/" << dtf.seg <<endl;
	return salida;
}