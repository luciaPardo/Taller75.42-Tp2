
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
    std::mutex mtx_exit;
    std::queue<std::string> cola_bpfs;

public:
    Monitor();
    /*Método THREAD UNSAFE, se usa cuando no hay hilos,
    únicamente al principio*/
    void push(std::string& archivo);
    void pushResult(std::string& archivo);
    bool popIfNotEmpty(std::string& archivo);
    void imprimir();
};


#endif
