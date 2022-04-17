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

    ///returns the maxVol of Carrinha
    unsigned int getMaxVol() const;

    ///returns the maxPeso of Carrinha
    unsigned int getMaxPeso() const;

    ///returns custo fo Carrinha
    unsigned int getCusto() const;

    ///adds package encomenda to encomendas
    void addEnconmenda(Encomenda encomenda);
    ///returns the number of packages in encomendas
    int getNumEncomendas();
    ///returns encomendas
    list<Encomenda> getEncomendas();
    ///emptys encomendas
    void clearEncomendas();
};


#endif //PROJETO_DA_CARRINHA_H
