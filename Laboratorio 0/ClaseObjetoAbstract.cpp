#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

class Objeto{
    private:
            string nombre;
            int anioComprado;
    public:
        virtual string toString() = 0;
};

int main(){
    return 0;
}