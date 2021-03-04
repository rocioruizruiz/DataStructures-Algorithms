//
//  data.cpp
//  TrabajoMetroMadrid
//
//  Created by Rocio Ruiz Ruiz on 17/4/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "data.hpp"

Data::Data(int ID, string name):
    ID{ID}, name{name}
{}

int Data::getID() const
{
    return ID;
}

void Data::setID(int v)
{
    ID = v;
}

string Data::getName() const
{
    return name;
}

void Data::setName(string v)
{
    name = v;
}

bool operator ==(const Data &d1, const Data &d2)
{
    return (d1.ID == d2.ID);
}

ostream &operator <<(ostream &os, const Data &d)
{
    os << d.name;
    return os;
}
