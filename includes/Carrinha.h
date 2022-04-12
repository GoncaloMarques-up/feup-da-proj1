//
// Created by goncalo on 04/04/22.
//

#ifndef PROJETO_DA_CARRINHA_H
#define PROJETO_DA_CARRINHA_H

#include <iostream>
#include <list>
#include "Encomenda.h"

using namespace std;

class Carrinha {
private:
    unsigned int maxVol, maxPeso, custo;
    list<Encomenda> enconmendas;

public:
    Carrinha(unsigned int maxVol, unsigned int maxPeso, unsigned int custo);

    unsigned int getMaxVol() const;
    void setMaxVol(unsigned int maxVol);

    unsigned int getMaxPeso() const;
    void setMaxPeso(unsigned int maxPeso);

    unsigned int getCusto() const;
    void setCusto(unsigned int custo);

    void addEnconmenda(Encomenda encomenda);
    int getNumEncomendas();
    list<Encomenda> getEncomendas();
};


#endif //PROJETO_DA_CARRINHA_H
