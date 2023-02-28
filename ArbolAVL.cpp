#include "ArbolAVL.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <sstream>

using namespace std;

int maximum(int a, int b) {
    return (a > b) ? a : b;
}



ArbolAVL* rotateRight( ArbolAVL* node) {
    ArbolAVL* leftChild = node->left;//leftChild contendrá el subarbol izquierdo del nodo padre
    ArbolAVL* rightSubtree = leftChild->right;//rightSubtree contendrá el subarbol derecho del subarbol izquierdo del nodo padre
    leftChild->right = node;// el subarbol derecho del subarbol izquierdo del nodo padre, será ahora el nodo padre
    node->left = rightSubtree;// el subarbol izquierdo del nodo padre pasa a ser el subarbol derecho del subarbol izquierdo del nodo padre
    node->height = maximum(getHeight(node->left), getHeight(node->right)) + 1;// se calcula de vuelta la altura del nodo que ahora es el subarbol del nodo padre.
    leftChild->height = maximum(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;//LeftChild ya siendo el nodo padre se le calcula la altura

    return leftChild;
}
//
ArbolAVL* rotateLeft( ArbolAVL* node) {
    cout << node->data << endl;
    ArbolAVL* rightChild = node->right;//rightChild contendrá el subarbol derecho del nodo padre
    ArbolAVL* leftSubtree = rightChild->left;//leftSubtree contendrá el subarbol izquierdo del subarbol derecho del nodo padre

    rightChild->left = node;// el subarbol izquierdo del subarbol derecho del nodo padre, será ahora el nodo padre
    node->right = leftSubtree;// el subarbol derecho del nodo padre pasa a ser el subarbol izquierdo del subarbol derecho del nodo padre

    node->height = maximum(getHeight(node->left), getHeight(node->right)) + 1;// se calcula de vuelta la altura del nodo que ahora es el subarbol del nodo padre.
    rightChild->height = maximum(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;//rightChild ya siendo el nodo padre se le calcula la altura

    return rightChild;
}








ArbolAVL *crearNodoAVL (int n){
    ArbolAVL* node = new ArbolAVL();
    node->data = n;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
};

int getHeight(ArbolAVL* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalance(ArbolAVL* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Funcion para insertar Nodo y dato dentro del arbol binario
ArbolAVL* insertarNodoAVL(ArbolAVL *node, int data){
    if (node == NULL) {
        return crearNodoAVL(data);
    }

    if (data < node->data) {
        node->left = insertarNodoAVL(node->left, data);
    } else if (data > node->data) {
        node->right = insertarNodoAVL(node->right, data);
    } else {
        return node; // key already exists in tree
    }

    node->height = maximum(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);

    // left-left case
    if (balance > 1 && data < node->left->data) {
        return rotateRight(node);
    }

    // right-right case
    if (balance < -1 && data > node->right->data) {
        return rotateLeft(node);
    }

    // left-right case
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // right-left case
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;

};





ArbolAVL* rotarDerecha(ArbolAVL * node){
    ArbolAVL* leftChild = node->left;
    ArbolAVL* rightSubtree = leftChild->right;

    leftChild->right = node;
    node->left = rightSubtree;

    node->height = maximum(getHeight(node->left), getHeight(node->right)) + 1;
    leftChild->height = maximum(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;

    return leftChild;
}

ArbolAVL* rotarIzq(ArbolAVL * node){
    ArbolAVL* rightChild = node->right;
    ArbolAVL* leftSubtree = rightChild->left;

    rightChild->left = node;
    node->right = leftSubtree;

    node->height = maximum(getHeight(node->left), getHeight(node->right)) + 1;
    rightChild->height = maximum(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;

    return rightChild;
}

// Funcion para mostrar el arbol completo
void mostrarArbol(ArbolAVL *arbolB,int cont){

    if(arbolB == NULL){ // Si el arbol esta vacio
        return;
    }
    else{
        mostrarArbol(arbolB->right, cont + 1);
        for(int i=0; i<cont; i++){
            cout <<"   ";
        }
        cout << arbolB->data << endl;
        mostrarArbol(arbolB->left, cont + 1);
    }

}
// Funcion para verificar la existencia de un valor dentro del arbol
bool busqueda(ArbolAVL *arbolB, int n){
    if(arbolB == NULL){
        return false;
    }
    else if( arbolB->data== n){
        return true;
    }
    else if(n < arbolB->data){
        return busqueda(arbolB->left,n);
    }
    else{
        return busqueda(arbolB->right,n);
    }

    return false;
}

// Funcion para recorrido en profundidad - PreOrden
void preOrden(ArbolAVL *arbolB){
    if(arbolB == NULL){
        return;
    }
    else{
        cout << arbolB->data << " - ";
        preOrden(arbolB->left);
        preOrden(arbolB->right);
    }
}

// Funcion para recorrido en profundidad - InOrden
void inOrden(ArbolAVL *arbolB){

    if(arbolB == NULL){
        return;
    }
    else{
        inOrden(arbolB->left);
        cout << arbolB->data << " - ";
        inOrden(arbolB->right);
    }


}

// Funcion para recorrido en profundidad - PostOrden
void postOrden(ArbolAVL *arbolB){

    if(arbolB == NULL){
        return;
    }
    else{
        postOrden(arbolB->left);
        postOrden(arbolB->right);
        cout << arbolB->data << " - ";
    }


}
//Eliminar un nodo de arbol
void eliminar(ArbolAVL *arbol, int n){
    if(arbol == NULL){// Si el arbol esta vacio
        return;//No se hace nada
    }
    else if(n < arbol->data){//Si el dato es menor
        eliminar(arbol->left, n);//Busca por la izq
    }
    else if(n > arbol->data){//si el dato es mayor
        eliminar(arbol->right, n);//Busca por la der
    }
    else{//Si ya encontraste el valor del nodo
        eliminarNodo(arbol);
    }
        balanceAVL(arbol);


}
void eliminarNodo(ArbolAVL *nodoEliminar){
    if(nodoEliminar->left && nodoEliminar->right){//Si el nodo tiene hijo izq y der
        ArbolAVL *menor = minimo(nodoEliminar->right);
        nodoEliminar->data = menor->data;
        eliminarNodo(menor);
    }
    else if(nodoEliminar->left){//Si tiene hijo izq
//        reemplazar(nodoEliminar, nodoEliminar->left);
        destruirNodo(nodoEliminar);
    }
    else if(nodoEliminar->right){//Si tiene hijo der
//        reemplazar(nodoEliminar, nodoEliminar->right);
        destruirNodo(nodoEliminar);
    }
    else{
//        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }


}
//Funcion para determinar el nodo mas izq posible
ArbolAVL *minimo(ArbolAVL *arbolB ){
    if(arbolB ==NULL){//Si el arbol esta vacio
        return NULL;//retorna NULL
    }
    if(arbolB->left){//Si tiene hijo izq
        return minimo(arbolB->left);//buscamos la parte mas izq posible
    }
    else{//Si no tiene izq izq
        return arbolB; //retornamos el mismo nodo
    }

}

//Funcion para reemplazar dos nodos
//void reemplazar(ArbolAVL *arbolB, ArbolAVL *nuevoNodo){
//
//    if(arbolB->padre){
//        //arbolB->padre hay que asignarle su nuevo hijo
//        if(arbolB->padre->izq && arbolB->dato == arbolB->padre->izq->dato){
//
//            arbolB->padre->izq = nuevoNodo;
//        }
//        else if(arbolB->dato == arbolB->padre->der->dato){
//            arbolB->padre->der = nuevoNodo;
//        }
//
//    }
//    if(nuevoNodo){
//        //Procedemos a asignarle su nuevo padre
//        nuevoNodo->padre = arbolB->padre;
//    }
//}

//Funcion para destruir Nodo
void destruirNodo(ArbolAVL *nodo){
    nodo->left = NULL;
    nodo->right = NULL;
//    nodo->padre = NULL;

    delete nodo;
}



