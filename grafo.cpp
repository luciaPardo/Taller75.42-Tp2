#include<bits/stdc++.h> 
#include <string>
#include <vector>
#include "grafo.h"
#include "Nodo.h"
#include <iostream>
#include <set>


Grafo::Grafo(int total) : nodos(), total_vertices(total){
    for (int i = 0; i < total_vertices; i++) {
        Nodo nodo_actual = Nodo(i);
        nodos.push_back(nodo_actual);
    }
}

void Grafo::agregarArista(int a, int b){
    nodos[a].agregarAdy(&nodos[b]);
}

bool Grafo::detectarCiclo(int indice, Nodo& nodo, std::vector<bool>& stack,
                                            std::vector<bool>&  visitados){
    if (!visitados[indice]) {
        stack[indice] = true;
        visitados[indice] = true;
        std::vector < Nodo * > &adyacentes_act = nodo.getAdy();
        for (size_t i = 0; i < adyacentes_act.size(); ++i) {
            int n = (*adyacentes_act[i]).id;
            if (!visitados[n] &&
                    detectarCiclo(n, *adyacentes_act[i], stack, visitados))
                return true;
            else if (stack[n])
                return true;
        }
    }
    stack[indice] = false;
    return false;
}

void Grafo::dfs(int indice, std::vector<bool>& visitados){
	visitados[indice] = true;
    std::vector<Nodo*>& adyacentes =  nodos[indice].getAdy();
    for (unsigned int i = 0; i < adyacentes.size(); i++){
        int n = (*adyacentes[i]).id;
		if (!visitados[n]){
            dfs(n, visitados);
        }
    }
}

bool Grafo::esConexo(){
    std::vector<bool>  visitados;
    for (int a = 0; a < total_vertices; a++){
        visitados.push_back(false);
    }
    dfs(0, visitados);
	for (int b = 0; b < total_vertices; b++){
        if (!visitados[b]){
            return false;
        }
    }
	return true; 
} 


int Grafo::esCiclico(){
    std::vector<bool>  stack;
    std::vector<bool>  visitados;

    for (int i = 0; i < total_vertices; i++){
        stack.push_back(false);
        visitados.push_back(false);
    }

    for (int i = 0; i < total_vertices; i++) {
        bool ret = detectarCiclo(i, nodos[i], stack, visitados);
        if (ret == true)
            return -1;
    }

    if (!esConexo()) return -2;

    return 0;
}
