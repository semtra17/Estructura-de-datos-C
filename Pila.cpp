#include "Pila.h"
#include <iostream>
using namespace std;


void apilar(NodoPila *&pila, void *dato){
    NodoPila* nuevo_nodo = new NodoPila();
    nuevo_nodo->dato = dato;
    nuevo_nodo->nextNode = pila;
    pila = nuevo_nodo;
    cout << "Elemento agregado a pila " << endl;
};


void desapilar(NodoPila *&pila, void* dato){
    NodoPila *aux = pila;
    dato = aux->dato;
    pila = aux->nextNode;
    if(pila != NULL){
            cout << *(int*) dato << " , ";
        }else{
            cout << *(int*) dato<< " . ";
        }
    delete aux;
;}
