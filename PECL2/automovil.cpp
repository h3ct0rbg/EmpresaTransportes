#include "automovil.h"

string letras[4] = {"A", "B", "C", "D"};
string digitos[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
string modelos[5] = {"Leon", "Ibiza", "Opel", "Ateca", "Mii Electric"};
string colores[6] = {"Rojo", "Negro", "Blanco", "Azul", "Verde", "Gris"};

//Muestra por pantalla la información de un automovil
void escribeAutomovil(Automovil p){
    cout << p.bastidor << " " << p.modelo << " " << p.color << " " << p.concesionario << p.zona << endl;
}

//Genera un automovil sin datos
Automovil dameAutomovilVacio(void){
    Automovil p;
    p.bastidor="";
    p.modelo="";
    p.color="";
    p.zona="";
    p.concesionario = 0;
    return p;
}

//Genera aleatoriamente un numero de bastidor
string generaBastidor(){
    string bastidor;
    for (int i=0;i<3;i++){
        bastidor = bastidor + letras[rand()%4];
    }
    for (int i=0;i<5;i++){
        bastidor = bastidor + digitos[rand()%10];
    }
    return bastidor;
}

//Generar aleatoriamente un automovil y lo introduce en la cola de fabrica.
Automovil generarAutomovil(){
    Automovil a;
    a = dameAutomovilVacio();
    a.bastidor = generaBastidor();
    a.modelo = modelos[rand()%5];
    a.color = colores[rand()%5];
    a.zona = "Z";
    a.concesionario = 0;
    return a;
}
