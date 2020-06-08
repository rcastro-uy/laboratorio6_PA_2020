#ifndef DTFECHAHORA
#define DTFECHAHORA
#include<iostream>
#include"DtFecha.h"
using namespace std;
class DtFechaHora: public DtFecha{
	private:
		int hora;
		int min;
		int seg;
	public:
		DtFechaHora();
		DtFechaHora(int,int,int,int,int,int);
		int getHora();
		int getMin();
		int getSeg();
		~DtFechaHora();

		friend bool operator <(const DtFechaHora&,const DtFechaHora&);
		friend ostream& operator <<(ostream&,const DtFechaHora&);

};
#endif
