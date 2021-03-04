//
//  grafo.cpp
//  Algoritmo de Dijkstra
//
//  Created by Rocio Ruiz Ruiz on 2/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "grafo.hpp"
#include <math.h>

Grafo::Grafo(int num_nodos)
{
    nodos = num_nodos;
}
void Grafo::setNombre(int nodoi, string name)
{
    nombre[nodoi] = name;
}
string Grafo::getNombre(int nodoi)
{
    return(nombre[nodoi]);
}
void Grafo::setDistancia(int nodoi, int nodof, int dist)
{
    distancia[nodoi][nodof] = dist;
    distancia[nodof][nodoi] = dist;
}
int Grafo::getDistancia(int nodoi, int nodof)
{
    return(distancia[nodoi][nodof]);
}
int Grafo::caminoCorto(int nodoi, int nodof)
{

   // INICIALIZAR LOS NODOS PARA LAS ITERACIONES
    for (int i{0}; i<nodos; i++)
       myNodo[i] = new Node();
   
   // ALGORITMO DE DIJKSTRA
    myNodo[nodof]->predecesor=-1 ;     // no haria falta porque ya viene del constructor, pero aclara
    myNodo[nodof]->distancia  =  0;
    myNodo[nodof]->permanente =  true;
   // EMPEZAMOS POR EL NODO INICIAL
   int p = nodof;             // calculo de nodof a nodoi para asi poder pintar luego la ruta contraria
   do{
       // DISTANCIA MINIMA -> Distancia nueva acumulada<anterior (d[k]+distancia[k,i]<d[i] -> d[i]=d[k]+d[k,i])
       calcular(p);
       // COJO EL NODO NO PERMANENTE CON DISTANCIA MINIMA MENOR Y LE HAGO PERMANENTE
       p = get_minimo();
       myNodo[p]->permanente = true;
   } while (p != nodoi);
   
   // USO PREDECESOR PARA MOSTRAR LA RUTA Y DEVOLVER LA DISTANCIA MINIMAS
   int i = 0; p = nodoi;
   cout<< "La ruta es: ";
   do {
       cout<< p << " ";
       ruta[i] = p;
       p = myNodo[p]->predecesor;
       i++;
   } while (p >= 0);
   cout << endl;
   coste = myNodo[nodoi]->distancia;
   return coste;  // coste = distancia minima de Nodoi a Nodof
}
void Grafo::calcular(int p)  // distancias acumuladas del nodo p (ultimo permanente) al resto de nodos temporales
{
   for (int i = 0; i <nodos; i++){ // para cada nodo */
       if (distancia[p][i] != 0 && myNodo[i]->permanente == false) {
           if (myNodo[p]->distancia + distancia[p][i] < myNodo[i]->distancia) {
               myNodo[i]->predecesor = p;
               myNodo[i]->distancia = myNodo[p]->distancia + distancia[p][i];
           }
       }
   }
}
int Grafo::get_minimo()     // Selecciona el nodo NO-PERMANENTE con la minima distancia acumulada
{
   int k = 0;
   int minimo = INFINITO;
   for (int i = 0; i < nodos; i++){
       if (myNodo[i]->permanente == false && myNodo[i]->distancia < minimo) {
           minimo = myNodo[i]->distancia;
           k = i;
       }
   }
   return k;
}


//_______________________________________________________________________________________

