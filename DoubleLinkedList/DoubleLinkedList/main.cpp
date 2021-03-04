//
//  main.cpp
//  Lista_Doble_Solita
//
//  Created by Rocio Ruiz Ruiz on 13/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include <iostream>
using namespace std;
#include "list.hpp"
#include "node.hpp"
#include "data.hpp"

int main() {
    // insert code here...
    srand(time(NULL));
    List mylist;
    for(int i=0; i <= 10; i++){
        int v = rand()%10;
        int w = 0; // rand()%10;
        mylist.push_in_order(new Data(v,w));
        mylist.printList();
        cout << " -------------------" << endl;
    }
    
    Data *dato = new Data(5,0);
    mylist.push_in_order(dato);


    mylist.printList();
    mylist.busca(dato);
    cout << endl;
    
       
}
