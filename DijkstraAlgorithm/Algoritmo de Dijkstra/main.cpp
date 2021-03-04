//
//  main.cpp
//  Algoritmo de Dijkstra
//
//  Created by Rocio Ruiz Ruiz on 2/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include <iostream>
#include "node.hpp"
#include "grafo.hpp"
using namespace std;

int main()
{
    int nodos = 5;        // NUMERO DE NODOS EN ESTE EJEMPLO
    Grafo myGrafo(nodos);   // tengo un grafo con 5 nodos
    
    // DAR NOMBRE A LOS NODOS DEL GRAFO --
    myGrafo.setNombre(0,"A");
    myGrafo.setNombre(1,"B");
    myGrafo.setNombre(2,"C");
    myGrafo.setNombre(3,"D");
    myGrafo.setNombre(4,"E");
    myGrafo.setNombre(5,"F");
    myGrafo.setNombre(6,"G");
    
    // INICIALIZAR DISTANCIAS A CERO  ----
    for (int i=0; i < nodos; i++) {
        for (int j=0; j < nodos; j++) {
            myGrafo.setDistancia(i,j,0);
        }
    }

    float distanciaAC, distanciaAF, distanciaAB, distanciaBF, distanciaBD, distanciaCE, distanciaCF, distanciaFE, distanciaFD;
    // METER DISTANCIAS del ejemplo
    distanciaAC = sqrt((0-0)*(0-0) - (2-0)*(2-0));
    distanciaAF = sqrt((0-0)*(0-0) - (2-0)*(2-0));
    distanciaAB = sqrt((0-0)*(0-0) - (2-0)*(2-0));
    distanciaBF = sqrt((0-0)*(0-0) - (2-0)*(2-0));
    distanciaBD = sqrt((0-0)*(0-0) - (2-0)*(2-0));
    distanciaCE = sqrt((0-0)*(0-0) - (2-0)*(2-0));
    distanciaCF = sqrt((0-0)*(0-0) - (2-0)*(2-0));
    distanciaFE = sqrt((0-0)*(0-0) - (2-0)*(2-0));
    distanciaFD = sqrt((0-0)*(0-0) - (2-0)*(2-0));

    
    
    myGrafo.setDistancia(0,1, distanciaAB);
    myGrafo.setDistancia(0,2, distanciaAC);
    myGrafo.setDistancia(0,5, distanciaAF);
    myGrafo.setDistancia(1,5, distanciaBF);
    myGrafo.setDistancia(1,3, distanciaBD);
    myGrafo.setDistancia(2,4, distanciaCE);
    myGrafo.setDistancia(2,5, distanciaCF);
    myGrafo.setDistancia(5,3, distanciaFD);
    myGrafo.setDistancia(5,4, distanciaFE);

    
    int costo = myGrafo.caminoCorto(0,5);
    
    cout << "La distancia minima es: " << costo << endl;


    return 0;
}
