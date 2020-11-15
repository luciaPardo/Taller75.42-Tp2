#include "Parseador.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iterator>
#include <unordered_map>


Parser::Parser(const std::string& archivo)
        : archivo(archivo)
{}


void Parser::file(std::unordered_map<std::string, int>& dic,
                  std::vector<std::vector<std::string>>& lineas){
    std::string line;
    std::ifstream file(archivo);
    if (!file.is_open()){
        return;
    }
    int nro_linea = 0;
    while (getline(file, line)){
        std::vector<std::string> instrucciones;
        if (!line.empty()) {
            std::size_t etiqueta = line.find(":");
            if (etiqueta != std::string::npos) {
                std::string aux = line.substr(0, etiqueta);
                dic.insert({aux, nro_linea});
            }
            split(line, instrucciones);
            lineas.push_back(instrucciones);
            nro_linea += 1;
        }
    }
}


void Parser::split(const std::string& str,
                            std::vector<std::string>& instruccion ){
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(instruccion));
}





