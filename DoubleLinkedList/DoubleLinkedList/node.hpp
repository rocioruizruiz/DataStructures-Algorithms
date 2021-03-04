//
//  node.hpp
//  Lista_Doble_Solita
//
//  Created by Rocio Ruiz Ruiz on 13/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <iostream>
#include "data.hpp"
class Node{
public:
    Node(Data*);
    void setNext(Node* value);
    Node* getNext()const;
    void setPrev(Node* value);
    Node* getPrev()const;
    Data* getDato()const;
    void printNode(Node*)const;

    void push_in_order(Data *d);
    
    
private:
    Node* next;
    Node* prev;
    Data* data;
    
};




#endif /* node_hpp */
