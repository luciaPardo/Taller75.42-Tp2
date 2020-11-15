
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

public:
    Monitor();
    void push(std::string& archivo);
    bool sacoArchivo(std::string& archivo);
    void imprimir();
};


#endif
