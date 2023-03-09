#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

enum Estado {Nuevo , BienConservado, Roto};

// niño
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


//Objeto
class Objeto {

    private: 
            string nombre;
            int anioComprado;
            bool estaPrestado;
            Ninio* prestado;
            Estado _est;
    public:
            Objeto(string,int,string);

            void setEstado(Estado estado)
            {
                _est = estado;
            };
            Estado getEstado() {
                return _est;
            };
            virtual string toString() = 0;
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

Objeto::Objeto(string nomb, int anio, string estado){
    if(estado == "Nuevo") this->_est = Nuevo;
    else 
    if(estado == "BienConservado") this->_est = BienConservado;
    else 
    if(estado == "Roto") this->_est = Roto;
    this->nombre = nomb;
    this->anioComprado = anio;
    this->estaPrestado = false;
    this->prestado = NULL;
}

Libro::Libro(string autor,int cant_pag, string nomb, int anio,string estado) : Objeto(nomb,anio,estado){
 this->autor = autor;
 this->cantPaginas = cant_pag;
}

JuegoMesa::JuegoMesa(int edad_rec, int cant_jug,string nomb, int anio,string estado) : Objeto(nomb,anio,estado){
this->edadRecomendada = edad_rec;
this->cantJugadores = cant_jug;
}

//implementaciones
void Libro::setAutor(string autor){
    this->autor = autor;
}

string Libro::getAutor(){
    return this->autor;
}

void Libro::setCantPaginas(int cantPaginas){
    this->cantPaginas = cantPaginas;
}

int Libro::getCantPaginas(){
    return this->cantPaginas;
}

string Libro::toString(){ //Nombre, AñoComprado, Estado, Autor, CantPaginas
    
}




nodo::nodo(Objeto *objeto, nodo *sig) {
    this->dato = objeto;
    this->sig = sig;
}

Objeto *nodo::objeto() {
    return this->dato;
}

nodo *nodo::getSig() {
    return this->sig;
}

void nodo::setSig(nodo *sig) {
    this->sig = sig;
}


ListaObjetos::ListaObjetos() {
    this->primero = nullptr;
}

ListaObjetos::~ListaObjetos() {
    nodo *actual = this->primero;
    nodo *aeliminar;
    while (actual->getSig()) {
        aeliminar = actual;
        actual = actual->getSig();
    }
    delete actual;
}

void ListaObjetos::agregar(Objeto *objeto) {
    this->primero = new nodo(objeto, this->primero);
}

void ListaObjetos::quitar(Objeto *objeto) {
    nodo *aeliminar;
    nodo *actual = this->primero;


    if (actual->objeto() != objeto) {
        while (actual->getSig()->objeto() != objeto) {
           actual = actual->getSig();
        }
        aeliminar = actual->getSig();
        actual->setSig(aeliminar->getSig());
    
    } else {
        aeliminar = this->primero;
        this->primero = aeliminar->getSig();
    }
    delete aeliminar;
}

nodo *ListaObjetos::getPrimero() {
    return this->primero;
}

Ninio::Ninio(string nombre, int edad, string direccion, string telefono) {
    this->nombre = nombre;
    this->edad = edad;
    this->direccion = direccion;
    this->telefono = telefono;

    this->listaObjetos = new ListaObjetos();
}

Ninio::~Ninio() {

}

void Ninio::prestarObjeto(Objeto *objeto) {
   this->listaObjetos->agregar(objeto);
}

void Ninio::quitarObjeto(Objeto *objeto) {
    this->listaObjetos->quitar(objeto);
}

void Ninio::listarObjetosPrestados() {
    nodo *actual = this->listaObjetos->getPrimero();

    while (actual->getSig()) {
        actual->objeto()->toString();
        actual = actual->getSig();
    }
    actual->objeto()->toString();
}


int main(){

    return 0;
}