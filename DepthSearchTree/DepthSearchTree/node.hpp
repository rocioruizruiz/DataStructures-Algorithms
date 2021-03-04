//
//  node.hpp
//  DepthSearchTree
//
//  Created by Rocio Ruiz Ruiz on 11/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#ifndef node_hpp
#define node_hpp
#include "data.hpp"

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
    Node *getLeft() const;
    Node *getParent() const;
    Node *getRight() const;
    
    void pushIterative(Data d);
    void depthFirstRun() const;
    void printLevel(int setHeight) const;
    void eliminarNodo(Node*);
    void search(int);
    
protected:
    void push(Node* n);
    
    
protected:
    int height;
    Data* data;
    Node* parent;
    Node* left;
    Node* right;
};

bool operator == (Node const &n1, Node const &n2 );
bool operator >= (Node const &n1, Node const &n2 );
bool operator <= (Node const &n1, Node const &n2 );
bool operator > (Node const &n1, Node const &n2 );
bool operator < (Node const &n1, Node const &n2 );

std::ostream & operator << (std::ostream & os, Node const &d);

#endif 


