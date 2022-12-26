#include "ArbolAVL.h"
#include <string.h>
#include <iostream>

string zona[4] = {"A", "B", "C", "D"};
int num_concesionario[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

//Borra una rama desde el nodo indicado
void ArbolAVL::Podar(NodoArbol* &NodoArbol)
{
   // Algoritmo recursivo, recorrido en postorden
   if(NodoArbol) {
      Podar(NodoArbol->izquierdo); // Podar izquierdo
      Podar(NodoArbol->derecho);   // Podar derecho
      delete NodoArbol;            // Eliminar NodoArbol
      NodoArbol = NULL;
   }
}

//Insertar un int en el árbol AVL
void ArbolAVL::Insertar(Concesionario dat)
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
   if(!Vacio(actual)){
        return;
   }
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo NodoArbol será
   // el NodoArbol raiz
   else if(Vacio(padre)){
        raiz = new NodoArbol(dat);
   }
   // Si el int es menor que el que contiene el NodoArbol padre, lo insertamos
   // en la rama izquierda
   else if(dat.numero_concesionario < padre->dato.numero_concesionario){
        padre->izquierdo = new NodoArbol(dat);
   }
   // Si el int es mayor que el que contiene el NodoArbol padre, lo insertamos
   // en la rama derecha
   else if(dat.numero_concesionario > padre->dato.numero_concesionario){
        padre->derecho = new NodoArbol(dat);
   }
   balancear(raiz);
}

// Recorrido de árbol en inorden
void ArbolAVL::InOrden(void (*func)(Concesionario&, string&), string zona, NodoArbol *NodoArbol, bool r)
{
   if (Vacio(raiz)) return; //si está vacío nada
   if(r) NodoArbol = raiz;
   if(NodoArbol->izquierdo) InOrden(func, zona, NodoArbol->izquierdo, false);
   func(NodoArbol->dato, zona);
   if(NodoArbol->derecho) InOrden(func, zona, NodoArbol->derecho, false);
}

Concesionario& ArbolAVL::Buscar(int concesionario)
{
    actual = raiz;
    while(!Vacio(actual))
    {
        if(concesionario == actual->dato.numero_concesionario) {
            return actual->dato; //Concesionario encontrado
        }
        else if(concesionario > actual->dato.numero_concesionario){
                actual = actual->derecho;
        }
        else if(concesionario < actual->dato.numero_concesionario){
            actual = actual->izquierdo;
        }
    }
    throw "No se ha encontrado el concesionario";
}

void ArbolAVL::Borrar(Concesionario &dat)
{
   NodoArbol *padre = NULL;
   NodoArbol *nodo;
   Concesionario aux;
   actual = raiz;

   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)){
      if(dat.numero_concesionario == actual->dato.numero_concesionario) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre) {// Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual){padre->derecho = NULL;}
               else if(padre->izquierdo == actual){padre->izquierdo = NULL;};
            }
            else{
                raiz=NULL;
            }
            delete actual; //Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            if (actual->derecho==NULL){ //sólo tiene hijo izquierdo.
                if (padre){ //Si tiene padre, me lo salto
                        if(padre->izquierdo==actual)
                            padre->izquierdo=actual->izquierdo;
                        else
                            padre->derecho=actual->izquierdo;
                }
                else{ //Si no tiene padre, su hijo izquierdo es el nuevo raiz;
                    raiz=actual->izquierdo;
                }
                delete actual;
                actual=NULL;
                return;
            }
            else  if (actual->izquierdo==NULL){ //sólo tiene hijo derecho.
                if (padre){ //Si tiene padre, me lo salto
                        if(padre->izquierdo==actual)
                            padre->izquierdo=actual->derecho;
                        else
                            padre->derecho=actual->derecho;
                }
                else{ //Si no tiene padre, su hijo izquierdo es el nuevo raiz;
                    raiz=actual->derecho;
                                    }
                delete actual;
                actual=NULL;
                return;
            }
            else{ // Tiene dos hijos. Busco sustituto. Nodo más a la derecha de la rama izquierda
               padre=actual;
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            // Intercambiar valores de nodo a borrar y nodo encontrado y continuar, cerrando el bucle. El nodo encontrado no tiene por qué ser un nodo hoja.
            // cerrando el bucle nos aseguramos de que sólo se eliminan nodos hoja.
                aux = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = aux;
                actual = nodo;
            }
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat.numero_concesionario > actual->dato.numero_concesionario) actual = actual->derecho;
         else if(dat.numero_concesionario < actual->dato.numero_concesionario) actual = actual->izquierdo;
      }
   }
}

