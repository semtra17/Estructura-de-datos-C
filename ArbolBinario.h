
#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>

typedef struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
    Nodo *padre;
};



Nodo *crearNodo (int n, Nodo *);
void insertar(Nodo *&, int n, Nodo *);
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *arbolB, int);
void preOrden(Nodo *);
void postOrden(Nodo *);
void inOrden(Nodo *);
void eliminar(Nodo *, int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);

#endif
