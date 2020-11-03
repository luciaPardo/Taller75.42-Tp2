
#include "grafo.h"
#include "Manejador.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#define BUENO 0
#define CICLO -1
#define AISLADO -2


Manejador::Manejador (Monitor& monitor_inic, Monitor& monitor_fin)
    :   monitor_inic(monitor_inic),
        monitor_fin(monitor_fin)
{}

void Manejador::llenarGrafo(Grafo& grafo,
                            std::vector<std::vector<std::string>>& lineas,
                            std::unordered_map<std::string, int>& dic_et){
    for (int i = 0; i < lineas.size(); i++) {
        std::string instr_act = lineas[i][0];
        if (instr_act.find(':') == std::string::npos) { // si no tiene etiqueta
            if (lineas[i][0].compare("ret") == 0 || (i + 1) > lineas.size() - 1)
                continue;
            revisarOpcode(i, 0, lineas, dic_et, grafo);
        } else{
            if (lineas[i][1].compare("ret") == 0 || (i + 1) > lineas.size() - 1)
                continue;
            revisarOpcode( i, 1, lineas, dic_et, grafo);
        }
    }
}

void Manejador::revisarOpcode(int i, int pos_instr,
                              std::vector<std::vector<std::string>>& lineas,
                              std::unordered_map<std::string, int>& dic_et,
                              Grafo& grafo){
    int vertice_agregar = i + 1;
    if (lineas[i][pos_instr].find('j',0) != std::string::npos) {
        std::string etiqueta_act;
        if ((lineas[i]).size() == pos_instr + 2) {
            etiqueta_act = lineas[i][pos_instr + 1];
        } else if ((lineas[i]).size() == pos_instr + 3) {
            etiqueta_act = lineas[i][pos_instr + 2];
            grafo.agregarArista(i, vertice_agregar);
        } else if ((lineas[i]).size() == pos_instr + 4) {
            std::string etiqueta_a_parsear = lineas[i][pos_instr + 2];
            std::string etiqueta_act2 = lineas[i][pos_instr + 3];
            etiqueta_act = etiqueta_a_parsear.substr(0,etiqueta_a_parsear.size()-1);
            int aux = buscarDic(dic_et, etiqueta_act2);
            if(aux != -1) grafo.agregarArista(i, aux);
        }
        int aux = buscarDic(dic_et, etiqueta_act);
        if (aux != -1)
            vertice_agregar = aux;
    }
    grafo.agregarArista(i, vertice_agregar);
}

int Manejador::buscarDic(std::unordered_map<std::string, int>& dic_et,
                                            std::string etiqueta_act){
    auto elem = dic_et.find(etiqueta_act);
    if (elem == dic_et.end()){
        return -1;
    }
    return elem->second;
}

void Manejador::run(){

    while (!monitor_inic.vacia()) {
        std::vector<std::vector<std::string>> lineas;
        std::unordered_map<std::string, int> dic_et;
        std::string archivo_actual;
        monitor_inic.pop(archivo_actual);
        Parser parse(archivo_actual);
        parse.file(dic_et, lineas);
        Grafo grafo(lineas.size());
        llenarGrafo(grafo, lineas, dic_et);
        mandarMensaje(grafo, archivo_actual);
    }

}

void Manejador::mandarMensaje(Grafo& grafo, std::string archivo_actual){
    int correcto = grafo.esCiclico();
    if (correcto == BUENO)
         archivo_actual += " GOOD";
    else if (correcto == CICLO)
        archivo_actual += " FAIL: cycle detected";
    else if (correcto == AISLADO)
        archivo_actual += " FAIL: unused instructions detected";
    monitor_fin.push(archivo_actual);
}
