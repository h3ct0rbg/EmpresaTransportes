#include <iostream>
#include "time.h"
#include "arbolABB.h"
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
}

int main()
{
    srand (time(NULL));

    ArbolABB concesionarios = generarArbolConcesionarios();
    ListaD almacen;

    int numero;
    int numero1;
    string cadena;
    Concesionario c;
    Automovil v;
    int op;

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
                int numero;
                cout << "Numero de automoviles a generar: ";
                cin >> numero;
                cout << "----------------------------------------" << endl;
                cout << "Se han generado " << numero << " automoviles" << endl;
                cout << "----------------------------------------" << endl;
                while(numero>0){
                    almacen.insertarNodoListaD(generarAutomovil(), 'f');
                    numero--;
                }
                system("pause");
                break;

            case 3:
                system("cls");
                almacen.mostrarLista(ASCENDENTE);
                system("pause");
                break;

            case 4:
                system("cls");
                almacen.~ListaD();
                system("pause");
                break;

            case 5:
                system("cls");
                cout << "Modelo de automovil que desea borrar del almacen: ";
                cin >> cadena;
                almacen.borrarPorModelo(cadena);
                system("pause");
                break;

            case 6:
                system("cls");
                cout << "Numero de concesionario donde enviar los automoviles del almacen: ";
                cin >> numero;
                numero1 = 0;
                while(almacen.getLongitud()>0){
                    concesionarios.Buscar(numero).lista_vehiculos.insertarEnOrden(almacen.borrarNodo(almacen.getCabeza()));
                    numero1++;
                }
                cout << "--------------------------------------------------------------" << endl;
                cout << "Se han enviado " << numero1 << " automoviles al concesionario " << numero << concesionarios.Buscar(numero).zona << endl;
                cout << "--------------------------------------------------------------" << endl;
                system("pause");
                break;

//            case 7:
//                system("cls");
//                  string zona;
//                  cout << "Introduzca una zona: ";
//                  cin >> zona;
//                system("pause");
//                break;

            case 8:
                system("cls");
                cout << "Introduzca el numero de concesionario que desea ver: ";
                cin >> numero;
                c = concesionarios.Buscar(numero);
                //Lista de vehiculos del concesionario
                muestraConcesionario(c);
                system("pause");
                break;

            case 9:
                system("cls");
                cout << "Introduzca una zona: ";
                cin >> cadena;
                concesionarios.mostrarConcesionariosZona(cadena);
                system("pause");
                break;

            case 10:
                system("cls");
                cout << "Introduzca un numero de concesionario para borrarlo: ";
                cin >> numero;
                c = concesionarios.Buscar(numero);
                concesionarios.Borrar(c);
                system("pause");
                break;
        }
        system("cls");

    }while(op!=0);

    return 0;
}

