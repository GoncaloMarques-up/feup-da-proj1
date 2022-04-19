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

    /**
     *
     * @return maxVol of Carrinha
     */
    unsigned int getMaxVol() const;

    /**
     *
     * @return maxPeso of Carrinha
     */
    unsigned int getMaxPeso() const;

    /**
     *
     * @return custo of Carrinha
     */
    unsigned int getCusto() const;

    /**
     * adds package encomenda to encomendas
     * @param encomenda and object of type Encomenda
     */
    void addEnconmenda(Encomenda encomenda);
    /**
     *
     * @return the size of the list encomendas
     */
    int getNumEncomendas();
    /**
     *
     * @return list encomendas
     */
    list<Encomenda> getEncomendas();
    /**
     * emptys encomendas
     */
    void clearEncomendas();
};


#endif //PROJETO_DA_CARRINHA_H
