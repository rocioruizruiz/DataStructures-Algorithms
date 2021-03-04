//
//  estacion.cpp
//  TrabajoMetroMadrid
//
//  Created by Rocio Ruiz Ruiz on 17/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "estacion.hpp"
#include <limits>

#include <stdlib.h>

Node::Node(Data* d, set<int> l):
    data{d},
    visited{false},
    next{nullptr},
    prev{nullptr},
    pathWeight{std::numeric_limits<float>::max()},
    currentLine{0},
    lines{l}
{}

Data *Node::getData() const
{
    return data;
}

void Node::setData(Data *value)
{
    data = value;
}

set<Node *> Node::getNeighbours() const
{
    return neighbours;
}

void Node::setNeighbours(const set<Node *> &value)
{
    neighbours = value;
}

void Node::addNeighbour(Node * n)
{
    neighbours.insert(n);
}

set<int> Node::getLines() const {
    return lines;
}

int Node::getLine() const {
    return currentLine;
}

void Node::setLines(const set<int> &value) {
    lines = value;
}

void Node::setLine(int value) {
    currentLine = value;
}

void Node::addLine(int n)
{
    lines.insert(n);
}

void Node::printAll(){
    
    if(visited) return;
    visited = true;
    // imprime estacion y correspondencias
    cout << *data;
    cout << " correspondencia con lineas: ";
    for (auto l:lines) cout << l << " ";
    cout << endl;
    // recursivo al resto de vecinos
    for(auto n:neighbours)
        n->printAll();
}

void Node::resetVisited(){
    
    // set path weight to max for next search
    pathWeight = std::numeric_limits<float>::max();
    
    if(!visited) return;
    visited = false;
    for(auto n:neighbours)
        n->resetVisited();
}

Node* Node::computePath(Node *dest)
{
    if(visited) return nullptr;
    
    next = nullptr;
    visited = true;
    
    if(dest == this) return this;
    
    for(auto p:neighbours){
        Node* aux = p->computePath(dest);
        if(aux){
            next = p;
            aux->setLine(aux->commonline(this));
            return aux;
        }
    }
    return nullptr;
}

Node *Node::computeDijkstraPath(Node *dest, set<Node *> &allNodes, int tripline)
{
    // node should never be previously visited when used to compute Dijkstra Path
    if(visited) throw string{"This should not happen"};
    
    visited = true;
    if (this == dest) return this;
    
    // set weight and prev for all neighbours
    for(auto n: neighbours){
        const float dist = pathWeight + distanceTo(n, tripline);
        // if distance form thi node is smaller than stablished distance
        if(dist < n->getPathWeight()){
            n->setPathWeight(pathWeight + distanceTo(n, tripline));
            n->setPrev(this);
            n->setLine(n->commonline(this));  // VOY DEJANDO PISTA DE LA LINEA POR LA QUE PASO
        }
    }
    
    // get next neighbour to keep looking
    // minimum weight non visited node
    
    Node* aux = nullptr;
    float dist = std::numeric_limits<float>::max();
    
    for(auto p: allNodes){
        if(!p->getVisited() && p->getPathWeight() < dist){
            aux = p;
            dist = p->getPathWeight();
        }
    }
    if(aux) {
        tripline = aux->getLine();   // actualizo tripline que indica el curso del viaje
        return aux->computeDijkstraPath(dest, allNodes, tripline);
    }
    throw string{"Path not found"};
}

float Node::distanceTo(Node *n, int tripline)
{
    for (auto l: n->lines){
        if (!tripline || l == tripline) return (1);
    }
    return (3);
}

int Node::commonline(Node *n)
{
    for (auto l: n->lines){
        for(auto p: this->lines){
            if(l == p) return l;
        }
    }
    cout << "esto no deberia escribirse" << endl;
    return -1;
}

void Node::printPath()
{
    cout << " -> " << currentLine << " - ";
    cout << *data;
    if(next) next->printPath();
}

bool Node::getVisited() const
{
    return visited;
}

Node *Node::getPrev() const
{
    return prev;
}

void Node::setPrev(Node *value)
{
    prev = value;
}

float Node::getPathWeight() const
{
    return pathWeight;
}

void Node::setPathWeight(float value)
{
    pathWeight = value;
}

bool operator ==(const Node &n1, const Node &n2)
{
    return (*(n1.data) == *(n2.data));
}

ostream &operator <<(ostream &os, const Node &n)
{
    os << *(n.data);
    return os;
}
