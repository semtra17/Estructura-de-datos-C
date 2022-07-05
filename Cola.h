#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

struct NodoCola{
    int index;
    void * dato;
    NodoCola * nextNode;
};


void encolar(NodoCola*&,NodoCola*&, void*);
void desEncolar(NodoCola*&,NodoCola*&, void*);
bool cola_vacia(NodoCola *&);


#endif // COLA_H_INCLUDED
