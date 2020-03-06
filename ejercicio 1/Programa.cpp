#include <iostream>

#include "Grafo.h"
#include "Arbol.h"

using namespace std;

int main () {
    Arbol arbol = Arbol();
    Nodo *raiz = NULL;
    bool altura_arbol;
    int opcion;
    int dato;
    bool band;

    do {
        cout << "1. Insertar un nuevo nodo " << endl;
        cout << "2. Eliminar un nodo " << endl;
        cout << "3. Modificar un nodo " << endl;
        cout << "4. Mostrar grafo " << endl;
        cout << "5. Salir " << endl;
        cin >> opcion;
        system("clear");

        switch (opcion) {
            case 1: cout << "Escriba un numero: " << endl;
                    cin >> dato;
                    if (arbol.buscarNodo(raiz, dato) == false) {
                        arbol.insertarNodo(raiz, dato, altura_arbol);
                        cout << "El nodo se ingreso correctamente" << endl;
                    }
                    else {
                        cout << "El nodo ya existe" << endl;
                    }
                    break;
            case 2: cout << "Escriba el numero del nodo a eliminar: " << endl;
                    cin >> dato;
                    if (arbol.buscarNodo(raiz, dato) == false) {
                        cout << "El nodo no existe" << endl;
                    }
                    else {
                        arbol.eliminarNodo(raiz, dato, altura_arbol);
                        cout << "El nodo se elimino correctamente" << endl;
                    }

                    break;
            case 3: cout << "Escriba el numero del nodo a modificar: " << endl;
                    cin >> dato;
                    if (arbol.buscarNodo(raiz, dato) == false) {
                        cout << "El nodo no existe" << endl;
                    }
                    else {
                        arbol.eliminarNodo(raiz, dato, altura_arbol);
                        bool continuar = false;

                        while (continuar == false) {
                            cout << "Escriba el numero del nuevo nodo: " << endl;
                            cin >> dato;

                            if (arbol.buscarNodo(raiz, dato) == false) {
                                arbol.insertarNodo(raiz, dato, altura_arbol);
                                cout << "El nodo se ingreso correctamente" << endl;
                                continuar = true;
                            }
                            else {
                                cout << "El nodo ya existe, ingrese otro numero" << endl;
                            }
                        }
                    cout << "El nodo se modifico correctamente" << endl;
                    }

                    break;
            case 4:
                    Grafo *grap = new Grafo(raiz);
                    grap->crearGrafo();
                    break;
        }
    }while (opcion != 5);

    return 0;
}

