//
//  data.cpp
//  Lista_Doble_Solita
//
//  Created by Rocio Ruiz Ruiz on 13/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "data.hpp"
#include <math.h>
using namespace std;


Data::Data(unsigned int n, unsigned int m): r{n}, i{m}
{
    module = sqrt(r * r + i * i);
}

void Data::setR(const unsigned int &value)
{
    r = value;
}

unsigned int Data::getR()
{ 
    return r;
}
void Data::setI(const unsigned int &value)
{
    i = value;
}

unsigned int Data::getI()
{
    return i;
}
void Data::setModule(Data *a) {
    module = sqrt(a->getR() * a->getR() + a->getI() * a->getI());
}
float Data::getModulo(){
    return module;
}

void Data::print() { 
    cout << r << " + " << i << "i" << endl;
}






