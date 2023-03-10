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

string Objeto::getNombre(){
    return this->nombre;
}

int Objeto::getAnioComprado(){
    return this->anio_comprado;
}

Estado Objeto::getEstadoActual(){
    return this->estado_actual;
}

bool Objeto::getEstaPrestado(){
    return this->esta_prestado;
}

Ninio* Objeto::getPrestadoA(){
    return this->prestado;
}

void Objeto::setPrestarA(Ninio* ninio){
    this->prestado = ninio;
}

void Objeto::setEstaEnPrestamo(bool b){
    this->esta_prestado = b;

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




//IMPLEMENTACIONES LIBRO

Libro::Libro(string autor,int cant_pag, string nomb, int anio,string estado) : Objeto(nomb,anio,estado){
 this->autor = autor;
 this->cantPaginas = cant_pag;
}

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

//TERMINA IMPLEMENTACIONES LIBRO


//IMPLEMENTACIONES JUEGOMESA
JuegoMesa::JuegoMesa(int edad_rec, int cant_jug,string nombre, int anio,string estado) : Objeto(nombre,anio,estado){
this->edadRecomendada = edad_rec;
this->cantJugadores = cant_jug;
}

//TERMINA IMPLEMENTACIONES JUEGOMESA




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
void Ninio::prestarObjeto(Objeto* &objeto) {
   this->listaObjetos->agregar(objeto);
   objeto->setPrestarA(this);
   objeto->setEstaEnPrestamo(true);
}

void Ninio::quitarObjeto(Objeto* &objeto) {
    this->listaObjetos->quitar(objeto);
    objeto->setPrestarA(nullptr);
    objeto->setEstaEnPrestamo(false);
}

void Ninio::listarObjetosPrestados() {
    nodo *actual = this->listaObjetos->getPrimero();

    while (actual->getSig()) {
        actual->objeto()->toString();
        actual = actual->getSig();
    }
    actual->objeto()->toString();
}

//TERMINA IMPLEMENTACIONES NINIO Y LISTA OBJETOS


//IMPLEMENTACION OBJETO ROTO--------------------------------------------


DtObjetoRoto::DtObjetoRoto(string Nombre_obj,bool Pres,string Nombre_niño){
    this->NombreObjeto = Nombre_obj;
    this->Prestado = Pres;
    this->NombreNiño = Nombre_niño;
}

void DtObjetoRoto::setNombreObjeto(string s){
    this->NombreObjeto = s;
}

string DtObjetoRoto::getNombreObjeto(){
    return this->NombreObjeto;
}

void DtObjetoRoto::setPrestado(bool b){
    this->Prestado = b;
}

bool DtObjetoRoto::getPrestado(){
    return this->Prestado;
}

void DtObjetoRoto::setNombreNiño(string s){
    this->NombreNiño = s;
}

string DtObjetoRoto::getNombreNiño(){
    return this->NombreNiño;
}

//TERMINA OBJETO ROTO--------------------------------------------



int main(){
    JuegoMesa Juego1 = JuegoMesa(7,10,"Juego1",2022,"Roto");

    return 0;
}