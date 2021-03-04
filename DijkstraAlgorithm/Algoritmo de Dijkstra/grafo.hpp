//
//  grafo.hpp
//  Algoritmo de Dijkstra
//
//  Created by Rocio Ruiz Ruiz on 2/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//
#define MAX_NODOS 10

#ifndef grafo_hpp
#define grafo_hpp
#include <iostream>
#include <array>
#include "node.hpp"
using namespace std;
class Grafo{
public:
    Grafo(int num_nodes);
    void setNombre(int nodoi, string name);
    string getNombre(int nodoi);
    float calcularDistancia(int x, int y);
    void setDistancia(int nodoi, int nodof, int distancia);
    int getDistancia(int nodoi, int nodof);
    int caminoCorto(int nodoi, int nodof);
    int get_minimo();
    void calcular(int k);
    
private:
    int nodos;
    array <string, MAX_NODOS> nombre;     // nombre de los nodos
    array <array <int, MAX_NODOS>,MAX_NODOS> distancia;     // distancias entre nodos
    array <Node *, MAX_NODOS> myNodo;             // para el algoritmo de DIJKSTRA
    array <int, MAX_NODOS> ruta;                 // camino
    int coste;                         // coste minimo del recorrido
    
};

#endif /* grafo_hpp */
