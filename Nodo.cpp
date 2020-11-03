
#include <bits/stdc++.h>
#include "Nodo.h"
#include <string>
#include <iostream>
#include <vector>


Nodo::Nodo()
    : adyacentes(), visitado (false)
{}
std::vector<Nodo*>  &  Nodo::getAdy(){
    return this->adyacentes;
}
void Nodo::agregarAdy(Nodo* nodo){
    adyacentes.push_back(nodo);
}

void Nodo::esVisitado(){
    visitado = true;
}

void Nodo::desvisitado(){
    visitado = false;
}

bool Nodo::fueVisitado(){
    return visitado;
}