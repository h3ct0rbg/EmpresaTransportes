#include "lista.h"

using namespace std;

Lista::~Lista()
{
    pNodoLista aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}

void Lista::insertarEnOrden(Automovil v)
{
    pNodoLista aux, aux1;
    aux = new NodoLista(v);
    actual=cabeza;
    while((actual != NULL) && (actual->valor.bastidor).compare(v.bastidor)<0){
        aux1 = actual;
        actual = actual->siguiente;
    }

    if(listaVacia()){ //La lista está vacía
        cabeza = fin = aux;
    }
    else if(actual == cabeza){ //Es el primero de la lista
        aux->siguiente = actual;
        cabeza = aux;
    }
    else{ //Es el ultimo o intermedio
        aux->siguiente = actual;
        aux1->siguiente = aux;
    }
    longitud++;
}

void Lista::mostrarLista(){
    actual = cabeza;
    while(actual != NULL){
        escribeAutomovil(actual->valor);
        actual = actual->siguiente;
    }
}

bool Lista::listaVacia(){
    return cabeza == NULL;
}

void Lista::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}

void Lista::esPrimero()
{
    actual = cabeza;
}


void Lista::esFinal()
{
    esPrimero();
    if(!listaVacia())
    while(actual->siguiente)
    esSiguiente();
}

bool Lista::esActual()
{
    return actual != NULL;
}

Automovil Lista::valorActual()
{
    return actual->valor;
}
