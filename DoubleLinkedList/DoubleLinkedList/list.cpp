//
//  list.cpp
//  Lista_Doble_Solita
//
//  Created by Rocio Ruiz Ruiz on 13/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "list.hpp"
using namespace std;

List::List(): first{nullptr}, last{nullptr}, size{0}
{
}

void List::setFirst(Node *p) {
    first = p;
}

Node *List::getFirst() const { 
    return first;
}

void List::setLast(Node *p) {
    last = p;
}

Node *List::getLast() const { 
    return last;
}
unsigned int List::getSize() {
    return size;
}

void List::push_back(Data *dato) {
    Node* n = new Node(dato);
    if(last){
        n->setPrev(last);
        last->setNext(n);
        last = n;
    }else{
        first = n;
        last = n;
    }
    size++;
}

void List::push_between(Data *dato) {
    if(first && first->getNext() !=nullptr ){
        Node* n = new Node(dato);
        Node* aux = first;
        Node *it;
        for(it = first; it != nullptr; it = it->getNext()->getNext()){
            if(first->getNext()==last) continue;
            aux = aux->getNext();
            if(it->getNext() == nullptr){
                it = it->getPrev(); //gestion del error
            }
        }
        n->setNext(aux);
        n->setPrev(aux->getPrev());
        aux->getPrev()->setNext(n);
        n->getNext()->setPrev(n);
        size ++;

    }else{
        push_back(dato);
    }
}

void List::printList() {
    Node* it;
    for(it = first; it != nullptr; it = it->getNext()){
        cout << it->getDato()->getR() << " + " << it->getDato()->getI() <<" i " << endl;
       
    }
}
void List::printNode(Node *p)const {
    cout << "El nodo que buscas es: " <<  p  << endl;
}



Node *List::getMiddleNode(Node* first, unsigned int size)const {
    Node* it = first;
    for(int i=0; i < size/2 ; i++, it=it->getNext()){
    }
    return it;
}


Node* List::dicotomicSearch(Node* first, Node* last, Data* value, unsigned int size) {
    if(value->getR() == first->getDato()->getR()) return first;
    if(value->getR() == last->getDato()->getR()) return last;
    
    Node* middle = getMiddleNode(first, size);
    if(value->getR() == middle->getDato()->getR()) return middle;
    
    Node* newFirst, *newLast;
    
    if(value->getR() < middle->getDato()->getR()){
        newFirst = first;
        newLast = middle; //------------------------------------------------------
    }else{
        newFirst = middle;
        newLast = last; //--------------------------------------------------------
    }
    
    size = size / 2;
    return dicotomicSearch(newFirst, newLast, value, size);
}

void List::moveUp(Node *n)
{
    //node is already the first one, cannot be moved up
    if(n == first) return;
    
    //node is the last one
    if(n == last){
        if(n->getPrev() == first){ // Prev node is first. There are only 2 nodes
            first = n;
            last = n->getPrev();
            n->setPrev(nullptr);
            last->setNext(nullptr);
            first->setNext(last);
            last->setPrev(first);
        }else{
            last = n->getPrev();
            n->setPrev(last->getPrev());
            last->getPrev()->setNext(n);
            last->setPrev(n);
            last->setNext(nullptr);
            n->setNext(last);
            
        }
    }
    
    if(n != last){
        if(n->getPrev() != first){
            Node* aux1 = n->getPrev()->getPrev();
            Node* aux2 = n->getNext();
            n->getPrev()->setNext(aux2);
            aux2->setPrev(n->getPrev());
            aux1->setNext(n);
            n->setPrev(aux1);
            n->setNext(aux2->getPrev());
            n->getNext()->setPrev(n);
        }else{
            Node* aux = n->getNext();
            first->setNext(aux);
            aux->setPrev(first);
            n->setNext(first);
            n->setPrev(nullptr);
            first->setPrev(n);
            first = n;
        }
    }
}
void List::moveDown(Node *n) {
    //node is already the first one, cannot be moved up
    if(n == last) return;
    
    //node is the last one
    if(n == first){
        if(n->getNext() == last){ // Prev node is first. There are only 2 nodes
            last = n;
            first = n->getNext();
            n->setNext(nullptr);
            first->setPrev(nullptr);
            last->setPrev(first);
            first->setNext(last);
        }else{
            first = n->getNext();
            n->setNext(first->getNext());
            first->getNext()->setPrev(n);
            first->setNext(n);
            first->setPrev(nullptr);
            n->setPrev(first);
            
        }
    }
    
    if(n != first){
        if(n->getNext() != last){
            Node* aux1 = n->getNext()->getNext();
            Node* aux2 = n->getPrev();
            n->getNext()->setPrev(aux2);
            aux2->setNext(n->getNext());
            aux1->setPrev(n);
            n->setNext(aux1);
            n->setPrev(aux2->getNext());
            n->getPrev()->setNext(n);
        }else{
            Node* aux = n->getPrev();
            last->setPrev(aux);
            aux->setNext(last);
            n->setPrev(last);
            n->setNext(nullptr);
            last->setNext(n);
            last = n;
        }
    }
}


