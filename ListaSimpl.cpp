#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>
#include "ListaSimpl.h"


/******************************************************************************/
/* Implementacion de Primitivas */
/* ===================== CONSTRUCTOR =====================*/
NodoLista* newNode(void * data){

	NodoLista *nodo = new NodoLista();
	nodo->data = data;
    nodo->nextNode = NULL;
	return nodo;


}

ListaSimpEnl* newListSimpEnl(){
	ListaSimpEnl *list = new ListaSimpEnl();
	list->head = NULL;
	list->tam = 0;
	return list;
}



/* ===================== ADDITION =====================*/

void linkToNext(NodoLista* currentNode, NodoLista* nodeToAdd){
	if (currentNode->nextNode == NULL){
		currentNode->nextNode = nodeToAdd;
		nodeToAdd->index = nodeToAdd->index + 1;
	}else{
	 	linkToNext(currentNode->nextNode, nodeToAdd);
	}
}

void addNodeToList(ListaSimpEnl* list, NodoLista* nodeToAdd){
      if(list->head == NULL){
        list->head = nodeToAdd;
        nodeToAdd->index = 0;
      }else{
        linkToNext(list->head, nodeToAdd);
      }
}

void addDataToList(ListaSimpEnl* list, void* data){
	NodoLista* node = newNode(data);
    addNodeToList(list, node);
    list->tam++;
}

/* ===================== DESTRUCTOR =====================*/
void vaciarListaSimpEnl(ListaSimpEnl * list){
    NodoLista * nodo = list->head;
    NodoLista * nextNode = nodo->nextNode;
    while(nodo != NULL){
        delete(nodo);
        nodo = nextNode;
       if(nextNode != NULL){
        nextNode = nextNode->nextNode;

       }

    }
    delete(list->head);
    list->head = NULL;
}


/* ===================== GET =====================*/
NodoLista* getIndex(ListaSimpEnl * lista, int index){
    NodoLista* n = lista->head;
    NodoLista* temp = NULL;
    while (n != NULL) {
        if(n->index == index){
            return n;
        }
        n = n->nextNode;
      }
        return temp;

}
