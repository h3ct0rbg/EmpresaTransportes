#ifndef CONCESIONARIO_H
#define CONCESIONARIO_H

#include "listas_dobles.h"
#include "concesionario.h"
#include <iostream>

using namespace std;

struct Concesionario {
    int numero_concesionario;
    string zona;
    ListaD lista_vehiculos;
};

Concesionario dameConcesionarioVacio();
Concesionario generarConcesionario(int num_concesionario, string zona);
void escribeConcesionario(Concesionario &c);

#endif //CONCESIONARIO_H
