#include <iostream>
#include "Cola.h"
#include <iostream>
using namespace std;



Cola * createQueue(int bytesSizeData){
    Cola * cola = new Cola();
    cola->fin=NULL;
    cola->frente=NULL;
    cola->bytesSizeData = bytesSizeData;
    return cola;
}

NodoCola * createNodeQueue (Cola* cola, void* data) {

    NodoCola* temp = (NodoCola*) malloc(sizeof (NodoCola));
    temp->nextNode = NULL;

    temp->data = malloc(cola->bytesSizeData);
    if (!temp->data) {
        delete(temp);
        return temp;
    }
    memcpy(temp->data, data, cola->bytesSizeData);
    return temp;
}


void enqueue(Cola*& cola, void* data){

    NodoCola* nuevo_nodo = createNodeQueue(cola,data);

    if(isEmptyQueue(cola->frente)){
        cola->frente = nuevo_nodo;
    }
    else{
        cola->fin->nextNode=nuevo_nodo;
    }
    cola->fin = nuevo_nodo;





};

void * dequeue(Cola *&cola){
    void * n;
    n = cola->frente->data;
    NodoCola *aux = cola->frente;

    if(cola->frente == cola->fin){
        cola->frente = NULL;
        cola->fin = NULL;
    }
    else{
        cola->frente = cola->frente->nextNode;
    }

    delete aux;

    return n;
};

bool isEmptyQueue(NodoCola *&frente){
    return (frente == NULL) ? true : false;
}
