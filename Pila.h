#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <iostream>
using namespace std;




struct NodoPila{
    void * dato;
    NodoPila * nextNode;
    int bytesSizeData;
};

struct Pila{
    NodoPila * nodo;
    int bytesSizeData;
};

Pila* crearPila(int);
void apilar(Pila *, void*);
void * desapilar(Pila *pila);


#endif // PILA_H_INCLUDED
