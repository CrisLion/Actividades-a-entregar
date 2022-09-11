#include "ListaCD.hpp"
#include "Lista.hpp"

int main(){
    
    ListaCD<int>* l = new ListaCD<int>();

    l->push_back(1);
    l->push_back(2);
    l->push_back(3);
    l->addPos(45,1);
    l->modPos(21,1);
    l->deletePos(1);
    
    auto a = [] (int valor) -> void {std::cout<<valor<<" ";};
    l->displayList(a);
    


    delete l;
    

    return 0;
}