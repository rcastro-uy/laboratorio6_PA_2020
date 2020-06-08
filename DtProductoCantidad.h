#ifndef DTPRODUCTOCANTIDAD
#define DTPRODUCTOCANTIDAD
#include <iostream>

using namespace std;

class DtProductoCantidad{
    private:
        string codigo;
        int cantidad;

    public:
        DtProductoCantidad();
        DtProductoCantidad(string,int);
        string getCodigo();
        void setCodigo(string);
        int getCantidad();
        void setCantidad(int);
        ~DtProductoCantidad();
};
#endif