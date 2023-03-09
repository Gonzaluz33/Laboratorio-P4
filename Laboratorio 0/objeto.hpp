#ifndef OBJETO_HPP // include guard
#define OBJETO_HPP

using namespace std;
#include "ninio.hpp"
//Objeto
class Objeto {

    private: 
            string nombre;
            int anio_comprado;
            bool esta_prestado;
            Ninio* prestado;
            Estado estado_actual;
    public:
            Objeto(string,int,string);
            ~Objeto();
            int getAnioComprado();
            bool estaEnPrestamo();
            Ninio* prestadoA();
            Estado getEstado();
            string getEstadoString();
            virtual string toString() = 0;
};
//FIN OBJETO

#endif