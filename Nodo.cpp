#include "Nodo.h"
#include <string>
#include <iostream>
#include <vector>


Nodo::Nodo(int n)
    : adyacentes(), id(n)
{}
std::vector<Nodo*>&  Nodo::getAdy(){
    return this->adyacentes;
}
void Nodo::agregarAdy(Nodo* nodo){
    adyacentes.push_back(nodo);
}

int Nodo::getId(){
    return id;
}
