//
//  estacion.hpp
//  TrabajoMetroMadrid
//
//  Created by Rocio Ruiz Ruiz on 17/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#ifndef estacion_hpp
#define estacion_hpp

#include "data.hpp"

#include <set>
#include <vector>
#include <iostream>
using namespace std;


class Node
{
    friend bool operator == (Node const & n1, Node const & n2);
    friend ostream & operator << (ostream & os, Node const & n);
    
    friend class Graph;
    
public:
    Node(Data *d, set<int> l);
    
    Data *getData() const;
    void setData(Data *value);
    
    set<int> getLines() const;
    void setLines(const set<int> &value);
    int getLine() const;
    void setLine(int value);
    
    set<Node *> getNeighbours() const;
    void setNeighbours(const set<Node *> &value);
    
    float getPathWeight() const;
    void setPathWeight(float value);
    
    Node *getPrev() const;
    void setPrev(Node *value);

    bool getVisited() const;

    int commonline(Node *n);
    void addNeighbour(Node *n);
    void addLine(int n);

    
protected:
    void printAll();
    void resetVisited();
    Node *computePath(Node* dest);
    Node* computeDijkstraPath(Node* dest, set<Node*> & allNodes, int);
    void printPath();
    
    
private:
    Data* data;
    set <int> lines;
    set<Node *> neighbours;

    
    bool visited;
    int  currentLine;
    Node* next;
    Node* prev;
    float pathWeight;
    float distanceTo(Node* n, int currentLine);
};

bool operator == (Node const & n1, Node const & n2);
ostream & operator << (ostream & os, Node const & n);


#endif /* estacion_hpp */
