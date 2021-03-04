//
//  node.cpp
//  DepthSearchTree
//
//  Created by Rocio Ruiz Ruiz on 11/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "node.hpp"
#include <iostream>

using namespace std;


Node::Node(Data *d):
data{d},
parent{nullptr},
left{nullptr},
right{nullptr}
{
    
}

void Node::push(Node *n)
{
    if( *n > *this){
        if(right)
            right->push(n);
        else{
            right = n;
            n->parent = this;
        }
    }else{
        if(left)
            left->push(n);
        else{
            left = n;
            n->parent = this;
        }
    }
}

Node *Node::getRight() const
{
    return right;
}

void Node::depthFirstRun() const
{
    cout << *(this) << endl;
    if(left) left->depthFirstRun();
    if(right) right->depthFirstRun();
    
}


Node *Node::getParent() const
{
    return parent;
}

Node *Node::getLeft() const
{
    return left;
}

void Node::eliminarNodo(Node* n)
{
     
}
void Node::search(int d)
{
    
}

Data *Node::getData() const
{
    return data;
}

void Node::pushIterative(Data d) {
    Node* aux = new Node(d);
    if(!parent){
        parent = new Node(d);
        return;
    }
    Node* it = parent;
    while(true){
        if(it->getData()->getValue() > d.getValue()){
            if(it->getRight()){
            }else{
                it->getRight() = aux;
                aux->parent = it;
                return;
            }
        }else{
            if(it->getLeft()){
            }else{
                it->getLeft() = aux;
                aux->parent = it;
                return;
        }
    }
    
    }
    
}


bool operator ==(const Node &n1, const Node &n2)
{
    return ( *(n1.data) == *(n2.data));
}

bool operator <=(const Node &n1, const Node &n2)
{
    return ( *(n1.data) <= *(n2.data));
}

bool operator >=(const Node &n1, const Node &n2)
{
    return ( *(n1.data) >= *(n2.data));
}

bool operator >(const Node &n1, const Node &n2)
{
    return ( *(n1.data) > *(n2.data));
}

bool operator <(const Node &n1, const Node &n2)
{
    return ( *(n1.data) < *(n2.data));
}

std::ostream &operator <<(std::ostream &os, const Node &d)
{
    os << *(d.data);
    return os;
}
