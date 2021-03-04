//
//  node.cpp
//  Lista_Doble_Solita
//
//  Created by Rocio Ruiz Ruiz on 13/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "node.hpp"


Node::Node(Data* _d): next{nullptr}, prev{nullptr}, data{_d}
{
}

void Node::setNext(Node *p)
{
    next = p;
}

Node *Node::getNext() const
{
    return next;
}

void Node::setPrev(Node *p)
{
    prev = p;
}

Node *Node::getPrev() const
{
    return prev;
}
Data* Node::getDato()const{
    return data;
}

void Node::push_in_order(Data *d) { 
    
    Node* it;
    for(it = this; it != nullptr; it = it->getNext()){
        if(d->getModulo() < it->getDato()->getModulo()){
            Node* aux= new Node(d);
            it->getPrev()->setNext(aux);
            aux->setPrev(it->getPrev());
            aux->setNext(it);
            it->setPrev(aux);
        }
    }
}


