#ifndef GESTOR_H
#define GESTOR_H

#include "automovil.h"
#include "listas_dobles.h"
#include "arbolABB.h"
#include "concesionario.h"

ArbolABB generarArbolConcesionarios(void);
void insertarListaVehiculos_Concesionario(ListaD almacen, ListaD listaVehiculos);

#endif // GESTOR_H

