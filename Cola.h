#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <sstream>

struct NodoCola{
    void * data;
    NodoCola * nextNode;
};

struct Cola {
    NodoCola*frente = NULL;
    NodoCola*fin = NULL;
    int bytesSizeData;
};

Cola * createQueue(int bytesSizeData);
NodoCola * createNodeQueue (Cola* cola, void* data);
void enqueue(Cola*& queue,void* data);
void * dequeue(Cola*& queue);
bool isEmptyQueue(NodoCola *& frente);
void printQueue(Cola*cola);

#endif // COLA_H_INCLUDED
