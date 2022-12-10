#include <iostream>
#include "time.h"
#include "arbolABB.h"
#include "automovil.h"
#include "gestor.h"
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
                int NV;
                cout << "Numero de automoviles a generar: ";
                cin >> NV;
                cout << "----------------------------------------" << endl;
                cout << "Se han generado " << NV << " automoviles" << endl;
                cout << "----------------------------------------" << endl;
                while(NV>0){
                    almacen.insertarNodoListaD(generarAutomovil(), 'f');
                    NV--;
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

//            case 5:
//                system("cls");
//                string modelo;
//                cout << "Introduzca el modelo de vehiculo que quiera borrar del almacen: ";
//                cin >> modelo;
//                almacen.borrarPorModelo(modelo);
//                system("pause");
//                break;

            case 6:
                system("cls");
                int n_concesionario;
                cout << "Introduzca un numero de concesionario donde llevar todos los vehiculos desde el almacen: ";
                cin >> n_concesionario;
                //Lista de vehiculos del concesionario
                ListaD concesionarioLista = concesionarios.busqueda(n_concesionario).lista_vehiculos;

                //Insertamos los vehiculos del almacen al concesionario indicado por n_concesionario
                almacen.insertarListaVehiculos_Concesionario(concesionarioLista);

                concesionarioLista.mostrarLista(ASCENDENTE);
                system("pause");
                break;

//            case 7:
//                system("cls");
//                system("pause");
//                break;
//
//            case 8:
//                system("cls");
//                system("pause");
//                break;
//
//            case 9:
//                system("cls");
//                system("pause");
//                break;
//
//            case 10:
//                system("cls");
//                system("pause");
//                break;
        }
        system("cls");

    }while(op!=0);

    return 0;
}

