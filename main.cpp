
#define MIN_ARG 3
#include <vector>
#include <iostream>
#include "SalaEspera.h"


int main(int argc, char *argv[]) {
    if (argc < MIN_ARG){
        std::cerr << "ERROR cant parámetros" << std::endl;
        return -1;
    }
    SalaEspera sala(argc, argv);
    sala.init();
    return 0;
}