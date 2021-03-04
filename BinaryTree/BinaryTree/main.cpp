#include <iostream>
#include <time.h>

#include "tree.h"

using namespace std;

int main()
{
    
    Tree tree;
    tree.push(new Data(20));
    tree.push(new Data(15));
    Node* n = new Node(new Data(80));
    tree.push(n->getData());
    Node* t = new Node(new Data(10));
    tree.push(t->getData());
    tree.push(new Data(40));
    tree.push(new Data(30));
    tree.push(new Data(160));
    tree.push(new Data(5));
    tree.push(new Data(4));
    
    tree.print();
    cout << "-------------" << endl;
    Node* resultado = tree.search(n);
    cout << "El nodo: " << resultado->getData()->getValue() << " es ----> " << resultado << endl;
    resultado->printNode(resultado);
    Node* found = tree.search(t);
    cout << "El nodo: " << found->getData()->getValue() << " es ----> " << found << endl;
    found->printNode(found);

    tree.erase(n);
    tree.print();
    
    return 0;
}
