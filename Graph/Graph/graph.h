#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"

class Graph
{
public:
    Graph(Node* entryPoint = nullptr);
    void printAll();
    void link(Node* n1, Node* n2, bool twoWay = false);
    void printPath(Node* dest);
    void dephtFirstSearch();
    void breadthFirstSearch();
    
    /*
     En el quick sort necesitamos hacer un DFS o BFS para determinar en pivote central.
     Lo colocamos en el centro y empezamos una busqueda bidireccional en la que comparas cada elemento de cada direccion dejando los mayores que el pivote a un lado y los menores que el pivote al otro lado.
     Una vez cada dirección se encuentra en el centro, tomamos las dos sublistas y ordenamos bidireccionalmente.
    */

private:
    Node* entryPoint;
    bool computePath(Node* dest);

};

#endif // GRAPH_H
