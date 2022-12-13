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

void escribeConcesionario(Concesionario &c){
    cout << "Concesionario " << c.numero_concesionario << c.zona << ": " << c.lista_vehiculos.getLongitud() << " automoviles" << endl;
}

void muestraConcesionario(Concesionario &c){
    cout << "Concesionario " << c.numero_concesionario << c.zona << ": " << endl;
    c.lista_vehiculos.mostrarLista();
}



