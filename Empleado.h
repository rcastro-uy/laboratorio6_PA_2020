#ifndef EMPLEADO
#define EMPLEADO
#include <stdio.h>
#include <iostream>

using namespace std;

class Empleado{
    private:
        string idEmpleado;
        string nombre;
    public:
        Empleado();
        Empleado(string,string);
        string getIdEmpleado();
        void setIdEmpleado(string);
        string getNombre();
        void setNombre(string);
        virtual ~Empleado()=0;

};


#endif