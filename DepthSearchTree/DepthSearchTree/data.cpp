//
//  data.cpp
//  DepthSearchTree
//
//  Created by Rocio Ruiz Ruiz on 11/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include "data.hpp"

Data::Data(int d):
value{d}
{
    
}

int Data::getValue() const
{
    return value;
}

void Data::setValue(int v)
{
    value = v;
}

bool operator ==(const Data &d1, const Data &d2)
{
    return (d1.value == d2.value);
}

bool operator <=(const Data &d1, const Data &d2)
{
    return (d1.value <= d2.value);
}

bool operator >=(const Data &d1, const Data &d2)
{
    return (d1.value >= d2.value);
}

bool operator >(const Data &d1, const Data &d2)
{
    return (d1.value > d2.value);
}

bool operator <(const Data &d1, const Data &d2)
{
    return (d1.value < d2.value);
}

std::ostream &operator <<(std::ostream &os, const Data &d)
{
    os << d.value;
    return os;
}
