#include <iostream>

using namespace std;

class Arbol {
    private:
        bool altura_arbol;

    public:
		Arbol();
        Nodo* crearNodo (int);
        void restruct_izquierda(Nodo *&, bool);
        void restruct_derecha(Nodo *&, bool);
        void insertarNodo (Nodo *&, int, bool &);
        void eliminarNodo (Nodo *&, int, bool &);
        bool buscarNodo (Nodo* , int);
};
