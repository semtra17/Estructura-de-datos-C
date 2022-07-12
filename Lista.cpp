#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>
#include "Lista.h"
//
///******************************************************************************/
///* Implementacion de Primitivas */
///* ===================== CONSTRUCTOR =====================*/
//NodoLista* newNode(void * data){
//
//	NodoLista *nodo = new NodoLista();
//	nodo->data = data;
//    nodo->nextNode = NULL;
//	return nodo;
//
//
//}
//
//Lista* newListSimpEnl(){
//	Lista *list = new Lista();
//	list->head = NULL;
//	list->tam = 0;
//	return list;
//}
//
//
//
///* ===================== ADDITION =====================*/
//
//void linkToNext(NodoLista* currentNode, NodoLista* nodeToAdd){
//	if (currentNode->nextNode == NULL){
//		currentNode->nextNode = nodeToAdd;
//		nodeToAdd->index = nodeToAdd->index + 1;
//	}else{
//	 	linkToNext(currentNode->nextNode, nodeToAdd);
//	}
//}
//
//void addNodeToList(Lista* list, NodoLista* nodeToAdd){
//      if(list->head == NULL){
//        list->head = nodeToAdd;
//        nodeToAdd->index = 0;
//      }else{
//        linkToNext(list->head, nodeToAdd);
//      }
//}
//
//void addDataToList(Lista* list, void* data){
//	NodoLista* node = newNode(data);
//    addNodeToList(list, node);
//    list->tam++;
//}
//
///* ===================== DESTRUCTOR =====================*/
//void vaciarLista(Lista * list){
//    NodoLista * nodo = list->head;
//    NodoLista * nextNode = nodo->nextNode;
//    while(nodo != NULL){
//        delete(nodo);
//        nodo = nextNode;
//       if(nextNode != NULL){
//        nextNode = nextNode->nextNode;
//
//       }
//
//    }
//    delete(list->head);
//    list->head = NULL;
//}
//
//
///* ===================== GET =====================*/
//NodoLista* getIndex(Lista * lista, int index){
//    NodoLista* n = lista->head;
//    NodoLista* temp = NULL;
//    while (n != NULL) {
//        if(n->index == index){
//            return n;
//        }
//        n = n->nextNode;
//      }
//        return temp;
//
//}
