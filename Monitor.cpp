#include "Monitor.h"
#include "Thread.h"
#include <vector>
#include <queue>
#include <mutex>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

Monitor::Monitor()
    :  mtx(), cola_bpfs()
{}

void Monitor::push(std::string archivo){
    std::lock_guard<std::mutex> lck(mtx);
    cola_bpfs.push(archivo);
}

void Monitor::pop(std::string& archivo){
    std::lock_guard<std::mutex> lck(mtx);
    archivo = cola_bpfs.front();
    cola_bpfs.pop();
}

std::size_t Monitor::size(){
    std::lock_guard<std::mutex> lck(mtx);
    return cola_bpfs.size();
}

bool Monitor::vacia(){
    std::lock_guard<std::mutex> lck(mtx);
    return cola_bpfs.empty();
}

bool ordenarAlfabetico(const std::string& a, const std::string& b){
    return a < b;
}

void Monitor::imprimir(){
    std::vector<std::string> ordenados;
    while (!cola_bpfs.empty()){
        std::string resultado;
        resultado += cola_bpfs.front();
        cola_bpfs.pop();
        ordenados.push_back(resultado);
    }
    std::sort(ordenados.begin(), ordenados.end(), ordenarAlfabetico);
    for (int i = 0; i < (int)ordenados.size(); i++) {
        std::cout << ordenados.at(i) << std::endl;
    }
}




