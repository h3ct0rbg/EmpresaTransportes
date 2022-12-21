#include "listas_dobles.h"

using namespace std;

ListaD::~ListaD()
{
    pNodoListaD aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
        cabeza=NULL;
        fin=NULL;
        longitud=0;
}

void ListaD::insertarNodoListaD(Automovil v)
{
    pNodoListaD aux = new NodoListaD(v);
    pNodoListaD actual = cabeza;

    while(actual!=fin && v.modelo != actual->valor.modelo){
        actual = actual->siguiente;
    }
    while(actual!=fin && v.color != actual->valor.color && v.modelo == actual->siguiente->valor.modelo){
        actual = actual->siguiente;
    }

        if(listaVacia()){ //Si la lista esta vacia
            cabeza=fin=aux;
        }
        else if(actual == cabeza){ //Si es el primero de la lista
            aux->siguiente=cabeza;
            cabeza->anterior=aux;
            cabeza=aux;
        }
        else if(actual == fin){
            aux->anterior=fin;
            fin->siguiente=aux;
            fin=aux;
        }
        else{
            aux->siguiente=actual->siguiente;
            aux->anterior=actual;
            actual->siguiente->anterior=aux;
            actual->siguiente=aux;
        }
        longitud++;
}

void ListaD::mostrarLista(int orden)
{
    pNodoListaD aux;

    if (orden == ASCENDENTE) {
        aux = cabeza;
        while(aux) {
            escribeAutomovil(aux->valor);
            aux = aux->siguiente;
        }
    }
    else {
        aux = fin;
        while(aux) {
            escribeAutomovil(aux->valor);
            aux = aux->anterior;
        }
    }
}

Automovil ListaD::borrarNodo(pNodoListaD aux)
{
    Automovil automovil = aux->valor;
    if(esUnico()){
        cabeza = NULL;
        fin = NULL;
        delete aux;
    }
    else if(aux==cabeza){
        aux->siguiente->anterior = NULL;
        cabeza = aux->siguiente;
        delete aux;
    }
    else if(aux==fin){
        aux->anterior->siguiente = NULL;
        fin = aux->anterior;
        delete aux;
    }
    else{
        aux->siguiente->anterior = aux->anterior;
        aux->anterior->siguiente = aux->siguiente;
        delete aux;
    }
    longitud--;
    return automovil;
}

void ListaD::borrarPorModelo(string modelo){

    pNodoListaD aux;

    aux = cabeza;
    while(aux) {
        if (aux->valor.modelo == modelo){
            borrarNodo(aux);
        }
        aux = aux->siguiente;
    }
}

pNodoListaD ListaD::Buscar(int n){

    pNodoListaD aux;

    aux = cabeza;
    while(aux){
        if(aux->valor.concesionario == n){
            return aux;
        }
        aux = aux->siguiente;
    }
    return aux;
}

pNodoListaD ListaD::Buscar(string s){

    pNodoListaD aux;
    aux = cabeza;
    while(aux){
        if(aux->valor.zona == s){
            return aux;
        }
        aux = aux->siguiente;
    }
    return aux;
}
