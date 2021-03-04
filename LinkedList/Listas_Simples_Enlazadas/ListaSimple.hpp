//
//  ListaSimple.hpp
//  Listas_Simples_Enlazadas
//


#ifndef LISTASIMPLE_HPP
#define LISTASIMPLE_HPP

#include <iostream>

using namespace std;

class ListaSimple{
public:
    ListaSimple(int);
    void push_back(int);            //Añade un nuevo elemento al final de la lista
    void push_front(int);  //Añade un nuevo elemento al inicio de la lista (cambia el head de la lista!!!)
    ListaSimple *  at(int i);          //Devuelve un puntero al elemento con índice i
    int search(int)const;                //Devuelve el índice i de la primera coincidencia del elemento buscado (o -1 si no lo encuentra).
    bool erase(int);                //Elimina el elemento de índice i
    void move(int, int);            //Mueve elemento i a posición j
    void print();                   //imprime la lista entera
    ListaSimple * getNext();        //te devuelve puntero al siguiente
    int getData()const;                  // devuelve el dato
    void setI(int);
    void insert(ListaSimple, int, unsigned int);
    int getSize();
    ListaSimple * greater_than(int)const;        // devuelve una lista nueva con los MAYORES de un valor X
    ListaSimple * equal_to(int)const;            // devuelve una lista nueva con los IGUALES de un valor X
    ListaSimple * lesser_than(int)const;         // devuelve una lista nueva con los MENORES de un valor X
    ListaSimple * within_interval(int,int)const; // devuelve una lista nueva con elementos con valor en el INTERVALO
    void deleteAll();                            // borra todos los elementos de la lista, incluyendo el header
    void print()const;
    void printAll()const;                        // imprime la lista entera
    ListaSimple * getNext()const;                // devuelve puntero al siguiente elemento
    void setData(int);                           // cambia el valor del Data
    void setNext(ListaSimple *);                 // cambia el puntero al siguiente
    ListaSimple * getPares()const;
    ListaSimple * eliminarPares();
    void recorreLaLista();
private:
    int data, i;
    unsigned int size = 1;
    ListaSimple *next;
};
#endif   // LISTASIMPLE_HPP
