#include <iostream>
#include "Cola.h"
#include <iostream>
using namespace std;



Cola * crearCola(){
    Cola * cola = new Cola();
    cola->fin=NULL;
    cola->frente=NULL;
    return cola;
}

void encolar(Cola*& cola, void* n){
    NodoCola* nuevo_nodo = new NodoCola();
    nuevo_nodo->dato= n;
    nuevo_nodo->nextNode = NULL;

    if(cola_vacia(cola->frente)){
        cola->frente = nuevo_nodo;
    }
    else{
        cola->fin->nextNode=nuevo_nodo;
    }

    cola->fin = nuevo_nodo;

    cout << "dato agregado: " << *(int*) n << endl;

};

void desEncolar(Cola *&cola){
    void * n;
    n = cola->frente->dato;
    NodoCola *aux = cola->frente;

    if(cola->frente == cola->fin){
        cola->frente = NULL;
        cola->fin = NULL;
    }
    else{
        cola->frente = cola->frente->nextNode;
    }
     cout << "dato eliminado: " << *(int*) aux->dato << endl;
    delete aux;
};

bool cola_vacia(NodoCola *&frente){
    return (frente == NULL) ? true : false;
}
