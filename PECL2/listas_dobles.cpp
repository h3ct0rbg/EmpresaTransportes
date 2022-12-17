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
//void ListaD::insertarNodoListaD(Automovil v)
//{
//    pNodoListaD aux = cabeza;
//
//    while(v.modelo != aux.valor.modelo || aux!=fin){
//        aux = aux->siguiente;
//    }
//
//        if(cabeza==NULL){ //Si la lista esta vacia
//            aux = new NodoListaD(v);
//            cabeza=fin=aux;
//        }
//        else if(aux == cabeza){ //Si es el primero de la lista
//            aux = new NodoListaD(v);
//            aux->siguiente=cabeza;
//            cabeza->anterior=aux;
//            cabeza=aux;
//        }
//        else if(aux == fin){
//            aux = new NodoListaD(v);
//            aux->anterior=fin;
//            fin->siguiente=aux;
//            fin=aux;
//        }
//        else(){
//            aux = new NodoListaD(v);
//        }
//    }
//    else if(){
//
//    }
//    longitud++;
//}

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

void ListaD::insertarListaVehiculos_Concesionario(ListaD listaVehiculos){
    pNodoListaD aux;
    aux = cabeza;
    while(aux) {
        //cout << aux->valor.modelo << endl;
        listaVehiculos.insertarNodoListaD(aux->valor, 'f');
        aux = aux->siguiente;
    }
}

void ListaD::sortModelo(pNodoListaD cabeza) {
  if (cabeza == NULL || cabeza->siguiente == NULL) {
    return;
  }

  bool sorted = false;
  while (!sorted) {
    sorted = true;
    pNodoListaD aux = cabeza;
    while (aux->siguiente != NULL) {
      if (aux->valor.modelo.compare(aux->siguiente->valor.modelo) > 0) {
        swap(aux->valor, aux->siguiente->valor);
        sorted = false;
      }
      aux = aux->siguiente;
    }
  }
}

void ListaD::sortColor(pNodoListaD cabeza) {
  if (cabeza == NULL || cabeza->siguiente == NULL) {
    return;
  }

  bool sorted = false;
  while (!sorted) {
    sorted = true;
    pNodoListaD aux = cabeza;
    while (aux->siguiente != NULL) {
      if (aux->valor.modelo.compare(aux->siguiente->valor.modelo) == 0) {
            if (aux->valor.color.compare(aux->siguiente->valor.color) > 0){
                swap(aux->valor, aux->siguiente->valor);
                sorted = false;
            }
      }
      aux = aux->siguiente;
    }
  }
}
