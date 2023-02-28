#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED
#include <stdbool.h>
#include "Cola.h"



struct NodoGraph{
    int data;
    NodoGraph* next;
};

struct Graph{
    int numVertices;
    NodoGraph ** adjLists;

};


//
Graph * createGraph(int);
NodoGraph * createNode(int );
void addEdge(Graph* , int , int );
void showGraph(Graph* );
void bfs(Graph*graph, int);
void dfs(Graph*graph, int);
void dfs_helper(NodoGraph** adj_list, int visited[], int v);



#endif // GRAFOS_H_INCLUDED
