//
//  main.cpp
//  Polimorfismo
//
//  Created by Rocio Ruiz Ruiz on 4/2/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class FiguraGeometrica{
public:
    FiguraGeometrica();
    FiguraGeometrica(string tipo);
    string getTipo()const{ return tipo; }
    virtual float getArea()const = 0;
    
private:
    string tipo;
};
class Cuadrado: public FiguraGeometrica{
private:
    int lado;
public:
    Cuadrado(int l):
    FiguraGeometrica("Cuadrado"),
    lado{l}{}
    float getArea()const{ return lado*lado; }
    void print(){
        for (int i{0}; i < lado ; i++){
            for (int j{0}; j < lado; j++){
                cout << "**";
            }
            cout << endl;
        }
    }
};
class Triangulo: public FiguraGeometrica{
private:
    int base, altura;
public:
    Triangulo(int b):
    FiguraGeometrica("Triangulo"),
    base{b}{}
    float getArea()const { return 0.5*base*altura; }
    float getHeight(){
        return sqrt(3)*base;
        
    }
};

