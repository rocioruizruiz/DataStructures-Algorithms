//
//  main.cpp
//  TrabajoMetroMadrid
//
//  Created by Rocio Ruiz Ruiz on 17/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>

#include "metro.hpp"
using namespace std;

int main()
{
    Graph metro;
    ifstream fichero;
    string registro;
    int idPrev=0;
    int linea_ant=0;
    
    fichero.open("Estaciones.csv", ios::in);
    if (fichero.fail()) cout << "El fichero no existe en el directorio del ejecutable!!" << endl;

    while (!fichero.eof()) {
        getline(fichero, registro);
        // cout << registro << endl;
        stringstream   stream(registro);
        string         c_line,order,c_id,name;
        int line, id;
        
        // cout << "Contenido de la linea:\n";
        getline(stream,c_line,';');
        getline(stream,order,';');
        getline(stream,c_id,';');
        getline(stream,name,';');
        //cout << "linea: " << c_line;
        //cout << " orden: " << order;
        //cout << " id: " << c_id;
        //cout << " estacion: " << name << endl;
        id = atoi(c_id.c_str());
        line = atoi(c_line.c_str());
        
        // Voy generando los Nodos Estacion
        // Existe un nodo con este ID
        //aux = metro.searchNode(id);
        if (metro.existNode(id)) {
            metro.addNodeLine(id,line);      // si existe entonces le añado la nueva linea
        }
        else {
            metro.addNode(id,name,{line});             // si no existe crea el nodo
        }
        if (idPrev && line == linea_ant) {
            metro.link(id,idPrev, true); // nuevo vecino el nodo anterior
        }
        if (!idPrev) metro.setEntryPoint(id);
        idPrev = id;                     // me quedo con la direccion del nodo actual como nodo anterior
        linea_ant = line;
        // cout << "Fin de la linea\n";
    }
    
    fichero.close();
    
    cout << "Lista de las Estaciones de Metro de Madrid" << endl;
    cout << "==========================================" << endl;
    
    metro.printAll();
    
    cout << endl << " --------------------- " << endl;
    
    int ini,fin;
    cout << "Estacion de partida (ID, datos en el fichero): " << endl;
    cin >> ini;
    cout << "Estacion de llegada (ID, datos en el fichero): " << endl;
    cin >> fin;
    cout << "        RRECORRIDO   "  << endl;
    
    if (metro.existNode(ini)) metro.setEntryPoint(ini); else cout << "La estación de inicio es inexistente";
    if (metro.existNode(fin)) metro.printPath(fin,true); else cout << "La estación de llegada es inexistente";


    return 0;
}
