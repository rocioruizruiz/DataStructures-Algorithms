//
//  tree.cpp
//  DepthSearchTree
//
//  Created by Rocio Ruiz Ruiz on 11/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "tree.hpp"
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

Node *Tree::search(const Data &d)
{
    Node* it = first;
    
    while(it){
        if( *(it->data) == d) return it;
        else if( *(it->data) > d) it = it->left;
        else if( *(it->data) < d) it = it->right;
    }
    
    return nullptr;
}

Node *Tree::getFirst() const
{
    return first;
}

void Tree::depthFirstRun() const
{
    if(first) first->depthFirstRun();
}

Node *Tree::recursiveSearch(int d) const
{
    if(first) return first->search(d);
    else return nullptr;
}
void Tree::prune(Node *n)
{
    Node* p;
    // recorro el subarbol
    //TODO
 

}

void Tree::pushIterative(Data v) { 
    if (first) first->pushIterative(v);
}

