#ifndef _PARSEADOR_H
#define _PARSEADOR_H
#include <vector>
#include <string>
#include <unordered_map>


class Parser{
    std::string archivo;

public:
    Parser(std::string archivo);
    void file(std::unordered_map<std::string, int>& dic,
                std::vector<std::vector<std::string>>& lineas);
    void split(const std::string& str,
               std::vector<std::string>& instruccion);
    int BuscarEtiqueta(std::vector<std::vector <std::string>>& lineas,
                                    std::string etiqueta_act, int i);
};
#endif
