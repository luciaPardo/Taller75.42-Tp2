
#ifndef _MultiThreadVerifier_H
#define _MultiThreadVerifier_H
#include <vector>
#include <queue>
#include <string>
#include "Monitor.h"

class MultiThreadVerifier {
private:
   const int nro_threads;
   Monitor monitor_inic;
   Monitor monitor_fin;

public:
    MultiThreadVerifier(int argc, char** argv);
    void init();
    void destroyThreads(std::vector<Thread*>& threads);
};


#endif
