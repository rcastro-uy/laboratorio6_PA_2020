#ifndef MANEJADOREMPLEADO
#define MANEJADOREMPLEADO
#include "Empleado.h"
#include <iostream>
#include <list>

using namespace std;

class ManejadorEmpleado{
    private:
        static ManejadorEmpleado* instancia;
        ManejadorEmpleado();
    public:
        static ManejadorEmpleado* getInstancia();
        list<Empleado*> getEmpleados();
        Empleado* getEmpleado(string);
        void removerEmpleado(Empleado*);
        void agregarEmpleado(Empleado*);
        virtual ~ManejadorEmpleado();
};

#endif