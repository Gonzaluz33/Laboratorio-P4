#ifndef LISTAOBJETOS_HPP // include guard
#define LISTAOBJETOS_HPP
using namespace std;
#include "objeto.hpp"

class nodo {

    private:
        Objeto* dato;
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

#endif