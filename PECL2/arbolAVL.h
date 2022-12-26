#ifndef ArbolAVL_H
#define ArbolAVL_H

#include <iostream>
#include "concesionario.h"

using namespace std;

//Clase local de Lista para NodoArbol de AVL:
class NodoArbol {

    public:
        NodoArbol(Concesionario dat, int fe=0, NodoArbol *izq=NULL, NodoArbol *der=NULL) :
        dato(dat), factorEquilibrio(fe), izquierdo(izq), derecho(der) {}
        Concesionario dato;
        int factorEquilibrio;
        NodoArbol *izquierdo;
        NodoArbol *derecho;
};

class ArbolAVL {

    private:
        //Punteros de la lista, para cabeza y NodoArbol actual:
        NodoArbol *raiz;
        NodoArbol *actual;

    public:
       //Constructor y destructor básicos:
       ArbolAVL() : raiz(NULL), actual(NULL) {}
       ~ArbolAVL() { Podar(raiz); }

       void Podar(NodoArbol* &NodoArbol);
       void Insertar(Concesionario dat); //Insertar en árbol ordenado
       void Borrar(Concesionario &dat);
       Concesionario& Buscar(int concesionario);
       bool Vacio(NodoArbol *r) { return r==NULL; } //Comprobar si el árbol está vacío
       bool EsHoja(NodoArbol *r) { return !r->derecho && !r->izquierdo; } //Comprobar si es un NodoArbol hoja
       void InOrden(void (*func)(Concesionario&, string&), string zona="", NodoArbol *NodoArbol=NULL, bool r=true); //Aplicar una función a cada elemento del árbol:
       int alturaArbol(NodoArbol *a);
       int factorBalanceo(NodoArbol *a);
       void rotacionSimple(NodoArbol *a, bool giroizq);
       void rotacionDoble(NodoArbol *a, bool giroizq);
       void balancear(NodoArbol *a);
       void dibujaArbol(NodoArbol* root, int cont=0);

       //Getter
       NodoArbol* getRaiz() { return raiz;}
};

ArbolAVL generarArbolConcesionarios(void);

#endif // ArbolAVL_H
