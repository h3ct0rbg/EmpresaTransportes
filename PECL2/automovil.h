#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include <iostream>

using namespace std;

struct Automovil {
    string bastidor;
    string modelo;
    string color;
    string zona;
    int concesionario;
};

void escribeAutomovil(Automovil p);
Automovil dameAutomovilVacio(void);
string generaBastidor(void);
Automovil generarAutomovil(string z, int c);

#endif // AUTOMOVIL_H