void List::bubbleSort()
{
    Node* it = first;
    
    while(it != nullptr){
        
        if(it == first){
            it = it->getNext();
            continue;
        }
        
        // if current node is smaller than previous
        
        Node* bubble = it;
        Node* prev = it->getPrev();
        if( bubble->getDato()->getR() < prev->getDato()->getR()){
            moveUp(it);
            continue;
        }
        
        it = it->getNext();
    }
}

void List::stoneSort()
{
    Node* it = last;
    while(it != nullptr){
        if(it == last){
            it = it->getPrev();
            continue;
        }
        Node* stone = it;
        Node* next = it->getNext();
        if( stone->getDato()->getR() > next->getDato()->getR()){
            moveDown(it);
            continue;
        }
        it = it->getPrev();
    }
}

void List::busca(Data* n){
    Node* aux1 = first;
    Node* aux2 = last;
    
    while (aux1 != aux2) {
        if (aux1->getDato()->getR() != n->getR() || aux1->getDato()->getI() != n->getI()) {
            cout << "izda = " << aux1->getDato()->getR() << " + " << aux1->getDato()->getI() <<" i " << endl;
            aux1=aux1->getNext();
            if (aux1 == aux2) { cout << "se acabo ... " << endl; return; }  // he acabado
        }
        else {
            cout << "encontrado !! " << aux1->getDato()->getR() << " + " << aux1->getDato()->getI() <<" i " << endl;
            return;                   // fin lo encontre
        }
        if (aux2->getDato()->getR() != n->getR() || aux2->getDato()->getI() != n->getI()) {
            cout << "dcha = " << aux2->getDato()->getR() << " + " << aux2->getDato()->getI() <<" i " << endl;
            aux2=aux2->getPrev();
            if (aux1 == aux2) { cout << "se acabo ... " << endl; return; }  // he acabado
        }
        else {
            cout << "encontrado !! " << aux2->getDato()->getR() << " + " << aux2->getDato()->getI() <<" i " << endl;
            return;                   // fin lo encontre
        }
    }
}


void List::push_in_order(Data *d)
{
    Node* n = new Node(d);    // ---- creo el node nuevo con el dato
    // miro si es el primer nodo a insertar ----
    if(first == nullptr){
        first = n;
        last = n;
        return;
    }
    // hay nodos, le digo al primero que lo inserte
    Node* puntero = first;
    // avanzo mientras el dato sea mayor que el nodo y no llegue al final
    while( d->getModulo() > puntero->getDato()->getModulo() && puntero->getNext()!=nullptr) {
        puntero = puntero->getNext();
    }
    // le tengo en el sitio -> puntero esta en el mayor/siguiente a donde tengo que meter al nuevo
    // si no hay mayor --> lo tengo que poner al final
    if (d->getModulo() <= puntero->getDato()->getModulo()) {
        // en cualquier otro caso -----
        n->setPrev(puntero->getPrev());   // el previo al nuevo es el anterior al mayor encontrado
        n->setNext(puntero);              // el siguiente del nuevo es el mayor encontrdo
        if(puntero->getPrev()) puntero->getPrev()->setNext(n);   // el anterior apunta al nuevo como posterior
        puntero->setPrev(n);              // el mayor apunta al nuevo como anterior
        // si el mayor es el first
        if (puntero==first) first = n;
        return;
    }
    // es el nuevo ultimo .....
    n->setPrev(last);
    last->setNext(n);
    last = n;
}
    
