

#ifndef _GRAFO_H
#define _GRAFO_H
#include<bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include "Nodo.h"

class Grafo{
    std::vector<Nodo> nodos;
    int total_vertices;
    bool detectarCiclo(int indice, Nodo& nodo, std::vector<bool>& stack);
public:
    Grafo();
    Grafo(int);
    void agregarArista(int a, int b);
    int esCiclico();
};


#endif
