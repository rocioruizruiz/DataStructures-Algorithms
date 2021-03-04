//
//  data.hpp
//  Lista_Doble_Solita
//
//  Created by Rocio Ruiz Ruiz on 13/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#ifndef data_hpp
#define data_hpp

#include <iostream>
#include <math.h>
class Data{
public:
    Data(unsigned int n, unsigned int m);
    void setR(const unsigned int &value);
    unsigned int getR();
    void setI(const unsigned int &value);
    unsigned int getI();
    float getModulo();
    void setModule(Data*);
    void print();
    
    
    
    
private:
    unsigned int r, i;
    float module;
};

#endif /* data_hpp */
