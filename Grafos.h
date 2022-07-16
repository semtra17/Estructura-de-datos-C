#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED
#include <stdbool.h>
#include "ListaSimpl.h"
struct node_vertex{
    int vertex;
    node_vertex * nextNode;

};


struct Graph{
    node_vertex * list_nodes_vertex[50];
    int n;

};



Graph * crearGraph();
void addedge(Graph* graph,int u,int v);
void printGraph(Graph* graph);
bool add_data_to_graph(ListaSimpEnl *,int u, int v);



#endif // GRAFOS_H_INCLUDED
