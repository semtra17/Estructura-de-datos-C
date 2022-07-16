#include "Grafos.h"
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;


Graph* crearGraph(){
    Graph * g =  new Graph();
//    g->lista =  newListSimpEnl();

    return g;
}

void addedge(Graph* graph,int u,int v){
    bool flag = false;
    if(graph->list_nodes_vertex[u] == NULL){
            graph->list_nodes_vertex[u] = new node_vertex();
            graph->list_nodes_vertex[u]->nextNode = new node_vertex();
            graph->list_nodes_vertex[u]->vertex = u;
            graph->list_nodes_vertex[u]->nextNode->vertex = v;
            graph->list_nodes_vertex[u]->nextNode->nextNode = NULL;

    }else{
        node_vertex * n = graph->list_nodes_vertex[u]->nextNode;
        while(n != NULL ){
            if(n->nextNode == NULL){
                n->nextNode = new node_vertex();
                n->nextNode->vertex = v;
                break;
            }
            n = n->nextNode;
        }
    }


};
bool add_data_to_graph(ListaSimpEnl *lista, int u, int v){
    cout << *(int*)lista->head->data << endl;
//    cout <<

}






void printGraph(Graph* graph){
    for(int i =0; i< 50; i++){
        if(graph->list_nodes_vertex[i] != NULL){
            node_vertex * n = graph->list_nodes_vertex[i];
            cout << n->vertex << " --> " ;
            n = n->nextNode;
            while(n !=NULL){
            cout << n->vertex << " , ";
            n = n->nextNode;
            }
            cout << endl;
        }

    }

};


