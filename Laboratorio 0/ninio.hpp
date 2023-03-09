#ifndef NINIO_HPP // include guard
#define NINIO_HPP

using namespace std;
#include "listaobjetos.hpp"
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
    void prestarObjeto(Objeto*);
    void quitarObjeto(Objeto*);
    void listarObjetosPrestados();

};
//FIN NINIO
#endif