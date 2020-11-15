#ifndef _NODO_H
#define _NODO_H

#include <vector>
class Nodo {
private:
    std::vector<Nodo*> adyacentes;
    int id;
public:
    explicit Nodo(int n);
    std::vector<Nodo*> & getAdy();
    void agregarAdy(Nodo* nodo);
    int getId();
};
#endif
