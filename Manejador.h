
#ifndef _MANEJADOR_H
#define _MANEJADOR_H
#include "Thread.h"
#include "Parseador.h"
#include "Monitor.h"
#include "grafo.h"
#include <vector>
#include <string>


class Manejador : public Thread {
    Monitor& monitor_inic;
    Monitor& monitor_fin;
    void mandarMensaje(Grafo& grafo, std::string archivo_actual);
    int buscarDic(std::unordered_map<std::string, int>& dic_et,
                                        std::string etiqueta_act);
    void llenarGrafo(Grafo& grafo,
                     std::vector<std::vector<std::string>>& lineas,
                     std::unordered_map<std::string, int>& dic_et);
    void revisarOpcode(int i, int pos_instr,
                       std::vector<std::vector<std::string>>& lineas,
                       std::unordered_map<std::string, int>& dic_et,
                       Grafo& grafo);

public:
    Manejador(Monitor& monitor_inic, Monitor& monitor_fin);
    virtual void run() override;
};


#endif
