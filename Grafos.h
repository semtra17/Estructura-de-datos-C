#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED
#include <stdbool.h>
#include "ListaSimpl.h"
struct Graph{
    ListaSimpEnl * lista;
    int n;


};

Graph * crearGraph();
void addedge(Graph*& graph,int u,int v);
void printGraph(Graph*& graph);
bool add_data_to_graph(ListaSimpEnl *&,int u, int v);



#endif // GRAFOS_H_INCLUDED
