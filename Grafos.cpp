#include "Grafos.h"
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;


Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->adjLists = (NodoGraph**)malloc(n * sizeof(new NodoGraph()));
    int i;
    for (i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}


void addEdge(Graph* graph, int src, int dest){
    // Add edge from src to dest
    NodoGraph* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;

}
void showGraph(Graph* graph){

  int i;
    for (i = 0; i < graph->numVertices; i++) {
        NodoGraph* node = graph->adjLists[i];
        printf("Adjacency list of vertex %d: ", i);
        while (node) {
            printf("%d -> ", node->data);
            node = node->next;
        }
        printf("NULL\n");
    }
}


void bfs(Graph*graph, int start){
    int i, v;
    int visited[graph->numVertices];
    for (i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    visited[start] = 1;
   cout << start << " " << endl;
    NodoGraph* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = graph->adjLists[start];
    while (front != rear) {
        NodoGraph* curr = queue[front++];
        v = curr->data;
        while (curr != NULL) {
            if (!visited[v]) {
                visited[v] = 1;
                cout << v << " " << endl;
                queue[rear++] = graph->adjLists[v];
            }
            curr = curr->next;
        }
    }
}

void dfs(Graph*graph, int start){
    int i;
    int visited[graph->numVertices];
    for (i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    dfs_helper(graph->adjLists, visited, start);

}

void dfs_helper(NodoGraph** adj_list, int visited[], int v) {
    visited[v] = 1;
    cout << v << " " << endl;
    NodoGraph* curr = adj_list[v];
    while (curr != NULL) {
        int u = curr->data;
        if (!visited[u]) {
            dfs_helper(adj_list, visited, u);
        }
        curr = curr->next;
    }
}


NodoGraph * createNode(int data){
    NodoGraph* newNode = new NodoGraph();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


