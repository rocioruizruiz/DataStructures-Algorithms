//
//  mainclase.cpp
//  Listas_Simples_Enlazadas
//
//  Created by Rocio Ruiz Ruiz on 6/2/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//


#include <iostream>
#include "ListaSimple.hpp"

using namespace std;
int menu(){
    int option;
    cout << "----------------------------------------------       "  << endl;
    cout << "1: Anadir  numero entero al final de la lista        "  << endl;
    cout << "2: Filtrar por pares                                 "  << endl;
    cout << "3: Eliminar los pares                                "  << endl;
    cout << "4: Imprimir lista                                    "  << endl;
    cout << "0: SALIR                                             "  << endl;
    cout << "----------------------------------------------       "  << endl;
    cin  >> option;
    
    return option;
}
int main() {
    
    int option;
    ListaSimple * head = new ListaSimple{0};
    
    do{
        option = menu();
        switch (option) {
                
            case 1:
            {
                bool b{true};
                while(b){
                    int a;
                    cout << "Introduzca el numero que desee anadir. " << endl;
                    cin  >> a;
                    head->push_back(a);
                    cout << "¿Desea anadir algun otro? *Si: pulse 1.  *No: pulse 0. " << endl;
                    cin  >> b;
                }
                break;
            }
                
            case 2:
            {
                cout << "Filtrando por pares: " << endl;
                head->getPares();
                break;
            }
                
            case 3:
            {
                ListaSimple * aux = new ListaSimple{0};
               // aux = eliminarPares();
                aux->print();
                break;
            }
                
            case 4:
            {
                cout << "-------------------SU LISTA----------------" << endl;
                head ->print();
                break;
            }
            default:
                option = 0;
                break;
        }
    }while (option);
    return 0;
}
