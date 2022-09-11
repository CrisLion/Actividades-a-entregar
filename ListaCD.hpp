#include "Nodo.hpp"
#include <functional>
template<typename T>
class ListaCD{ //Lista circular doblemente enlazada
private:
    Nodo<T>* _cabeza;
    Nodo<T>* _cola;
    unsigned int _n;
public:
    ListaCD() : _cabeza(nullptr), _cola(nullptr), _n(0) {}
    ~ListaCD() { while (_cabeza != nullptr) pop_back();}

    void push_back(const T& valor){ //O(1)
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);// 1
        if (_n == 0){// 1
            _cabeza = _cola = nuevoNodo; // 2
            nuevoNodo->_anterior = nuevoNodo; // 2
            nuevoNodo->_siguiente = nuevoNodo;// 2
            ++_n; // 2 
            return;
        }
        nuevoNodo->_anterior = _cola; // 2
        nuevoNodo->_siguiente = _cabeza; // 2
        _cabeza->_anterior = nuevoNodo; // 2
        _cola->_siguiente = nuevoNodo; // 2
        _cola= nuevoNodo; // 1
        ++_n; // 2
    } // Analisis Detallado max(1 +2 +2 +2 +2 , 2 +2 +2 +2+1+2) +1 = 11 +1 = 12
      // Analisis Asintotico = O(1)

    void pop_back(){   
        if (_n != 0){// 0  ->  0 -> nu
            Nodo<T>* aux = _cola;
            if (_n == 1){
                _cola = _cabeza = nullptr;
                delete aux;
                --_n;
                return;
            }
            _cola->_anterior->_siguiente = _cabeza;
            _cola = _cola->_anterior;
            _cabeza->_anterior = _cola;
            delete aux;
            --_n;
        }
    }

    void modified_last(const T& element) {
        pop_back();
        push_back(element);
    }

    void modPos(const T& element, const int& pos) {
        if (pos < _n && pos >= 0 && _cabeza != nullptr) {  
            unsigned int count = 0;
            for (Nodo<T>*i = _cabeza; i != nullptr; i = i->_siguiente){
                if (count == pos) {
                    i->_dato = element;
                    return;
                }
                count++;
            }
        }
    }

    void deletePos(const int& pos){
        if (pos < _n && pos >= 0 && _cabeza != nullptr) {  
            unsigned int count = 0;
            for (Nodo<T>*i = _cabeza; i != nullptr; i = i->_siguiente){
                if (count == pos) {
                    i->_anterior->_siguiente = i->_siguiente;
                    i->_siguiente->_anterior = i->_anterior;
                    delete i;
                    return;
                }
                count++;
            }
        }
    }

    void addPos(const T& element, const int& pos){

        if (pos < _n && pos >= 0 && _cabeza != nullptr) {  
            unsigned int count = 0;
            for (Nodo<T>*i = _cabeza; i != nullptr; i = i->_siguiente){
                if (count == pos) {
                    Nodo<T>* newNode = new Nodo<T>(element);  
                    newNode->_siguiente = i->_siguiente;
                    newNode->_anterior = i;
                    i->_siguiente = newNode;
                    return;
                }
                count++;
            }
        }
    }

    void displayList(std::function<void(T)> printNodeValue){ // [] (T valor) -> void {std::cout<<valor<<" ";};
        Nodo<T>* aux = _cabeza;
        while(aux != nullptr){
            printNodeValue(aux->_dato);
            aux = aux->_siguiente;
        }
        std::cout<<std::endl;     
    }

    unsigned int size(){
        return _n;
    }

    T get_cabeza(){
        return _cabeza->_dato;
    }

    T get_cola(){
        return _cola->_dato;
    }
 
    
};