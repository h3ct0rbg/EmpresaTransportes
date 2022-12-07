#include "gestor.h"
#include "arbolABB.h"
#include "listas_dobles.h"
#include "concesionario.h"

//Genera aleatoriamente el arbol binario de concesionarios
ArbolABB generarArbolConcesionarios(){
    string zona[4] = {"A", "B", "C", "D"};
    int num_concesionario[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    ArbolABB concesionarios;
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
