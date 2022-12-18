#include "concesionario.h"

Concesionario dameConcesionarioVacio(){
    Concesionario concesionario;

    concesionario.lista_vehiculos = Lista();
    concesionario.numero_concesionario = 0;
    concesionario.zona = "";

    return concesionario;
}

Concesionario generarConcesionario(int num_concesionario, string zona){
    Concesionario concesionario = dameConcesionarioVacio();

    concesionario.numero_concesionario = num_concesionario;
    concesionario.zona = zona;
    concesionario.lista_vehiculos = Lista();

    return concesionario;
}

void escribeConcesionario(Concesionario &c, string &s){
    if(c.zona == s || s == ""){
        cout << "Concesionario " << c.numero_concesionario << c.zona << " -> " << c.lista_vehiculos.getLongitud() << " automoviles" << endl;
    }
}

void muestraConcesionario(Concesionario &c, string &s){
    if(c.zona == s || s == ""){
        cout << "Concesionario " << c.numero_concesionario << c.zona << ": " << endl;
        cout <<"----------------------------------------------------" << endl;
        c.lista_vehiculos.mostrarLista();
        cout <<"----------------------------------------------------\n" << endl;
    }
}
//concesionarios.Buscar(numero).lista_vehiculos.insertarEnOrden(almacen.borrarNodo(almacen.getCabeza()));

void insertarPorZona(Concesionario &c, string s, ListaD &almacen){
    if(c.zona == s){
        Automovil v = almacen.borrarNodo(almacen.getCabeza());
        v.concesionario = c.numero_concesionario;
        v.zona = c.zona;
        c.lista_vehiculos.insertarEnOrden(v);
    }
}
