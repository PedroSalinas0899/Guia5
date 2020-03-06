#include <iostream>

#include "Grafo.h"
#include "Arbol.h"

Arbol::Arbol () {
}

Nodo* Arbol::crearNodo (int n) {
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->der = NULL;

    return nuevo_nodo;
}

void Arbol::restruct_izquierda(Nodo *&raiz, bool altura_arbol) {
    Nodo *aux_1;
    Nodo *aux_2;

    if (altura_arbol == true) {
        if (raiz->fe == -1) {
            raiz->fe = 0;
        }
        else if (raiz->fe == 0) {
            raiz->fe = 1;
            altura_arbol = false;
        }
        else if (raiz->fe == 1) {
            aux_1 = raiz->der;
            if (aux_1->fe >= 0) {
                raiz->der = aux_1->izq;
                aux_1->izq = raiz;
                if (aux_1->fe == 0) {
                    raiz->fe = 1;
                    aux_1->fe = -1;
                    altura_arbol = false;
                }
                else if (aux_1->fe == 1) {
                    raiz->fe = 0;
                    aux_1->fe = 0;
                }
                raiz = aux_1;
            }
            else {
                aux_2 = aux_1->izq;
                raiz->der = aux_2->izq;
                aux_2->izq = raiz;
                aux_1->izq = aux_2->der;
                aux_2->der = aux_1;

                if (aux_2->fe == 1) {
                    raiz->fe = -1;
                }
                else {
                    raiz->fe = 0;
                }
                if (aux_2->fe == -1) {
                    aux_1->fe = 1;
                }
                else {
                    aux_1->fe = 0;
                }
                raiz = aux_2;
                aux_2->fe = 0;
            }
        }
    }
}

void Arbol::restruct_derecha(Nodo *&raiz, bool altura_arbol) {
    Nodo *aux_1;
    Nodo *aux_2;

    if (altura_arbol == true ) {
        if (raiz->fe == 1) {
            raiz->fe = 0;
        }
        else if (raiz->fe == 0) {
            raiz->fe = -1;
            altura_arbol = false;
        }
        else if (raiz->fe == -1) {
            aux_1 = raiz->izq;
            if (aux_1->fe <= 0) {
                raiz->izq = aux_1->der;
                aux_1->der = raiz;

                if (aux_1->fe == 0) {
                    raiz->fe = -1;
                    aux_1->fe = 1;
                    altura_arbol = false;
                }
                else if (aux_1->fe == -1) {
                    raiz->fe = 0;
                    aux_1->fe = 0;
                }
                raiz = aux_1;
            }
            else {
                aux_2 = aux_1->der;
                raiz->izq = aux_2->der;
                aux_2->der = raiz;
                aux_1->der = aux_2->izq;
                aux_2->izq = aux_1;

                if (aux_2->fe == -1) {
                    raiz->fe = 1;
                }
                else{
                    raiz->fe = 0;
                }
                if (aux_2->fe == 1) {
                    aux_1->fe = -1;
                }
                else {
                    aux_1->fe = 0;
                }
                raiz = aux_2;
                aux_2->fe = 0;
            }
        }
    }
}

void Arbol::insertarNodo (Nodo *&raiz, int n, bool &altura_arbol) {
    if (raiz == NULL) {
        Nodo *tmp;
        tmp = crearNodo(n);
        raiz = tmp;
        insertarNodo(raiz, n, altura_arbol);
    }
    else {
        if (n < raiz->dato) {
            insertarNodo(raiz->izq, n, altura_arbol);
            restruct_derecha(raiz, altura_arbol);
        }
        else if (n > raiz->dato) {
            insertarNodo(raiz->der, n, altura_arbol);
            restruct_izquierda(raiz, altura_arbol);
        }
    }
    altura_arbol = true;
}

bool Arbol::buscarNodo (Nodo* raiz, int n) {
    if (raiz == NULL) {
        return false;
    }
    else if (raiz->dato == n) {
        return true;
    }
    else if (n <= raiz->dato) {
        return buscarNodo(raiz->izq, n);
    }
    else {
        return buscarNodo(raiz->der, n);
    }
}

void Arbol::eliminarNodo (Nodo *&raiz, int n, bool &altura_arbol) {
    Nodo *aux_1;
    Nodo *aux_2;
    Nodo *tmp;
    bool band;

    if (raiz != NULL) {
        if (n > raiz->dato) {
            eliminarNodo(raiz->der, n, altura_arbol);
            restruct_derecha(raiz, altura_arbol);
        }
        else if (n <  raiz->dato) {
            eliminarNodo(raiz->izq, n, altura_arbol);
            restruct_izquierda(raiz, altura_arbol);
        }
        else {
            tmp = raiz;

            if(tmp->der == NULL){
                raiz = tmp->izq;
            }
            else {
                if (tmp->izq == NULL) {
                    raiz = tmp->der;
                }
                else{
                    aux_1 = raiz->izq;
                    band = false;

                    while (aux_1->der != NULL) {
                        aux_2 = aux_1;
                        aux_1 = aux_1->der;
                        band = true;
                    }
                    raiz->dato = aux_1->dato;
                    tmp = aux_1;

                    if (band == true) {
                        aux_2->der = aux_1->izq;
                    }
                    else{
                        raiz->izq = aux_1->izq;
                    }
                }
            }
        }
    }
}

