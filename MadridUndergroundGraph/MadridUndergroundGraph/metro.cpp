//
//  metro.cpp
//  TrabajoMetroMadrid
//
//  Created by Rocio Ruiz Ruiz on 17/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "metro.hpp"
#include <limits>
#include <vector>

using namespace std;

Graph::Graph(Node *entryPoint):
entryPoint{entryPoint}
{
}

void Graph::setEntryPoint(int id)
{
    Node * aux = searchNode(id);
    entryPoint = aux;
}

void Graph::addNode(int id, string name, set <int>lines)
{
    Node *n = new Node(new Data(id, name), {lines});
    // insert node in the allNodes set 
    allNodes.insert(n);
}
void Graph::link(int id1, int id2, bool twoWay)
{
    Node *n1 = searchNode(id1);
    Node *n2 = searchNode(id2);
    
    if(!n1 || !n2) throw string{"One of the nodes is invalid"};
    
    // linka los nodos como neighbourgs
    n1->addNeighbour(n2);
    if(twoWay) n2->addNeighbour(n1);
}
bool Graph::addNodeLine(int id, int line)
{
    Node *aux = searchNode(id);
    if (aux) {
        aux->addLine(line);
        return true;
    }
    return false;
}
Node * Graph::searchNode(int id)
{
    // le busca y si le encuentra devuelve su direccion 
    for(auto i:allNodes){
        if(i->getData()->getID() == id) return i;
    }
    return nullptr;
}

bool Graph::existNode(int id)
{
 
    for(auto i:allNodes){
        if(i->getData()->getID() == id) return true;
    }
    return false;
}

void Graph::printAll()
{
    if(!entryPoint) throw string{"No entry point"};
    
    if(entryPoint){
        entryPoint->resetVisited();
        entryPoint->printAll();
    }
    
}

void Graph::printPath(int id_dest, bool dijkstra)
{
    Node *dest = searchNode(id_dest);
    
    if(dijkstra){
        if(computeDijkstraPath(dest)){
            vector<Node*> path = getPath(dest);
            for(int i = path.size() -1 ; i >= 0 ; i-- ){
                if (i<(path.size()-1)) cout << " line " << path.at(i)->getLine();
                if (i<(path.size()-1)) cout << " -  coste acumulado: " << path.at(i)->getPathWeight();
                cout << " - " << *(path.at(i)->getData());
            }
            cout << endl;
        }
    }else{
        if(computePath(dest)){
            entryPoint->printPath();
            cout << endl;
        }else {
            cout << "No Path found" << endl;
        }
    }
}

bool Graph::computeDijkstraPath(Node *dest)
{
    if(!entryPoint) throw string{"No entry point"};
    
    entryPoint->resetVisited();
    entryPoint->setPathWeight(0);
    
    entryPoint->computeDijkstraPath(dest,allNodes,0);
    
    // if path found, weight must be limited
    if(dest->getPathWeight() < std::numeric_limits<float>::max())
        return true;
    
    return false;
    
}

vector<Node *> Graph::getPath(Node *dest)
{
    vector<Node*> path;
    Node* aux = dest;
    do{
        if(!aux) throw string{"This should not happen"};
        path.push_back(aux);
        aux = aux->getPrev();
    } while(aux);
    
    return path;
}

bool Graph::computePath(Node *dest)
{
    if(!entryPoint) throw string{"No entry point"};
    
    entryPoint->resetVisited();
    
    if(entryPoint->computePath(dest))
        return true;
    
    return false;
}

