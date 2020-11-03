
#ifndef _SALAESPERA_H
#define _SALAESPERA_H
#include <vector>
#include <queue>
#include <string>
#include "Monitor.h"

class SalaEspera {
private:
   const int nro_threads;
   Monitor monitor_inic;
   Monitor monitor_fin ;

public:
    SalaEspera(int argc, char** argv);
    void init();
    void destroyThreads(std::vector<Thread*>& threads);
};


#endif
