#include "DtProductoBase.h"

DtProductoBase::DtProductoBase(){}
DtProductoBase::DtProductoBase(string codigo,string desc){
    this->codigo = codigo;
    this->descripcion = desc;
}
string DtProductoBase::getCodigo(){
    return this->codigo;
}
void DtProductoBase::setDescripcion(string desc){
    this->descripcion = desc;
}
string DtProductoBase::getDescripcion(){
    return this->descripcion;
}
DtProductoBase::~DtProductoBase(){}