//Genera aleatoriamente el arbol binario de concesionarios
ArbolAVL generarArbolConcesionarios(){
    string zona[4] = {"A", "B", "C", "D"};
    int num_concesionario[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    ArbolAVL concesionarios;
    int aux = 0;
    int randomIndex = 0;

    for(int i=0; i<16; i++){
        randomIndex = rand()%16;
        aux = num_concesionario[i];
        num_concesionario[i] = num_concesionario[randomIndex];
        num_concesionario[randomIndex] = aux;
    }
    for(int i=0; i<16; i++){
        Concesionario c = generarConcesionario(num_concesionario[i], zona[i%4]);
        concesionarios.Insertar(c);
    }

    return concesionarios;
}

int ArbolAVL::alturaArbol(NodoArbol *a) {
   if (a==NULL)
       return -1;
   else
   {
       /* calcule la altura de cada subárbol */
       int alturaIzquierdo = alturaArbol(a->izquierdo);
       int alturaDerecho = alturaArbol(a->derecho);

       /* use el subárbol más alto */
       if (alturaIzquierdo > alturaDerecho)
           return(alturaIzquierdo+1);
       else return(alturaDerecho+1);
   }
}

int ArbolAVL::factorBalanceo(NodoArbol *a) {
    if (a == NULL) {
        return 0;
    }
    return alturaArbol(a->derecho) - alturaArbol(a->izquierdo);
}

void ArbolAVL::rotacionSimple(NodoArbol *a, bool giroizq) {
    NodoArbol *aux;

    if(giroizq){
        aux = a->izquierdo;
        a->izquierdo = aux->derecho;
        aux->derecho = a;
    }
    else{
        aux = a->derecho;
        a->derecho = aux->izquierdo;
        aux->izquierdo = a;
    }
}

void ArbolAVL::rotacionDoble(NodoArbol *a, bool giroizq) {
    if(giroizq){ //rotación izquierda-derecha
        rotacionSimple(a->izquierdo, false);
        rotacionSimple(a, true);
    }
    else{ //rotación derecha-izquierda
        rotacionSimple(a->derecho, true);
        rotacionSimple(a, false);
    }
}

void ArbolAVL::balancear(NodoArbol *a) {
    if(!Vacio(a)){
        if(alturaArbol(a->derecho) - alturaArbol(a->izquierdo) == -2){ //Desequilibrio hacia la izquierda
            if(alturaArbol(a->izquierdo->izquierdo) >= alturaArbol(a->izquierdo->derecho)){ //Desequilibrio simple izquierda-izquierda
                rotacionSimple(a, true);
            }
            else{ //Desequilibrio doble izquierda-derecha
                rotacionDoble(a, true);
            }
        }
        else{
            if(alturaArbol(a->derecho) - alturaArbol(a->izquierdo) == 2){ //Desequilibrio hacia la derecha
                if(alturaArbol(a->derecho->derecho) >= alturaArbol(a->derecho->izquierdo)){ //Desequilibrio simple derecha-derecha
                    rotacionSimple(a, false);
                }
                else{ //Desequilibrio doble derecha-izquierda
                    rotacionDoble(a, false);
                }
            }
        }
    }
}

void ArbolAVL::dibujaArbol(NodoArbol* root, int cont) {
    if(root == NULL){
        return;
    }
    else{
        dibujaArbol(root->derecho, cont+1);
        for(int i=0; i<cont; i++){
            cout << "    |";
        }
        cout << "-->" << root->dato.numero_concesionario << endl;
        dibujaArbol(root->izquierdo, cont+1);
    }
}
