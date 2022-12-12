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

void Lista::insertarEnOrden(Automovil v) {

    pNodoLista aux;
    aux = new NodoLista(v);

    if(listaVacia())
    {
        cabeza = aux;
        fin = cabeza;
        cout<<"vacia"<<endl;
    }
    else
    {
        actual=cabeza;
        cout<<"hola"<<endl;
        while(actual)
        {
            if (actual->valor.bastidor < v.bastidor || actual != fin){
                    actual = actual->siguiente;
                    cout<<"no encontrado"<<endl;
            }
            else{
                if(actual == cabeza){
                    aux->siguiente = actual;
                    cabeza = aux;
                    cout<<"es cabeza"<<endl;

                }
                else if(actual == fin){
                    aux->siguiente = NULL;
                    actual->siguiente = aux;
                    cout<<"es fin"<<endl;
                }
                else{
                    aux->siguiente=actual->siguiente;
                    actual->siguiente=aux;
                    cout<<"else"<<endl;
                }
                actual = NULL; //mueve actual para que salga del while.
            }
        }
    }
    longitud++;
}

bool Lista::listaVacia(){
    return cabeza == NULL;
}

void Lista::mostrarLista()
{
    //Nodo *aux;
    pNodoLista aux;
    aux = cabeza;

    while(aux)
    {
        cout << aux->valor.bastidor << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
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
