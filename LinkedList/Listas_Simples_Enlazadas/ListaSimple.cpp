//
//  ListaSimple.cpp
//  Listas_Simples_Enlazadas
//
//  Created by Rocio Ruiz Ruiz on 27/1/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "ListaSimple.hpp"

using namespace std;

ListaSimple::ListaSimple(int n){   // CONSTRUCTOR -----------
    data = n;
    next = nullptr;
}
void ListaSimple::push_back(int valor){
    ListaSimple *punteroL1 = this;
    while(punteroL1->next != nullptr) punteroL1 = punteroL1->next; // me lleva hasta el ultimo
    punteroL1->next = new ListaSimple(valor);
    this->size++; //te suma al primero y los demas size=1;
}

ListaSimple * ListaSimple::at(int i){
    ListaSimple *aux=this;
    if (i<1) return NULL ;   // ERROR -> no existe -> devuelve null
    for(int j{1}; j < i; j++){
        if (aux) aux = aux->next;  // si hay, avanza hasta la posicion
    }
    return aux;                 // devuelve aux, que es el que busca
}

void ListaSimple::push_front(int valor){
    ListaSimple *aux;
    aux = new ListaSimple{valor};
    aux->next = this->next;
    this->next = aux;
}
int ListaSimple::search(int ele)const{
    int i=1, j;
    if (data != ele) {
        if(next == nullptr) return -1;
        else {
            j=next->search(ele);
            if (j==-1) i=-1; else i+=j;
        }
    }
    return i;
}
void ListaSimple::print(){
    cout << data << endl;
    if(next) next->print();
}
bool ListaSimple::erase(int j){ //no elimina el primero
    ListaSimple * aux = this, * prev = nullptr;
    int i{1};
    if(j <= 1) return false; // no existe o es el primero
    while(i != j){
        prev= aux;
        aux = aux->next;
        i++;
    }
    if (prev) prev->next = aux->next;
    delete aux;
    return true;
}
ListaSimple * ListaSimple::getNext(){
    return next;
}
int ListaSimple::getData()const{
    return data;
}
void ListaSimple::move(int i, int j){   // i no puede ser 1;
    int k{1};
    ListaSimple * prev = nullptr, * nodo_i = nullptr;
    ListaSimple * aux = this;
    if (i > 2 || j < i) return;
    while(k <= j){
        if(k == i){
            nodo_i = aux;
            prev->next = aux->next;
        }
        if(k == j){
            nodo_i->next= aux->next;
            aux->next = nodo_i;
        }
        prev= aux;
        aux = aux->next;
        k++;
    }
}
int  ListaSimple::getSize(){
    return size;
}
/*void insert(ListaSimple *ref, int value, unsigned int pos){
    if(pos > ref->getSize()) throw string{""};
    ListaSimple * aux = ref->at(pos);
    ListaSimple * nuevo = new ListaSimple{value};
    nuevo->getNext() = aux->getNext();
    aux->getNext() = nuevo;
}
 */

ListaSimple * ListaSimple::greater_than(int value)const{
    ListaSimple *aux = new ListaSimple{0};
    ListaSimple *punteroL1 = this->next;
    ListaSimple *punteroL2 = aux;
    while(punteroL1 != nullptr){
        if(punteroL1->getData() > value){
            punteroL2->next = new ListaSimple{punteroL1->getData()};
            punteroL2 = punteroL2->next;
        }
        punteroL1 = punteroL1->next;
    }
    return aux;
}
ListaSimple * ListaSimple::equal_to(int value)const{
    ListaSimple *aux = new ListaSimple{0};
    ListaSimple *punteroL1 = this->next;
    ListaSimple *punteroL2 = aux;
    while(punteroL1 != nullptr){
        if(punteroL1->getData() == value){
            punteroL2->next = new ListaSimple{punteroL1->getData()};
            punteroL2 = punteroL2->next;
        }
        punteroL1 = punteroL1->next;
    }
    return aux;
}
ListaSimple * ListaSimple::lesser_than(int value)const{
    ListaSimple *aux = new ListaSimple{0};
    ListaSimple *punteroL1 = this->next;
    ListaSimple *punteroL2 = aux;
    while(punteroL1 != nullptr){
        if(punteroL1->getData() < value){
            punteroL2->next = new ListaSimple{punteroL1->getData()};
            punteroL2 = punteroL2->next;
        }
        punteroL1 = punteroL1->next;
    }
    return aux;
}
ListaSimple * ListaSimple::within_interval(int a, int b)const{
    ListaSimple *aux = new ListaSimple{0};
    ListaSimple *punteroL1 = this->next;
    ListaSimple *punteroL2 = aux;
    if(a > b) return aux;                                               // si a>b entonces devuelve un HEAD solo
    while(punteroL1 != nullptr){
        if(punteroL1->getData() >= a && punteroL1->getData() <= b){     // esta dentro del intervalo
            punteroL2->next = new ListaSimple{punteroL1->getData()};
            punteroL2 = punteroL2->next;
        }
        punteroL1 = punteroL1->next;
    }
    return aux;
}
void ListaSimple::deleteAll(){
    if (next) next->deleteAll();
    delete this;
}
void ListaSimple::printAll()const{
    ListaSimple *puntero = this->next;
    int i=0;
    
    cout << "hay " << this->size << " elementos en la lista" << endl;
    while(puntero != nullptr) {
        cout << ++i << ": " << puntero->getData() << endl;
        puntero = puntero->next;
    }
}
void ListaSimple::print()const{
    if (next) next->print();
    cout << data << endl;
}

ListaSimple * ListaSimple::getNext()const{
    return next;
}
void ListaSimple::setData(int i){
    data = i;
}
void ListaSimple::setNext(ListaSimple *puntero){
    next = puntero;
}
ListaSimple * ListaSimple::getPares()const{
    ListaSimple *aux = new ListaSimple{0};
    ListaSimple *punteroL1 = this->next;
    ListaSimple *punteroL2 = aux;
    while(punteroL1 != nullptr){
        if(punteroL1->getData() % 2 == 0){
            punteroL2->next = new ListaSimple{punteroL1->getData()};
            punteroL2 = punteroL2->next;
        }
        punteroL1 = punteroL1->next;
    }
    return aux;
}
/*ListaSimple * ListaSimple::eliminarPares(){
    
    
    return aux;
}
void ListaSimple::recorreLaLista(){
    for(ListaSimple* it = list.getNext(); it != nullptr; it = it->getNext())
}*/
    

    
    
    
    //ListaSimple *ListaSimple::remove_duplicates(){
    
    //}
    
    //    SEARCH No recursivo ---------------
    //    ListaSimple * aux;
    //    int dato = data, i=1;
    //    while (dato != ele) {
    //        i++;
    //        aux = next;
    //        dato = aux->data;
    //    }
    //    return i;
    
    
    
    


