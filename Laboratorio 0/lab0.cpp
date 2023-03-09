#include "lab0.hpp"

//METODOS OBJETO ----------------------------------------------------

Objeto::Objeto(string nombre, int anio, string estado){
    if(estado == "Nuevo") this->estado_actual = Nuevo;
    else 
    if(estado == "BienConservado") this->estado_actual = BienConservado;
    else 
    if(estado == "Roto") this->estado_actual = Roto;
    this->nombre = nombre;
    this->anio_comprado = anio;
    this->esta_prestado = false;
    this->prestado = nullptr;
}

Objeto::~Objeto(){};

int Objeto::getAnioComprado(){
    return this->anio_comprado;
}

bool Objeto::estaEnPrestamo(){
    return this->esta_prestado;
    
}

Ninio* Objeto::prestadoA(){
    return this->prestado;
}

Estado Objeto::getEstado(){
    return this->estado_actual;
}

string Objeto::getEstadoString(){
    if(estado_actual == Nuevo) return "Nuevo";
    else 
    if(estado_actual == BienConservado) return "BienConservado";
    else 
    if(estado_actual == Roto) return "Roto";
    else return "SIN ESTADO ACTUAL";
}

//TERMINA METODOS OBJETO --------------------------------------------

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

// hay que actualizar la direccion del objeto ingresado para que apunte a Ninio
// y cambiar bool esta_prestado; a true
// creo que habria que pasar por referencia el objeto
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