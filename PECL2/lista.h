#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <iostream>
#include "automovil.h"

class NodoLista
 {
    private:
        Automovil valor;
        NodoLista *siguiente;
        friend class Lista;

    public:
        NodoLista(Automovil v, NodoLista *sig = NULL)
        {
            valor = v;
            siguiente = sig;
        }
};
typedef NodoLista *pNodoLista;

class Lista {
    private:
        pNodoLista cabeza, fin, actual;
        int longitud;

    public:
        Lista()
        {
            cabeza = actual = fin = NULL;
            longitud = 0;
        }
        ~Lista();
        void insertarEnOrden(Automovil v);
        bool listaVacia();
        void mostrarLista();
        void esSiguiente();
        void esFinal();
        void esPrimero();
        void esUltimo();
        bool esActual();
        Automovil valorActual();

        //Getter
        int getLongitud(){
            return longitud;
        }
};

#endif // LISTAS_H_INCLUDED
