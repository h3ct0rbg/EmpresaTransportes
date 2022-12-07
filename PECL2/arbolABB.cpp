#include "ArbolABB.h"

string zona[4] = {"A", "B", "C", "D"};
int num_concesionario[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

//Borra una rama desde el nodo indicado
void ArbolABB::Podar(NodoArbol* &NodoArbol)
{
   // Algoritmo recursivo, recorrido en postorden
   if(NodoArbol) {
      Podar(NodoArbol->izquierdo); // Podar izquierdo
      Podar(NodoArbol->derecho);   // Podar derecho
      delete NodoArbol;            // Eliminar NodoArbol
      NodoArbol = NULL;
   }
}

//Insertar un int en el árbol ABB
void ArbolABB::Insertar(Concesionario dat)
{
   NodoArbol *padre = NULL;

   actual = raiz;
   // Buscar el int en el árbol, manteniendo un puntero al NodoArbol padre
   while(!Vacio(actual) && dat.numero_concesionario != actual->dato.numero_concesionario) {
      padre = actual;
      if(dat.numero_concesionario > actual->dato.numero_concesionario) actual = actual->derecho;
      else if(dat.numero_concesionario < actual->dato.numero_concesionario) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo NodoArbol será
   // el NodoArbol raiz
   if(Vacio(padre)) raiz = new NodoArbol(dat);
   // Si el int es menor que el que contiene el NodoArbol padre, lo insertamos
   // en la rama izquierda
   else if(dat.numero_concesionario < padre->dato.numero_concesionario) padre->izquierdo = new NodoArbol(dat);
   // Si el int es mayor que el que contiene el NodoArbol padre, lo insertamos
   // en la rama derecha
   else if(dat.numero_concesionario > padre->dato.numero_concesionario) padre->derecho = new NodoArbol(dat);
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::InOrden(void (*func)(Concesionario&) , NodoArbol *NodoArbol, bool r)
{
   if (Vacio(raiz)) return; //si está vacío nada
   if(r) NodoArbol = raiz;
   if(NodoArbol->izquierdo) InOrden(func, NodoArbol->izquierdo, false);
   func(NodoArbol->dato);
   if(NodoArbol->derecho) InOrden(func, NodoArbol->derecho, false);
}
