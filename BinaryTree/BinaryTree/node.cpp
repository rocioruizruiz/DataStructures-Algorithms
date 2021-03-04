#include "node.h"
#include <iostream>
#include <vector>

using namespace std;

Node::Node(Data *d):
    data{d},
    parent{nullptr},
    uno{nullptr},
    dos{nullptr},
    tres{nullptr},
    cuatro{nullptr}
{

}

void Node::push(Node *n)
{
    if(n->getData()->getValue()%this->getData()->getValue() == 0 ){
        if(uno){
            uno->push(n);
        }else{
            uno = n;
            n->parent = this;
        }
    }
    if(this->getData()->getValue()%n->getData()->getValue() == 0){
        if(dos){
            dos->push(n);
        }else{
            dos = n;
            n->parent = this;
        }
    }
    if(n->getData()->getValue()%this->getData()->getValue() != 0 && this->getData()->getValue()%n->getData()->getValue() != 0 && n->getData()->getValue()%2 == 0){
        if(tres){
            tres->push(n);
        }else{
            tres = n;
            n->parent = this;
        }
    }
    if(n->getData()->getValue()%this->getData()->getValue() != 0 && this->getData()->getValue()%n->getData()->getValue() != 0 && n->getData()->getValue()%2 != 0){
        if(cuatro){
            cuatro->push(n);
        }else{
            cuatro = n;
            n->parent = this;
        }
    }
}
Data *Node::getData() const
{
    return data;
}

void Node::print() {
    cout << this->getData()->getValue() << endl;
    if(uno) uno->print();
    if(dos) dos->print();
    if(tres) tres->print();
    if(cuatro) cuatro->print();
}

Node *Node::search(Node *n) { 
    if(n->getData()->getValue()%this->getData()->getValue() == 0 ){
        if(uno){
            if(uno->getData()->getValue() == n->getData()->getValue()){
                return uno;
            }else{
                uno->search(n);
            }
        }
    }
    if(this->getData()->getValue()%n->getData()->getValue() == 0){
        if(dos){
            if(dos->getData()->getValue() == n->getData()->getValue()){
                return dos;
            }else{
                dos->search(n);
            }
        }
    }
    if(n->getData()->getValue()%this->getData()->getValue() != 0 && this->getData()->getValue()%n->getData()->getValue() != 0 && n->getData()->getValue()%2 == 0){
        if(tres){
            if(tres->getData()->getValue() == n->getData()->getValue()){
                return tres;
            }else{
                tres->search(n);
            }
        }
    }
    if(n->getData()->getValue()%this->getData()->getValue() != 0 && this->getData()->getValue()%n->getData()->getValue() != 0 && n->getData()->getValue()%2 != 0){
        if(cuatro){
            if(cuatro->getData()->getValue() == n->getData()->getValue()){
                return cuatro;
            }else{
                cuatro->search(n);
            }
        }
    }
    return nullptr;
}

void Node::printNode(Node* n) const{
    if(n){
        cout << "El nodo: " << n->getData()->getValue() << " tiene como hijos: " << endl;
        if(n->uno) cout << "En la rama 1: " << n->uno->getData()->getValue() << endl;
        if(n->dos) cout << "En la rama 2: " << n->dos->getData()->getValue() << endl;
        if(n->tres) cout << "En la rama 3: " << n->tres->getData()->getValue() << endl;
        if(n->cuatro) cout << "En la rama 4: " << n->cuatro->getData()->getValue() << endl;
    }
}

void Node::erase(Node *found){
    Node* arriba = found->parent;
    Node* prim = found->uno;
    Node* seg = found->dos;
    Node* ter = found->tres;
    Node* cuar = found->cuatro;
    if (found->getData()->getValue() == arriba->uno->getData()->getValue()) arriba->uno = nullptr;
    if (found->getData()->getValue() == arriba->dos->getData()->getValue()) arriba->dos = nullptr;
    if (found->getData()->getValue() == arriba->tres->getData()->getValue()) arriba->tres = nullptr;
    if (found->getData()->getValue() == arriba->cuatro->getData()->getValue()) arriba->cuatro = nullptr;
    found->uno = nullptr;
    found->dos = nullptr;
    found->tres = nullptr;
    found->cuatro = nullptr;
    delete found;
    
    if(prim) push(prim);
    if(seg) push(seg);
    if(ter) push(ter);
    if(cuar) push(cuar);
 }
/*
 void Node::breadthFirstRun() {
 vector<Node*> queue;
 queue.push_back(this);
 cout << this->getData()->getValue() << endl;
 for(int i{0}; i < queue.size(); i++){
 if(queue.at(i)->left) {queue.push_back(queue.at(i)->left);
 cout << "Izquierda:    " << queue.at(i)->left->getData()->getValue() << endl;}
 if(queue.at(i)->right){ queue.push_back(queue.at(i)->right);
 cout << "Derecha:    " << queue.at(i)->right->getData()->getValue() << endl;}
 }
 cout << "Arbol recorrido" << endl;
 }
 */

