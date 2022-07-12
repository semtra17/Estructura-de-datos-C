#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


struct NodoLista{
    int index;
    void * data;
};

struct Lista2{
    int tam;

};
//struct NodoLista{
//    int index;
//    void * data;
//    NodoLista* nextNode;
//};
//
//
//struct Lista{
//    int tam;
//    NodoLista * head;
//
//};
//
//NodoLista* newNode(void * data);
//
//Lista* newListSimpEnl();
//
//void linkToNext(NodoLista* currentNode, NodoLista* nodeToAdd);
//
//void addNodeToList(Lista* list, NodoLista* nodeToAdd);
//
//void addDataToList(Lista* list, void* data);
//
//void vaciarLista(Lista * list);
//
//NodoLista* getIndex(Lista * lista, int index);
//
//
//
//
#endif // Lista_H_INCLUDED
