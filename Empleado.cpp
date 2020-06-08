#include "Empleado.h"

Empleado::Empleado(){}
Empleado::Empleado(string id,string nom){
    this->idEmpleado=id;
    this->nombre=nom;
}
string Empleado::getIdEmpleado(){
    return this->idEmpleado;
}
void Empleado::setIdEmpleado(string id){
    this->idEmpleado=id;
}
string Empleado::getNombre(){
    return this->nombre;
}
void Empleado::setNombre(string nom){
    this->nombre=nom;
}
Empleado::~Empleado(){}