#ifndef LISTASIMPL_H_INCLUDED
#define LISTASIMPL_H_INCLUDED



struct NodoLista{
    int index;
    void * data;
    NodoLista * nextNode;
};



struct ListaSimpEnl{
    int tam;
    NodoLista * head;

};



NodoLista* newNode(void * data);

ListaSimpEnl* newListSimpEnl();



void linkToNext(NodoLista* currentNode, NodoLista* nodeToAdd);

void addNodeToList(ListaSimpEnl* list, NodoLista* nodeToAdd);


void addDataToList(ListaSimpEnl* list, void* data);


void vaciarListaSimpEnl(ListaSimpEnl * list);


NodoLista* getIndex(ListaSimpEnl * lista, int index);



#endif // LISTASIMPL_H_INCLUDED
