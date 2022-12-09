#include "listas_dobles.h"

using namespace std;

ListaD::~ListaD()
{
    pNodoListaD aux;
    esPrimero();
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
        cabeza=NULL;
        actual=NULL;
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

bool ListaD::listaVacia()
{
    return cabeza == NULL;
}

void ListaD::esPrimero()
{
    actual=cabeza;
}

void ListaD::esUltimo()
{
    actual=fin;
}

void ListaD::borrarNodo(Automovil v,char c)
{
    char tipoBorrado;
    tipoBorrado=c;

    if(tipoBorrado=='f') {//Eliminaci�n por el final
        pNodoListaD aux=NULL;
        if((cabeza==fin)) { //S�lo hay elemento
            aux=fin;
            cabeza = fin = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=fin;
            fin=fin->anterior;
            aux->anterior=NULL;  //a�ado yo seg�n transparencias
            fin->siguiente=NULL;
            delete aux;
        }
    }
    else if(tipoBorrado=='p') {//Eliminaci�n por el Principio
        pNodoListaD aux=NULL;
        if((cabeza==fin)) {//S�lo hay elemento
            aux=cabeza;
            cabeza = fin = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=cabeza;
            cabeza=cabeza->siguiente;
            aux->siguiente=NULL;  //a�ado yo seg�n transparencias
            cabeza->anterior=NULL;
            delete aux;
        }
    }
}

void ListaD::borrarPorModelo(string modelo){

    pNodoListaD aux;

    aux = cabeza;
    while(aux) {
        if (aux->valor.modelo == modelo){
            delete aux;
        }
        aux = aux->siguiente;
    }

}
