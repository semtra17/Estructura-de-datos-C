
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include "ListaDobleEnl.h"
#include "ArbolAVL.h"
//#include "ArbolBinario.h"
#include "Cola.h"
#include "Pila.h"
#include "User.h"
#include "Grafos.h"

using namespace std;
void imprimirLista(Lista*& lista){

    switch(lista->bytesSizeData){
        case sizeof(User):
        fflush(stdout);
        cout << "===========Lista de usuarios=============" << endl;
        for(int i = 0; i < lista->size; i ++){

               printUser((User*) getData(lista, i));
               cout << "----------------" << endl;
        }

        break;
        case sizeof(int):
            fflush(stdout);
            cout << "===========Lista de enteros =============" << endl;
            for(int i = 0; i < lista->size; i ++){
                int dato =  *(int*) getData(lista, i);
                cout <<  dato << " / " ;
            }
            cout <<  "\n\n";

        break;
    }

}


void imprimirListaUsers(Lista* &lista){
    for(int i = 0; i < lista->size; i ++){
        cout << "========================" << endl;


        printUser((User*) getData(lista, i));

    }
}

void imprimirDatoPila(void* dato, int type){

        switch(type){
        case sizeof(User):
        fflush(stdout);
        cout << "===========User=============" << endl;
        printUser((User*) dato);


        break;
        case sizeof(int):
            fflush(stdout);
            cout << "=========== Int =============" << endl;
                cout <<  *(int*) dato << " / " ;
            cout <<  "\n\n";

        break;
        case sizeof(double):
            fflush(stdout);
            cout << "=========== double =============" << endl;
                cout <<  *(double*) dato << " / " ;
            cout <<  "\n\n";

        break;
    }

}
int main()
{

    // ======================================= CODIGO LISTAS =======================================
//    Lista* listaEnteros =  new Lista();
//    listlnit(listaEnteros,sizeof(int));
//
//    int x = 10;
//    listPushFront(listaEnteros,&x);
//    x= 3;
//    listPushFront(listaEnteros,&x);
//
//    x= 50;
//    listPushBack(listaEnteros,&x);
//    listPushBack(listaEnteros,&x);
//    listPushBack(listaEnteros,&x);
//    listPushBack(listaEnteros,&x);
//    x= 73;
//    listInsert(listaEnteros,&x, 5);
//    Lista * lista = listDuplicate(listaEnteros);
//    imprimirLista(lista);


// ======================================= CODIGO LISTA USUARIO =======================================
//    Lista* listUsers =  new Lista();
//    listlnit(listUsers, sizeof(User));
//    User * user = createUser("Luciano", "Assefh", "lassefh", "lassefh@gmail.com", "123456798");
//    User * user1 = createUser("Pedro", "Sanchez", "psanchez", "psanchez@gmail.com", "123456798");
//    User * user2 = createUser("Julian", "Gazpar", "jgazpar", "jgazpar@gmail.com", "123456798");
//    User * user3 = createUser("Matias", "Assefh", "masesfh", "masesfh@gmail.com", "123456798");
//    User * user4 = createUser("Edgar", "Assefh", "eassefh", "eassefh@gmail.com", "2222222");
//
//    listPushBack(listUsers,user);
//    listPushBack(listUsers,user1);
//    listPushBack(listUsers,user2);
//    listPushBack(listUsers,user3);
//
//    listPushBack(listUsers,user4);
//    listPushBack(listUsers,user1);
//    listInsert(listUsers,user4,5);
//    imprimirLista(listUsers);
//    cout << listUsers->bytesSizeData<< endl;



// ======================================= CODIGO PILA =======================================
//        Pila * pila = crearPila(sizeof(double));
//        double n = 2.35;
//        apilar(pila,&n);
//        double x = 2.45;
//        apilar(pila,&x);
//        double y = 3.15;
//        apilar(pila,&y);
//        while(pila->nodo != NULL){
//           imprimirDatoPila(desapilar(pila), pila->bytesSizeData);
//        }

// ======================================= CODIGO COLA =======================================

//
//    Cola * cola = createQueue(sizeof(int));
//    int x = 3;
//    enqueue(cola,&x);
//    x = 4;
//    enqueue(cola,&x);
//    x = 5;
//    enqueue(cola,&x);
//
//    cout << *(int*)dequeue(cola) << endl;
//    cout << *(int*)dequeue(cola) << endl;
//    cout << *(int*)dequeue(cola) << endl;
//
//
//    Cola * colaUser = createQueue(sizeof(User));
//    enqueue(colaUser,user);
//    enqueue(colaUser,user1);
//    enqueue(colaUser,user2);
//
//    printUser((User*)dequeue(colaUser));
//    printUser((User*)dequeue(colaUser));
//    printUser((User*)dequeue(colaUser));







// ======================================= CODIGO GRAFO =======================================

    Graph * graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    bfs(graph,0);
    dfs(graph,3);
//    showGraph(graph);



// ======================================= CODIGO ARBOL AVL =======================================

//        ArbolAVL *arbolB = NULL;
//        int opcion,dato,contador=0;
//        do{
//            cout << "\t MENU: " << endl;
//            cout << "\t 1 - Insertar nuevo nodo " << endl;
//            cout << "\t 2 - Imprimir arbol " << endl;
//            cout << "\t 3 - Buscar en arbol " << endl;
//            cout << "\t 4 - Imprimir preOrden " << endl;
//            cout << "\t 5 - Imprimir postOrden " << endl;
//            cout << "\t 6 - Imprimir inOrden " << endl;
//            cout << "\t 7 - Eliminar nodo " << endl;
//            cout << "\t 0 - Salir " << endl;
//            cout << "\t Opcion: ";
//            cin >> opcion;
//            switch(opcion){
//            case 1: cout << "digite un numero" << endl;
//                    cin >> dato;
//                    arbolB = insertarNodoAVL(arbolB, dato);
//                    cout << "\n";
//                    system("pause");
//                    break;
//            case 2: cout << "\nMostrando el arbol completo: \n\n" ;
//                    mostrarArbol(arbolB,contador);
//                    cout << "\n";
//                    system("pause");
//                    break;
//            case 3: cout<< "\nDigite el numero que desea buscar: ";
//                    cin >> dato;
//                    if(busqueda(arbolB, dato) == true ){
//                        cout << "\nElemento  "<< dato << " a sido encontrado en el arbol" << endl;
//                    }else{
//                        cout << "\n Elemento no encontrado " << endl;
//                    }
//                    system("pause");
//                    break;
//            case 4: cout << "\Recorrido preOrden: " ;
//                    preOrden(arbolB);
//                    cout << "\n\n";
//                    system("pause");
//                    break;
//            case 5: cout << "\Recorrido postOrden: " ;
//                    postOrden(arbolB);
//                    cout << "\n\n";
//                    system("pause");
//                    break;
//            case 6: cout << "\Recorrido inOrden: " ;
//                    inOrden(arbolB);
//                    cout << "\n\n";
//                    system("pause");
//                    break;
//            case 7: cout << "\Digite el numero que quiera eliminar: " ;
//                    cin >> dato;
//                    eliminar(arbolB,dato);
//                    cout << "\n\n";
//                    system("pause");
//                    break;
//            }
//            system("cls");
//
//        }while(opcion!= 0);







// ======================================= CODIGO ARBOL BINARIO =======================================
//        int opcion,dato,contador=0;

//        Nodo* arbolB = new Nodo();
//        do{
//            cout << "\t MENU: " << endl;
//            cout << "\t 1 - Insertar nuevo nodo " << endl;
//            cout << "\t 2 - Imprimir arbol " << endl;
//            cout << "\t 3 - Buscar en arbol " << endl;
//            cout << "\t 4 - Imprimir preOrden " << endl;
//            cout << "\t 5 - Imprimir postOrden " << endl;
//            cout << "\t 6 - Imprimir inOrden " << endl;
//            cout << "\t 7 - Eliminar nodo " << endl;
//            cout << "\t 0 - Salir " << endl;
//            cout << "\t Opcion: ";
//            cin >> opcion;
//            switch(opcion){
//            case 1: cout << "digite un numero" << endl;
//                    cin >> dato;
//                    insertar(arbolB, dato, NULL);
//                    cout << "\n";
//                    system("pause");
//                    break;
//            case 2: cout << "\nMostrando el arbol completo: \n\n" ;
//                    mostrarArbol(arbolB,contador);
//                    cout << "\n";
//                    system("pause");
//                    break;
//            case 3: cout<< "\nDigite el numero que desea buscar: ";
//                    cin >> dato;
//                    if(busqueda(arbolB, dato) == true ){
//                        cout << "\nElemento  "<< dato << " a sido encontrado en el arbol" << endl;
//                    }else{
//                        cout << "\n Elemento no encontrado " << endl;
//                    }
//                    system("pause");
//                    break;
//            case 4: cout << "\Recorrido preOrden: " ;
//                    preOrden(arbolB);
//                    cout << "\n\n";
//                    system("pause");
//                    break;
//            case 5: cout << "\Recorrido postOrden: " ;
//                    postOrden(arbolB);
//                    cout << "\n\n";
//                    system("pause");
//                    break;
//            case 6: cout << "\Recorrido inOrden: " ;
//                    inOrden(arbolB);
//                    cout << "\n\n";
//                    system("pause");
//                    break;
//            case 7: cout << "\Digite el numero que quiera eliminar: " ;
//                    cin >> dato;
//                    eliminar(arbolB,dato);
//                    cout << "\n\n";
//                    system("pause");
//                    break;
//            }
//            system("cls");
//
//        }while(opcion!= 0);

    return 0;
}
