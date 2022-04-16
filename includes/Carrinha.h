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

    list<Encomenda> enconmendas;

    unsigned int id, maxVol, maxPeso, custo;
public:
    unsigned int getId() const;


public:

    Carrinha(unsigned int id, unsigned int maxVol, unsigned int maxPeso, unsigned int custo);

    unsigned int getMaxVol() const;

    unsigned int getMaxPeso() const;

    unsigned int getCusto() const;

    void addEnconmenda(Encomenda encomenda);
    int getNumEncomendas();
    list<Encomenda> getEncomendas();
    void clearEncomendas();
};


#endif //PROJETO_DA_CARRINHA_H
