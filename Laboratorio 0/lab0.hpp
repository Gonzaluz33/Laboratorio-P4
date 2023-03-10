#ifndef LAB0_HPP // include guard
#define LAB0_HPP
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include "objeto.hpp"
#include "ninio.hpp"
#include "listaobjetos.hpp"
using namespace std;

enum Estado {Nuevo,BienConservado,Roto};

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
        JuegoMesa(int edad_rec,int cant_jug,string nombre,int anio,string estado);
        virtual string toString();
        JuegoMesa JuegoUno(JuegoMesa j);
        JuegoMesa MazoDeCartas(JuegoMesa j);
        JuegoMesa Datos(JuegoMesa j);
};
#endif