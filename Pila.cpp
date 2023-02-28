#include "Pila.h"
#include <iostream>
using namespace std;


Pila* crearPila(int bytesSizeData){
    Pila * pila = new Pila();
    pila->bytesSizeData = bytesSizeData;
    pila->nodo = NULL;

    return pila;
}



void apilar(Pila *pila, void *dato){
    NodoPila* nuevo_nodo = new NodoPila();
    nuevo_nodo->dato = malloc(pila->bytesSizeData);
    nuevo_nodo->nextNode = pila->nodo;
    pila->nodo = nuevo_nodo;
    cout << "Elemento agregado a pila " << endl;

    if (!nuevo_nodo->dato) {
        delete(nuevo_nodo);
    }
    memcpy(nuevo_nodo->dato, dato, pila->bytesSizeData);

};


void * desapilar(Pila *pila){
    NodoPila *aux = pila->nodo;
    void* dato = aux->dato;
    pila->nodo = aux->nextNode;
    delete aux;

    return dato;
;}
