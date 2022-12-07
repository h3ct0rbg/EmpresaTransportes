#ifndef ARBOLABB_H
#define ARBOLABB_H

#include "concesionario.h"
#include <iostream>

using namespace std;

//Clase local de Lista para NodoArbol de ArbolBinario:
class NodoArbol {
    public:
        NodoArbol(Concesionario dat, NodoArbol *izq=NULL, NodoArbol *der=NULL) :
        dato(dat), izquierdo(izq), derecho(der) {}
        Concesionario dato;
        NodoArbol *izquierdo;
        NodoArbol *derecho;
};

class ArbolABB {

    private:
        //Punteros de la lista, para cabeza y NodoArbol actual:
        NodoArbol *raiz;
        NodoArbol *actual;
        int contador;
        int altura;

    public:
       //Constructor y destructor básicos:
       ArbolABB() : raiz(NULL), actual(NULL) {}
       ~ArbolABB() { Podar(raiz); }

       void Podar(NodoArbol* &NodoArbol);
       void Insertar(Concesionario dat); //Insertar en árbol ordenado
       bool Vacio(NodoArbol *r) { return r==NULL; } //Comprobar si el árbol está vacío
       bool EsHoja(NodoArbol *r) { return !r->derecho && !r->izquierdo; } //Comprobar si es un NodoArbol hoja
       void InOrden(void (*func)(Concesionario&) , NodoArbol *NodoArbol=NULL, bool r=true); //Aplicar una función a cada elemento del árbol:
};

#endif // ARBOLABB_H
