//
//  data.hpp
//  TrabajoMetroMadrid
//
//  Created by Rocio Ruiz Ruiz on 17/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#ifndef data_hpp
#define data_hpp

#include <iostream>

using namespace std;

class Data
{
    friend bool operator == (Data const & d1, Data const & d2);
    friend ostream & operator << (ostream & os, Data const & d);
    
public:
    Data(int ID, string name);
    
    int getID() const;
    void setID(int v);
    string getName() const;
    void setName(string v);
    
protected:
    int ID;
    string name;
};

bool operator == (Data const & d1, Data const & d2);
ostream & operator << (ostream & os, Data const & d);

#endif /* data_hpp */
