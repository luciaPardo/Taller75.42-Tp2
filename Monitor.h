
#ifndef _MONITOR_H
#define _MONITOR_H

#include <vector>
#include "Thread.h"
#include <queue>
#include <string>
#include <cstring>
#include <mutex>


class Monitor {
    std::mutex mtx;
    std::queue<std::string> cola_bpfs;
    //static bool ordenarAlfabetico(const std::string a, const std::string b);

public:
    Monitor();
    void push(std::string archivo);
    void pop(std::string& archivo);
    std::size_t size();
    bool vacia();
    void imprimir();
};


#endif
