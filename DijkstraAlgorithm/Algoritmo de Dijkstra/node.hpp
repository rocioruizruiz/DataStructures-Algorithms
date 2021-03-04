//
//  node.hpp
//  Algoritmo de Dijkstra
//
//  Created by Rocio Ruiz Ruiz on 2/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#ifndef node_hpp
#define node_hpp
#define INFINITO 999

#include <iostream>
#include <math.h>

using namespace std;
class Node{
public:
    Node();
    Node(string name, int coorX, int coorY);
    int getX();
    int getY();
    string getNombre();
    int calcularDistancia(Node* x, Node* y);
    
    
    


    int  predecesor;    //  nodo previo
    int  distancia;     // distancia minima del origen a este nodo
    bool permanente;    //Verdadero para un nodo permanente (fijo) y falso para un nodo temporal.
private:
    int x, y;
    string nombre;

};

#endif /* node_hpp */
