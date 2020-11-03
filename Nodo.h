#ifndef _NODO_H
#define _NODO_H

#include <vector>
class Nodo {
private:
    std::vector<Nodo*> adyacentes;
    bool visitado;
public:
    Nodo();
    std::vector<Nodo*> & getAdy();
    void agregarAdy(Nodo* nodo);
    void esVisitado();
    void desvisitado();
    bool fueVisitado();
};
#endif
