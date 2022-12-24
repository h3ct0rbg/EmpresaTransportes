#include <iostream>
#include "time.h"
#include "ArbolAVL.h"
#include "automovil.h"
#include "concesionario.h"
#include "listas_dobles.h"

using namespace std;

void adios()
{
    cout << "                                                  " << endl;
    cout << "   #####  ####   ###   ###    ####      ###  ###  " << endl;
    cout << "   #   #  #   #   #   #   #  #         #   ##   # " << endl;
    cout << "   #####  #   #   #   #   #   ###      #        # " << endl;
    cout << "   #   #  #   #   #   #   #      #       #    #   " << endl;
    cout << "   #   #  ####   ###   ###   ####          ##     " << endl;
}

void menu()
{
    cout<<" 0: Salir"<<endl;
    cout<<" 1: Mostrar todos los Concesionarios"<<endl;
    cout<<" 2: Generar Automoviles"<<endl;
    cout<<" 3: Mostrar Almacen"<<endl;
    cout<<" 4: Vaciar Almacen"<<endl;
    cout<<" 5: Borrar Automoviles (dado un modelo)"<<endl;
    cout<<" 6: Enviar Automoviles (dado un concesionario)"<<endl;
    cout<<" 7: Enviar Automoviles (dada una zona)"<<endl;
    cout<<" 8: Mostrar un Concesionario"<<endl;
    cout<<" 9: Mostrar Concesionarios (dada una zona)"<<endl;
    cout<<"10: Borrar Concesionario"<<endl;
    cout<<"11: Mostrar Arbol de Concesionarios"<<endl;
}

int main()
{
    srand (time(NULL));

    ArbolAVL concesionarios = generarArbolConcesionarios();
    ListaD almacen;

    int op, numero, numero1;
    string cadena;
    Concesionario c;
    Automovil v;

    do{
        menu();
        cout << "\nIntroduzca una opcion: ";
        cin >> op;

        switch(op){

            case 0:
                system("cls");
                adios();
                system("pause");
                break;

            case 1:
                system("cls");
                concesionarios.InOrden(escribeConcesionario);
                system("pause");
                break;

            case 2:
                system("cls");
                cout << "Numero de automoviles a generar: ";
                cin >> numero;
                cout << "--------------------------------------------" << endl;
                cout << "Se han generado " << numero << " automoviles" << endl;
                cout << "--------------------------------------------\n" << endl;
                while(numero>0){
                    int c = rand()%16 + 1;
                    string z = concesionarios.Buscar(c).zona;
                    almacen.insertarNodoListaD(generarAutomovil(z, c));
                    numero--;
                }
                system("pause");
                break;

            case 3:
                system("cls");
                almacen.mostrarLista(ASCENDENTE);
                cout << endl;
                system("pause");
                break;

            case 4:
                system("cls");
                almacen.~ListaD();
                cout << "-------------------------------------" << endl;
                cout << "Se ha vaciado el almacen de fabrica" << endl;
                cout << "-------------------------------------\n" << endl;
                system("pause");
                break;

            case 5:
                system("cls");
                cout << "Introduzca el modelo de automovil que desea borrar del almacen: ";
                cin >> cadena;
                cout << "-----------------------------------------------------------------\n" << endl;
                almacen.borrarPorModelo(cadena);
                cout << "---------------------------------------------------" << endl;
                cout << "Modelo " << cadena << " borrado del almacen" << endl;
                cout << "---------------------------------------------------\n" << endl;
                system("pause");
                break;

            case 6:
                system("cls");
                cout << "Introduzca el numero de concesionario al que se realiza el envio: ";
                cin >> numero;
                cout << "-----------------------------------------------------------------\n" << endl;
                numero1 = 0;
                while(almacen.Buscar(numero)){
                    v = almacen.borrarNodo(almacen.Buscar(numero));
                    concesionarios.Buscar(numero).lista_vehiculos.insertarEnOrden(v);
                    numero1++;
                }
                cout << "------------------------------------------------------------------" << endl;
                cout << "Se han enviado " << numero1 << " automoviles al concesionario " << numero << concesionarios.Buscar(numero).zona << endl;
                cout << "------------------------------------------------------------------\n" << endl;
                system("pause");
                break;

            case 7:
                system("cls");
                cout << "Introduzca una zona: ";
                cin >> cadena;
                numero = 0;
                while(almacen.Buscar(cadena)){
                    v = almacen.borrarNodo(almacen.Buscar(cadena));
                    concesionarios.Buscar(v.concesionario).lista_vehiculos.insertarEnOrden(v);
                    numero++;
                }
                cout << "------------------------------------------------------------------" << endl;
                cout << "Se han enviado " << numero << " automoviles a los concesionarios de la zona " << cadena << endl;
                cout << "------------------------------------------------------------------\n" << endl;
                system("pause");
                break;

            case 8:
                system("cls");
                cout << "Introduzca el numero de concesionario que desea ver: ";
                cin >> numero;
                cout << "-----------------------------------------------------------------\n" << endl;
                cadena = "";
                muestraConcesionario(concesionarios.Buscar(numero), cadena);
                cout << endl;
                system("pause");
                break;

            case 9:
                system("cls");
                cout << "Introduzca la letra de la zona que desea ver: ";
                cin >> cadena;
                cout << "-----------------------------------------------------------------\n" << endl;
                concesionarios.InOrden(muestraConcesionario, cadena);
                cout << endl;
                system("pause");
                break;

            case 10:
                system("cls");
                cout << "Introduzca el numero de concesionario que desea borrar: ";
                cin >> numero;
                cout << "-----------------------------------------------------------------" << endl;
                c = concesionarios.Buscar(numero);
                concesionarios.Borrar(c);
                cout << "------------------------------------------------------------" << endl;
                cout << "Concesionario " << c.numero_concesionario << c.zona << " borrado" << endl;
                cout << "------------------------------------------------------------\n" << endl;
                system("pause");
                break;

            case 11:
                system("cls");
                cout << "\nRaiz del arbol: " << concesionarios.getRaiz()->dato.numero_concesionario << endl;
                cout << "Altura del arbol: " << concesionarios.alturaArbol(concesionarios.getRaiz()) << endl;
                cout << "Factor de balanceo del arbol es " << concesionarios.factorBalanceo(concesionarios.getRaiz()) << endl;
                cout << endl;
                concesionarios.dibujaArbol(concesionarios.getRaiz());
                cout << endl;
                system("pause");
                break;
        }
        system("cls");

    }while(op!=0);

    return 0;
}
