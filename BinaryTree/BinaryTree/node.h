#ifndef NODE_H
#define NODE_H

#include "data.h"

class Node
{

    friend bool operator == (Node const &n1, Node const &n2 );
    friend bool operator >= (Node const &n1, Node const &n2 );
    friend bool operator <= (Node const &n1, Node const &n2 );
    friend bool operator > (Node const &n1, Node const &n2 );
    friend bool operator < (Node const &n1, Node const &n2 );
    friend std::ostream & operator << (std::ostream & os, Node const &d);
    friend class Tree;

public:
    Node(Data* d);

    Data *getData() const;
    Node *getParent() const;
    void push(Node* n);
    void print();
    Node* search(Node* n);
    void printNode(Node* n)const;
    void erase(Node* n);
/*
    void breadthFirstRun();
*/
 


private:
    Data* data;
    Node* parent;
    Node* uno;
    Node* dos;
    Node* tres;
    Node* cuatro;

};

#endif // NODE_H
