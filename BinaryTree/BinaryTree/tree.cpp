#include "tree.h"

Tree::Tree():
    first{nullptr}
{

}

void Tree::push(Data* d)
{
    Node* n = new Node(d);
    if(!first)
        first = n;
    else
        first->push(n);
}

void Tree::print()
{
    if(first) first->print();
}

Node *Tree::search(Node* n)
{
    if(first) {
        Node* found = first->search(n);
        if(found){
            return found;
        }
    }
    return nullptr;
}

void Tree::erase(Node* n){
    Node* found = search(n);
    if(first && found) first->erase(found);
}

/*
void Tree::breadthFirstRun() const {
    if (first) first->breadthFirstRun();
}
*/


