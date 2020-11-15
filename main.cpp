
#define MIN_ARG 3
#include <vector>
#include <iostream>
#include "MultiThreadVerifier.h"


int main(int argc, char *argv[]) {
    if (argc < MIN_ARG){
        std::cerr << "ERROR cant parámetros" << std::endl;
        return -1;
    }
    MultiThreadVerifier sala(argc, argv);
    sala.init();
    return 0;
}
