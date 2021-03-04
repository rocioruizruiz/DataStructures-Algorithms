//
//  tree.hpp
//  DepthSearchTree
//
//  Created by Rocio Ruiz Ruiz on 11/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include "node.hpp"
#include "data.hpp"

class Tree
{
public:
    Tree();
    void push(Data *d);
    void pushIterative(Data v);
    Node* search(Data const & d);
    
    Node *getFirst() const;
    void depthFirstRun() const;
    void breadthFirstRun() const;
    Node *recursiveSearch(int d) const;
    void prune(Node *n);
    

    
    
protected:
    Node* first;

};

#endif // TREE_H

