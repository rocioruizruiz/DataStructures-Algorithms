//
//  data.hpp
//  DepthSearchTree
//
//  Created by Rocio Ruiz Ruiz on 11/3/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#ifndef data_hpp
#define data_hpp

#include <ostream>

class Data
{
    friend bool operator == (Data const & d1, Data const &d2);
    friend bool operator >= (Data const & d1, Data const &d2);
    friend bool operator <= (Data const & d1, Data const &d2);
    friend bool operator > (Data const & d1, Data const &d2);
    friend bool operator < (Data const & d1, Data const &d2);
    friend std::ostream & operator << (std::ostream & os, Data const &d);
public:
    Data(int d);
    
    int getValue() const;
    void setValue(int v);
    
protected:
    int value;
};

bool operator == (Data const & d1, Data const &d2);
bool operator >= (Data const & d1, Data const &d2);
bool operator <= (Data const & d1, Data const &d2);
bool operator > (Data const & d1, Data const &d2);
bool operator < (Data const & d1, Data const &d2);

std::ostream & operator << (std::ostream & os, Data const &d);


#endif /* data_hpp */
