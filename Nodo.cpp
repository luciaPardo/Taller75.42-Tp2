
#include <bits/stdc++.h>
#include "Nodo.h"
#include <string>
#include <iostream>
#include <vector>


Nodo::Nodo(int n)
    : adyacentes(), visitado (false), id(n)
{}
std::vector<Nodo*>  &  Nodo::getAdy(){
    return this->adyacentes;
}
void Nodo::agregarAdy(Nodo* nodo){
    adyacentes.push_back(nodo);
}
