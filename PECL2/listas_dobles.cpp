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

void ListaD::insertarNodoListaD(Automovil v, char c)
{
    pNodoListaD aux;
    char tipoInsercion = c;

    if(listaVacia()) { //Si la lista está vacía
        aux = new NodoListaD(v);
        fin=cabeza=aux;
    }
    else if (tipoInsercion=='f') {//Inserción por el final
        aux= new NodoListaD(v);
        aux->anterior=fin;
        fin->siguiente=aux;
        fin=aux;
    }
    else if (tipoInsercion=='p') {//Inserción por el principio
        aux= new NodoListaD(v);
        aux->siguiente=cabeza;
        cabeza->anterior=aux;
        cabeza=aux;
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

void ListaD::insertarListaVehiculos_Concesionario(ListaD listaVehiculos){
    pNodoListaD aux;
    aux = cabeza;
    while(aux) {
        //cout << aux->valor.modelo << endl;
        listaVehiculos.insertarNodoListaD(aux->valor, 'f');
        aux = aux->siguiente;
    }
}

void ListaD::escribeLista(){
    pNodoListaD aux;
    aux = cabeza;
    while(aux) {
        cout << aux->valor.modelo;
        aux = aux->siguiente;
    }
}
