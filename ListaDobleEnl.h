#ifndef LISTADOBLENL_H_INCLUDED
#define LISTADOBLENL_H_INCLUDED
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>
struct NodoListaDobl{
    int index;
    void * data;
    NodoListaDobl * next;
    NodoListaDobl * previous;
};


struct Lista{
    int size;
    NodoListaDobl * first;
    NodoListaDobl * last;
    int bytesSizeData;

};



NodoListaDobl * newNodoListaDobl(Lista* , void * );
bool listlnit(Lista*, int );
bool listInsert(Lista *& ,void * , int );
bool listPushBack (Lista *&, void *);
bool listPushFront(Lista *& , void * );
void * getData(Lista * , int pos);
bool listalsEmpty(Lista*& );
Lista * listDuplicate(Lista* );

#endif // LISTADOBLENL_H_INCLUDED
