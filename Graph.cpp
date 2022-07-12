Graph* crearGraph(){
    Graph * g =  new Graph();
    g->lista =  newListSimpEnl();
    g->lista->head = newListSimpEnl();
    g->lista->n = 0;
    return g;
}

void addedge(Graph*& graph,int u,int v,bool bi){
        (graph->lista->head == NULL){
            Lista * nueva_lista = newListSimpEnl();
            Nodo * nodo =
            addNodeToList(nueva_lista,Nodo *)
            addDataToList(graph->lista, )
        }
        if(bi){
            adjlist[v].push_back(u);
        }

};

void print(Graph*& graph){
        for(int i=0;i<n;i++){
            cout<<i<<"-->";
            for(auto it:adjlist[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
};


