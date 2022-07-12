#include "Grafos.h"
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;


Graph* crearGraph(){
    Graph * g =  new Graph();
    g->lista =  newListSimpEnl();
    ListaSimpEnl * lista = newListSimpEnl();
    addDataToList(lista,&lista);
    g->lista->tam = 0;
    return g;
}

void addedge(Graph*& graph,int u,int v){
//    cout << "nodo principal: " << u << endl;
//    cout << "nodo sig: " << v << endl;
    bool flag = false;
        if(graph->lista->head == NULL){
            cout << "Entre aqui" << endl;
            ListaSimpEnl * nueva_lista = newListSimpEnl(); // lista nueva
            NodoLista *nuevo_nodo_lista = new NodoLista();
            addDataToList(nueva_lista, &u);//Agrego el nodo que partira desde el grafo
            addDataToList(nueva_lista, &v);// agrego este nodo al anterior quedand =>     lista ---> (nodo(u) ----> nodo(v) ----> NULL)
//            cout << *(int*)nueva_lista->head->data << endl;
//            cout << *(int*)nueva_lista->head->nextNode->data << endl;
            nuevo_nodo_lista->data = nueva_lista;
            graph->lista->head = nuevo_nodo_lista;
//            cout << (*(int*)(((ListaSimpEnl* )graph->lista->head->data)->head->data)) << endl;
//            cout << *(int*)(((ListaSimpEnl* )graph->lista->head->data)->head->nextNode->data) << endl;
        }
        else{
            NodoLista * nodo = graph->lista->head;
//            cout << *(int*)(((ListaSimpEnl* )graph->lista->head->data)->head->data) << endl;
//            cout << *(int*)(((ListaSimpEnl* )graph->lista->head->data)->head->nextNode->data) << endl;
            while(nodo != NULL && flag == false){
                    flag = add_data_to_graph((ListaSimpEnl*&)nodo->data,u,v);
                    nodo = nodo->nextNode;
            }
        }


};
bool add_data_to_graph(ListaSimpEnl *&lista, int u, int v){
//    cout << u << "   " << v << endl;
    if(*(int*)lista->head->data == u){
//        cout << *(int*)lista->head->data << endl;
//        cout << *(int*)lista->head->nextNode->data << endl;
//        cout << *(int*)lista->head->nextNode->data << endl;
        addDataToList(lista, &v);
        return true;
    }
    return false;
}






void printGraph(Graph*& graph){
        NodoLista * nodo_de_lista = graph->lista->head;
        NodoLista * nodo_de_lista_aux = ((ListaSimpEnl*&)nodo_de_lista->data)->head;
        while(nodo_de_lista != NULL){
            cout << *(int*) nodo_de_lista_aux->data << " --> " ;
            nodo_de_lista_aux = nodo_de_lista_aux->nextNode;
            while(nodo_de_lista_aux !=NULL){
                cout << *(int*) nodo_de_lista_aux->data << " , " ;
                nodo_de_lista_aux = nodo_de_lista_aux->nextNode;
            }
            cout << endl;
            nodo_de_lista = nodo_de_lista->nextNode;

        }

};


