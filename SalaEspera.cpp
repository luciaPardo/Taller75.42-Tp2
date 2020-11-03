#include "SalaEspera.h"
#include "Thread.h"
#include "Monitor.h"
#include "Manejador.h"
#include <vector>
#include <thread>
#include <queue>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <iostream>

SalaEspera::SalaEspera(int argc, char** argv)
    :   nro_threads(atoi(argv[1])),
        monitor_inic(),
        monitor_fin()
{
    for (int i = 2; i < argc; i++){
        std::string s (argv[i]);
        monitor_inic.push(s);
    }
}

void SalaEspera::init(){ // vector de threads
    std::vector<Thread*> threads;
    for (int i = 0; i < nro_threads; ++i) {
        threads.push_back(new Manejador(monitor_inic, monitor_fin));
        threads[i]->start();
    }
    destroyThreads(threads);
    monitor_fin.imprimir();
}


void SalaEspera::destroyThreads(std::vector<Thread*>& threads){

    for (int i = 0; i < nro_threads; ++i) {
        threads[i]->join();
        delete threads[i];
    }
}

