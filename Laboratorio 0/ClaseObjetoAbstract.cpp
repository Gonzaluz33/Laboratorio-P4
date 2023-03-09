#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;



class Objeto {

    private:
            bool estaPrestado;
            string nombre;
            int anioComprado;
            Ninio* prestado;
            Estado _est;
    public:
            virtual string toString() = 0;

            enum Estado {Nuevo = 0, BienConservado = 1, Roto = 2};

            void setEstado(Estado estado)
            {
                _est = estado;
            }
            Estado getEstado() {
                return _est;
            }

};

int main(){

    return 0;
}