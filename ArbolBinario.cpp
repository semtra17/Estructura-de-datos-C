#include "ArbolBinario.h"


using namespace std;
// Funcion para crear nodo con su respectivo dato y padre.
Nodo *crearNodo (int n, Nodo *padre){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;
   return nuevo_nodo;
};
// Funcion para insertar Nodo y dato dentro del arbol binario
void insertar(Nodo *&arbolB, int n,Nodo * padre){

   if(arbolB == NULL)
       arbolB = crearNodo(n,padre);
    else if(n < arbolB->dato)
          insertar(arbolB->izq, n, arbolB);
     else if(n > arbolB->dato)
          insertar(arbolB->der, n, arbolB);

};

// Funcion para mostrar el arbol completo
void mostrarArbol(Nodo *arbolB,int cont){
    if(arbolB == NULL){ // Si el arbol esta vacio
        return;
    }
    else{
        mostrarArbol(arbolB->der, cont + 1);
        for(int i=0; i<cont; i++){
            cout <<"   ";
        }
        cout << arbolB->dato << endl;
        mostrarArbol(arbolB->izq, cont + 1);
    }

}
// Funcion para verificar la existencia de un valor dentro del arbol
bool busqueda(Nodo *arbolB, int n){
    if(arbolB == NULL){
        return false;
    }
    else if( arbolB->dato== n){
        return true;
    }
    else if(n < arbolB->dato){
        return busqueda(arbolB->izq,n);
    }
    else{
        return busqueda(arbolB->der,n);
    }

    return false;
}

// Funcion para recorrido en profundidad - PreOrden
void preOrden(Nodo *arbolB){
    if(arbolB == NULL){
        return;
    }
    else{
        cout << arbolB->dato << " - ";
        preOrden(arbolB->izq);
        preOrden(arbolB->der);
    }
}

// Funcion para recorrido en profundidad - InOrden
void inOrden(Nodo *arbolB){

    if(arbolB == NULL){
        return;
    }
    else{
        inOrden(arbolB->izq);
        cout << arbolB->dato << " - ";
        inOrden(arbolB->der);
    }


}

// Funcion para recorrido en profundidad - PostOrden
void postOrden(Nodo *arbolB){

    if(arbolB == NULL){
        return;
    }
    else{
        postOrden(arbolB->izq);
        postOrden(arbolB->der);
        cout << arbolB->dato << " - ";
    }


}
//Eliminar un nodo de arbol
void eliminar(Nodo *arbolB, int n){
    if(arbolB == NULL){// Si el arbol esta vacio
        return;//No se hace nada
    }
    else if(n < arbolB->dato){//Si el dato es menor
        eliminar(arbolB->izq, n);//Busca por la izq
    }
    else if(n > arbolB->dato){//si el dato es mayor
        eliminar(arbolB->der, n);//Busca por la der
    }
    else{//Si ya encontraste el valor del nodo
        eliminarNodo(arbolB);
    }


}
void eliminarNodo(Nodo *nodoEliminar){
    if(nodoEliminar->izq && nodoEliminar->der){//Si el nodo tiene hijo izq y der
        Nodo *menor = minimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if(nodoEliminar->izq){//Si tiene hijo izq
        reemplazar(nodoEliminar, nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }
    else if(nodoEliminar->der){//Si tiene hijo der
        reemplazar(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else{
        cout << "NODO HOJA A ELIMINAR" << endl;
        reemplazar(nodoEliminar, NULL);
        cout << "me rompo aca linea 135" << endl;
        destruirNodo(nodoEliminar);
    }


}
//Funcion para determinar el nodo mas izq posible
Nodo *minimo(Nodo *arbolB ){
    if(arbolB ==NULL){//Si el arbol esta vacio
        return NULL;//retorna NULL
    }
    if(arbolB->izq){//Si tiene hijo izq
        return minimo(arbolB->izq);//buscamos la parte mas izq posible
    }
    else{//Si no tiene izq izq
        return arbolB; //retornamos el mismo nodo
    }

}

//Funcion para reemplazar dos nodos
void reemplazar(Nodo *arbolB, Nodo *nuevoNodo){

    if(arbolB->padre){
        cout << "me rompo aca linea 159" << endl;
        //arbolB->padre hay que asignarle su nuevo hijo
        if(arbolB->padre->izq && arbolB->dato == arbolB->padre->izq->dato){
            cout << "me rompo aca linea 162" << endl;
            arbolB->padre->izq = nuevoNodo;
        }
        else if(arbolB->dato == arbolB->padre->der->dato){
        cout << "me rompo aca linea 166" << endl;
            arbolB->padre->der = nuevoNodo;
        }

    }
    if(nuevoNodo){
        //Procedemos a asignarle su nuevo padre
        cout << "me rompo aca linea 173" << endl;
        nuevoNodo->padre = arbolB->padre;
    }
}

//Funcion para destruir Nodo
void destruirNodo(Nodo *nodo){
    nodo->izq = NULL;
    nodo->der = NULL;
    nodo->padre = NULL;

    delete nodo;
}
