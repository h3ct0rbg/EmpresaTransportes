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
}

bool ListaD::listaVacia()
{
    return cabeza == NULL;
}

void ListaD::esPrimero()
{
    actual=cabeza;
}
