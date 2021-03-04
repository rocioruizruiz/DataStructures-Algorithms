//
//  node.cpp
//  Algoritmo de Dijkstra
//
//  Created by Rocio Ruiz Ruiz on 2/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "node.hpp"


Node::Node()
    {
        predecesor = -1;
        distancia  = INFINITO;
        permanente = false;
    }

Node::Node(std::string name, int coorX, int coorY) {
    nombre = name;
    x = coorX;
    y = coorY;
    predecesor = -1;
    distancia  = INFINITO;
    permanente = false;
}

int Node::getX() {
    return x;
}

int Node::getY() {
    return y;
}

int Node::calcularDistancia(Node* x, Node* y) {
    return sqrt((y->getX()-x->getX())*(y->getX()-x->getX())+(y->getY()-x->getY())*(y->getY()-x->getY()));
}

string Node::getNombre() {
    return nombre;
}



