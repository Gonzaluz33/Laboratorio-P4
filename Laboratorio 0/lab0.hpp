#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

enum Estado {Nuevo,BienConservado,Roto};

//NIÑO
class Ninio {
private:
    string nombre;
    int edad;
    string direccion;
    string telefono;

    ListaObjetos *listaObjetos;

public:
    Ninio(string nombre, int edad, string direccion, string telefono);
    ~Ninio();
    void prestarObjeto(Objeto *objeto);
    void quitarObjeto(Objeto *objeto);
    void listarObjetosPrestados();

};

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


class nodo {

    private:
        Objeto *dato;
        nodo *sig;

    public:
        nodo(Objeto *objeto, nodo *sig);
        Objeto *objeto();
        nodo *getSig();
        void setSig(nodo *sig);
};

class ListaObjetos {
    private:
        nodo *primero;

    public:
        ListaObjetos();
        ~ListaObjetos();
        void agregar(Objeto *objeto);
        void quitar(Objeto *objeto);
        nodo *getPrimero();
};



//LIBRO
class Libro : public Objeto{
    private:
      string autor;
      int cantPaginas;
    public:
      Libro(string,int,string,int,string);
      virtual string toString();
      void setAutor(string);
      string getAutor(); 
      void setCantPaginas(int);
      int getCantPaginas();  
};

//JUEGOMESA
class JuegoMesa : public Objeto{

    private:
        int edadRecomendada;
        int cantJugadores;
        
    public:
        JuegoMesa(int,int,string,int,string);
        virtual string toString();
        JuegoMesa JuegoUno(JuegoMesa j);
        JuegoMesa MazoDeCartas(JuegoMesa j);
        JuegoMesa Datos(JuegoMesa j);
};