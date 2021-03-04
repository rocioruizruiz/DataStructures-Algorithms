#ifndef TREE_H
#define TREE_H

#include "node.h"
using namespace std;
#include <vector>


class Tree
{
public:
    Tree();
    void push(Data *d);
    Node* search(Node* n);
    void print();

    Node *getFirst() const;
/*
    void depthFirstRun() const;
    void breadthFirstRun() const;
*/
    void erase(Node* n) ;

protected:
    Node* first;
};

#endif // TREE_H
