//
//  Node.cpp
//  Polimorfismo
//
//  Created by Rocio Ruiz Ruiz on 11/2/19.
//  Copyright © 2019 Rocio Ruiz Ruiz. All rights reserved.
//
#include "main.cpp"
class Node{
public:
    
    Node(FiguraGeometrica *data):
    next{nullptr},
    data{data}
    {}
    Node();
    
    void push_back(FiguraGeometrica* data){
        if(next) next->push_back(data);
        else next = new Node(data);
    }
    void push_front(Node* first, FiguraGeometrica* d){
        Node* aux = new Node(data);
        aux->setNext(first->getNext());
        first->setNext(aux);
    }
    Node * getNext() const
    {
        return next;
    }
    void setNext(Node *value)
    {
        next = value;
    }
    FiguraGeometrica * getDato(){
        return data;
    }

    
private:
    FiguraGeometrica* data;
    Node* next;
};


int main()
{
    Node * lista = new Node();
    
    FiguraGeometrica *c = new Cuadrado(3);
    lista->push_back(c);
    
    FiguraGeometrica * t = new Triangulo(4);
    lista->push_back(t);
    FiguraGeometrica * f = new Cuadrado(5);
    lista->push_back(f);
    
    Node* it = lista;
    
    for(it = lista->getNext(); it != nullptr; it = it->getNext()){
        cout << it->getDato()->getTipo() << endl;
        cout << it->getDato()->getArea() << endl;
        if(it->getDato()->getTipo() == "triangulo"){
            Triangulo* aux = dynamic_cast<Triangulo*>(it->getDato());
            cout << aux->getHeight() << endl;
        }
    }
    
    
    
}
