
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>
#include "ArbolBinario.h"
#include "Pila.h"
#include "Cola.h"

using namespace std;

int main()
{

//    Nodo *arbolB = NULL;
//    NodoPila * pila = NULL;
//    int n = 3, i =6 , j=5;
//    apilar(pila,&n);
//    apilar(pila,&i);
//    apilar(pila,&j);
//    while(pila != NULL){
//        desapilar(pila,&n);
//
//    }

    Cola *cola = crearCola();
    int l = 0, x = 3;
    encolar(cola, &l);
    encolar(cola, &x);

    while(cola->frente != NULL){
        desEncolar(cola);
    }




//    int opcion,dato,contador=0;
//
//    do{
//        cout << "\t MENU: " << endl;
//        cout << "\t 1 - Insertar nuevo nodo " << endl;
//        cout << "\t 2 - Imprimir arbol " << endl;
//        cout << "\t 3 - Buscar en arbol " << endl;
//        cout << "\t 4 - Imprimir preOrden " << endl;
//        cout << "\t 5 - Imprimir postOrden " << endl;
//        cout << "\t 6 - Imprimir inOrden " << endl;
//        cout << "\t 7 - Eliminar nodo " << endl;
//        cout << "\t 0 - Salir " << endl;
//        cout << "\t Opcion: ";
//        cin >> opcion;
//        switch(opcion){
//        case 1: cout << "digite un numero" << endl;
//                cin >> dato;
//                insertar(arbolB, dato, NULL);
//                cout << "\n";
//                system("pause");
//                break;
//        case 2: cout << "\nMostrando el arbol completo: \n\n" ;
//                mostrarArbol(arbolB,contador);
//                cout << "\n";
//                system("pause");
//                break;
//        case 3: cout<< "\nDigite el numero que desea buscar: ";
//                cin >> dato;
//                if(busqueda(arbolB, dato) == true ){
//                    cout << "\nElemento  "<< dato << " a sido encontrado en el arbol" << endl;
//                }else{
//                    cout << "\n Elemento no encontrado " << endl;
//                }
//                system("pause");
//                break;
//        case 4: cout << "\Recorrido preOrden: " ;
//                preOrden(arbolB);
//                cout << "\n\n";
//                system("pause");
//                break;
//        case 5: cout << "\Recorrido postOrden: " ;
//                postOrden(arbolB);
//                cout << "\n\n";
//                system("pause");
//                break;
//        case 6: cout << "\Recorrido inOrden: " ;
//                inOrden(arbolB);
//                cout << "\n\n";
//                system("pause");
//                break;
//        case 7: cout << "\Digite el numero que quiera eliminar: " ;
//                cin >> dato;
//                eliminar(arbolB,dato);
//                cout << "\n\n";
//                system("pause");
//                break;
//        }
//        system("cls");
//
//    }while(opcion!= 0);


    return 0;

}
