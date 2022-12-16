#ifndef CONCESIONARIO_H
#define CONCESIONARIO_H

#include "lista.h"
#include "concesionario.h"
#include "listas_dobles.h"
#include <iostream>

using namespace std;

struct Concesionario {
    int numero_concesionario;
    string zona;
    Lista lista_vehiculos;
};

Concesionario dameConcesionarioVacio();
Concesionario generarConcesionario(int num_concesionario, string zona);
void escribeConcesionario(Concesionario &c, string &s);
void muestraConcesionario(Concesionario &c, string &s);
bool insertarPorZona(Concesionario &c, string &s, ListaD &almacen);

#endif //CONCESIONARIO_H
