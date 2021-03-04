//
//  metro.hpp
//  TrabajoMetroMadrid
//
//  Created by Rocio Ruiz Ruiz on 17/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#ifndef metro_hpp
#define metro_hpp

#include <iostream>
#include <vector>

#include "estacion.hpp"
using namespace std;
#include "estacion.hpp"
#include <set>
#include <vector>

using namespace std;

class Graph
{
public:
    Graph(Node* entryPoint = nullptr);
    void printAll();
    
    void printPath(int id_dest, bool dijkstra = true);
    
    bool computeDijkstraPath(Node* dest);
    
    vector<Node*> getPath(Node* dest);
    
    void addNode(int id, string name, set <int> lines);
    bool addNodeLine(int id, int line);
    Node * searchNode(int id);
    bool existNode(int id);
    void link(int id1, int id2, bool twoWay = false);
    void setEntryPoint(int id);
    
private:
    Node* entryPoint;
    bool computePath(Node* dest);
    set<Node*> allNodes;
    
    
};


#endif /* metro_hpp */
