#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED


struct NodoCola{
    int index;
    void * dato;
    NodoCola * nextNode;
};

struct Cola {
    NodoCola*frente = NULL;
    NodoCola*fin = NULL;
};

Cola * crearCola();
void encolar(Cola*& cola,void* n);
void desEncolar(Cola*& cola);
bool cola_vacia(NodoCola *& frente);


#endif // COLA_H_INCLUDED
