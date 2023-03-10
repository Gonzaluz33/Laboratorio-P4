#ifndef OBJETO_HPP // include guard
#define OBJETO_HPP

using namespace std;

//Objeto
class Objeto {

    private: 
            string nombre;
            int anio_comprado;
            Estado estado_actual;
            bool esta_prestado;
            Ninio* prestado;
    public:
            Objeto(string nombre,int anio,string estado);
            ~Objeto();
            string getNombre();
            int getAnioComprado();
            Estado getEstadoActual();
            bool getEstaPrestado();
            Ninio* getPrestadoA();
            void setPrestarA(Ninio*);
            void setEstaEnPrestamo(bool);
            string getEstadoString();
            virtual string toString() = 0;
};
//FIN OBJETO

#endif