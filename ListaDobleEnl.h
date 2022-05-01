#ifndef LISTADOBLEENL_H_INCLUDED
#define LISTADOBLEENL_H_INCLUDED

struct Nodo{
    Nodo *ant;
    Nodo *sig;
    void* dato;

};


Nodo * crearListaDobEnl();
void insertar(Nodo *&, void *dato);
void imprimir (Nodo *, void *dato);
#endif // LISTADOBLEENL_H_INCLUDED
