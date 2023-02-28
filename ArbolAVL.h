#ifndef ARBOLAVL_H_INCLUDED
#define ARBOLAVL_H_INCLUDED







struct ArbolAVL {
    int data;
    ArbolAVL* left;
    ArbolAVL* right;
    int height;

};







ArbolAVL *crearNodoAVL(int data);
int maximum(int a, int b);
int getHeight(ArbolAVL*);
int getBalance(ArbolAVL*);
ArbolAVL* rotateLeft( ArbolAVL* node);
ArbolAVL* rotateRight( ArbolAVL* node);
ArbolAVL* insertarNodoAVL(ArbolAVL *, int n);
ArbolAVL* balanceAVL(ArbolAVL * );
void mostrarArbol(ArbolAVL *,int);
bool busqueda(ArbolAVL *arbolB, int);
void preOrden(ArbolAVL *);
void postOrden(ArbolAVL *);
void inOrden(ArbolAVL *);
void eliminar(ArbolAVL *, int);
void eliminarNodo(ArbolAVL *);
ArbolAVL *minimo(ArbolAVL *);
void reemplazar(ArbolAVL *, ArbolAVL *);
void destruirNodo(ArbolAVL *);
//void balancearArbolAVL(ArbolAVL* un_arbol);
//int balanceo (ArbolAVL * un_arbol);
ArbolAVL* rotarDerecha(ArbolAVL * arbol);
ArbolAVL* rotarIzq(ArbolAVL * arbol);
int alturaArbolAVL(ArbolAVL * un_arbol);

#endif // ARBOLAVL_H_INCLUDED
