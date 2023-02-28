
#include "ListaDobleEnl.h"

using namespace std;
/******************************************************************************/
/* Implementacion de Primitivas */
/* ===================== CONSTRUCTOR =====================*/


NodoListaDobl * newNodoListaDobl (Lista* list, void* data) {

    NodoListaDobl* temp = (NodoListaDobl*) malloc(sizeof (NodoListaDobl));
    temp->data = malloc(list->bytesSizeData);
    if (!temp->data) {
        free(temp);
        return temp;
    }

    memcpy(temp->data, data, list->bytesSizeData);
    return temp;
}

bool listlnit(Lista* list, int bytesSizeData){
    if(!list) return false;


    list->first = list->last = NULL;
    list->size = 0;
    list->bytesSizeData = bytesSizeData;
    return true;
}

bool listPushBack (Lista*& list, void *data) {
    NodoListaDobl* temp;
    if (!(temp = newNodoListaDobl(list, data))) return false;
    if (list->size == 0) {
        list->first = list->last = temp;
        temp->next= NULL;
        list->size++;
        return true;
    } else {
        list->last->next= temp;
        list->last = temp;
        list->last->next = NULL;
    }
    list->size++;
    return true;
}

bool listPushFront(Lista *& lista, void * data){
    NodoListaDobl* temp;
    if (!(temp = newNodoListaDobl (lista, data))) return false;


    if (lista->size == 0) {
        lista->first = lista->last = temp;
        temp->next = NULL;
        lista->size++;
        return true;
    }

    temp->next = lista->first;
    lista->first = temp;
    lista->size++;
    return true;

}


void * getData(Lista *lista, int pos){
    if(!lista || pos < 0 || lista->size <= 0 || pos >= lista->size)
        return NULL;

    if(pos == 0)
        return lista->first->data;
    if(pos == lista->size-1)
        return lista->last->data;

    NodoListaDobl *f = NULL;
    for (int i = 0; i < pos; i++) {
        if (i == 0)
        f = lista->first;
        else
        f= f->next;
    }

    return f->next->data;

}



Lista * listDuplicate(Lista* list) {

    if (!list) return NULL;

    Lista* temp = new Lista();
    listlnit(temp, list->bytesSizeData);


    NodoListaDobl *p = list->first;
    while (p!= NULL) {
        listPushBack(temp, p->data);
        p = p->next;
    }

    return temp;


}



bool listInsert(Lista * &lista,void * data, int pos){

    if(!lista || pos < 0)
        return false;

    if(pos == 0)
        return listPushFront(lista, data);
    if(pos == lista->size)
        return listPushBack(lista, data);

    NodoListaDobl *f = NULL;
    for(int i=0; i< pos; i++){
        if(i == 0)
            f = lista->first;
        else
            f = f->next;
    }

    NodoListaDobl * temp;
    if(!(temp = newNodoListaDobl(lista,data)))
        return false;
    temp->next = f->next;
    f->next = temp;
    lista->size++;
    return true;
}

bool listalsEmpty(Lista* list) {
    if (!list)
        return true;

    return (list->size == 0);
}

