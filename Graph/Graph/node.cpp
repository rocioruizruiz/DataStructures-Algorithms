#include "node.h"
#include <vector>
using namespace std;

Node::Node(Data* d):
    data{d},
    visited{false},
    next{nullptr}
{

}

Data *Node::getData() const
{
    return data;
}

void Node::setData(Data *value)
{
    data = value;
}

set<Node *> Node::getNeighbours() const
{
    return neighbours;
}

void Node::setNeighbours(const set<Node *> &value)
{
    neighbours = value;
}

void Node::printAll(){

    if(visited) return;
    visited = true;
    cout << *data << endl;
    for(auto n:neighbours)
        n->printAll();
}

void Node::resetVisited(){
    if(!visited) return;
    visited = false;
    for(auto n:neighbours)
        n->resetVisited();
}

void Node::addNeighbour(Node * n)
{
    neighbours.insert(n);
}

Node* Node::computePath(Node *dest)
{
    if(visited) return nullptr;

    next = nullptr;
    visited = true;

    if(dest == this) return this;

    for(auto p:neighbours){
        Node* aux = p->computePath(dest);
        if(aux){
            next = p;
            return aux;
        }
    }
    return nullptr;
}

void Node::printPath()
{
    cout << *data << " - ";
    if(next) next->printPath();
}

Node* Node::find(Node* p)
{
    if(visited) return nullptr;
    visited = true;
    if(data->getValue() == p->getData()->getValue()){
        return p;
    }
    for(auto n:neighbours){
        n->find(p);
    }
    return nullptr;
}
void Node::depthFirstSearch()
{
    if(visited) return;
    visited = true;
    cout << *data << endl;
    for(auto n:neighbours)
        n->printAll();
}
void Node::breadthFirstSearch()
{
    vector<Node*> queue;
    queue.push_back(this);
    cout << this->getData()->getValue() << endl;
    //for(auto q: queue){
    for(int i{0}; i < queue.size(); i++){
        int j{0};
        set<Node*> neighbours_ = queue.at(i)->neighbours;
        for(auto n:neighbours_){
            if(n != nullptr && neighbours.size() > 0 ){
                queue.push_back(n);
                cout << "neigh num  " << j << " :  " << n->getData()->getValue() << endl;
                j++;
            }
        }
        cout << queue.size();
    }
    cout << "Arbol recorrido" << endl;
}

bool operator ==(const Node &n1, const Node &n2)
{
    return (*(n1.data) == *(n2.data));
}

ostream &operator <<(ostream &os, const Node &n)
{
    os << *(n.data);
    return os;
}
