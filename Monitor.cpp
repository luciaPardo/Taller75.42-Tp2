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
    :  mtx(), mtx_exit(), cola_bpfs()
{}

void Monitor::pushResult(std::string& archivo){
    std::lock_guard<std::mutex> lck(mtx_exit);
    cola_bpfs.push(archivo);
}

void Monitor::push(std::string& archivo){
    cola_bpfs.push(archivo);
}

bool Monitor::popIfNotEmpty(std::string& archivo){
    std::lock_guard<std::mutex> lck(mtx);
    if (!cola_bpfs.empty()) {
        archivo = cola_bpfs.front();
        cola_bpfs.pop();
        return true;
    }
    return false;
}

bool ordenarAlfabetico(const std::string& a, const std::string& b){
    return a < b;
}

void Monitor::imprimir(){
    std::lock_guard<std::mutex> lck(mtx);
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




