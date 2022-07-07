#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED



struct NodoCola{
    int index;
    void * dato;
    NodoCola * nextNode;
};

struct Cola {
    NodoCola*frente;
    NodoCola*fin;
};

Cola * crearCola();
void encolar(Cola*&,void*);
void desEncolar(Cola*&);
bool cola_vacia(NodoCola *&);


#endif // COLA_H_INCLUDED
