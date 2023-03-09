#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

enum Estado : string {Nuevo, BienConservado, Roto};

class Objeto{
    private:
            bool estaPrestado;
            string nombre;
            int anioComprado;
            Ninio* prestado;
            Estado estadoObjeto;
    public:
        virtual string toString() = 0;

};

int main(){

    return 0;
}