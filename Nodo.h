#ifndef _NODO_H
#define _NODO_H

#include <vector>
class Nodo {
private:
    std::vector<Nodo*> adyacentes;
    bool visitado;
public:
    explicit Nodo(int n);
    int id;
    std::vector<Nodo*> & getAdy();
    void agregarAdy(Nodo* nodo);
};
#endif
