#include<bits/stdc++.h> 
#include <string>
#include <vector>
#include "grafo.h"
#include "Nodo.h"
#include <iostream>
#include <set>

Grafo::Grafo()
{}


Grafo::Grafo(int total)
    : nodos (), total_vertices (total){
    for (int i = 0; i < total_vertices; i++) {
        Nodo nodo_actual = Nodo();
        nodos.push_back(nodo_actual);
    }
}

void Grafo::agregarArista(int a, int b){
    nodos[a].agregarAdy(&nodos[b]);
}

bool Grafo::detectarCiclo(int indice, Nodo& nodo, std::vector<bool>& stack){
//    if(!nodo.fueVisitado()){
//        stack.insert(indice);
        nodo.esVisitado();
        std::vector<Nodo*> & adyacentes_act = nodo.getAdy();

        for (size_t i = 0; i < adyacentes_act.size(); i++){
            if ( !nodo.fueVisitado() && detectarCiclo(i, *adyacentes_act[i], stack) )
                return true;
//            else if (stack[i])
//                return true;
        }

    nodo.desvisitado();
    //set.erase(indice);
    return false;
} 

int Grafo::esCiclico(){
    std::vector<bool>  stack;
    std::set<int> visitados;
    for (int i = 0; i < total_vertices; i++){
        //visitados.push_back(false);
        stack.push_back(false);
    } 

    for (int i = 0; i < total_vertices; i++) {
        if (detectarCiclo(i, nodos[i], stack))
            return -1;
    }
    for (int i = 0; i < total_vertices; i++){
        if (!nodos[i].fueVisitado())
            return -2;
    }
    return 0;
} 

