#ifndef LISTAS_DOBLES_H
#define LISTAS_DOBLES_H

#include "automovil.h"
#include <iostream>

const int ASCENDENTE=0;
const int DESCENDENTE=1;

class NodoListaD
{
    private:
        Automovil valor;
        NodoListaD *siguiente;
        NodoListaD *anterior;

        friend class ListaD;


    public:
        NodoListaD(Automovil v)
        {
            valor = v;
            siguiente = NULL;
            anterior = NULL;
        }
};
typedef NodoListaD *pNodoListaD;

class ListaD
{
    private:
        pNodoListaD cabeza, fin;
        int longitud;

    public:
        ListaD(){
            cabeza=fin=NULL;
            longitud=0;
        }
        ~ListaD();
        void insertarNodoListaD(Automovil v, char c);
        void mostrarLista(int orden);
        Automovil borrarNodo(pNodoListaD aux);
        void borrarPorModelo(string modelo);
        void insertarListaVehiculos_Concesionario(ListaD listaVehiculos);
        void escribeLista();
        bool listaVacia(){return cabeza == NULL;};
        bool esUnico(){return cabeza == fin;};

        //Getter
        int getLongitud(){
            return longitud;
        }
};

#endif // LISTAS_DOBLES_H
