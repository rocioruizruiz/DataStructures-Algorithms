//
//  list.hpp
//  Lista_Doble_Solita
//
//  Created by Rocio Ruiz Ruiz on 13/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#ifndef list_hpp
#define list_hpp
#include "node.hpp"

#include <iostream>
class List{
public:
    List();
    void setFirst(Node* p);
    Node* getFirst()const;
    void setLast(Node* p);
    Node* getLast()const;
    unsigned int getSize();
    void push_back(Data*);
    void push_between(Data*);
    Node* getMiddleNode(Node* first, unsigned int size)const;
    Node* dicotomicSearch(Node*, Node*, Data*, unsigned int );
    void printList();
    void printNode(Node*)const;
    void moveUp(Node *n);
    void moveDown(Node *n);
    void bubbleSort();
    void stoneSort();
    void iterate_right(Node* first, Node* last);
    void iterate_left(Node* first, Node* last);
    void busca(Data* n);
    void push_in_order(Data *d);
private:
    Node* first;
    Node* last;
    unsigned int size;
};

#endif /* list_hpp */
