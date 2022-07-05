#include <iostream>
#include "Cola.h"




void encolar(NodoCola*& frente,NodoCola*& fin , void* n){
    NodoCola* nuevo_nodo = new NodoCola();
    nuevo_nodo->dato= n;
    nuevo_nodo->nextNode = NULL;
    if(cola_vacia(frente)){
        frente = nuevo_nodo;
    }
    else{
        fin->nextNode=nuevo_nodo;
    }

    fin = nuevo_nodo;

};

void desEncolar(NodoCola*& frente,NodoCola*& fin,void* n){
    n = frente->dato;
    NodoCola *aux = frente;

    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }
    else{
        frente = frente->nextNode;
    }
    delete aux;


};

bool cola_vacia(NodoCola *&frente){
    return (frente == NULL) ? true : false;
}
