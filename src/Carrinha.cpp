//
// Created by goncalo on 04/04/22.
//

#include "../includes/Carrinha.h"


Carrinha::Carrinha(unsigned int id, unsigned int maxVol, unsigned int maxPeso, unsigned int custo) : id(id),
                    maxVol(maxVol),maxPeso(maxPeso),custo(custo) {}

unsigned int Carrinha::getMaxVol() const {
    return maxVol;
}

unsigned int Carrinha::getMaxPeso() const {
    return maxPeso;
}

unsigned int Carrinha::getCusto() const {
    return custo;
}


void Carrinha::addEnconmenda(Encomenda encomenda) {
    enconmendas.push_back(encomenda);
}

int Carrinha::getNumEncomendas() {
    return enconmendas.size();
}


list<Encomenda> Carrinha::getEncomendas() {
    return enconmendas;
}

unsigned int Carrinha::getId() const {
    return id;
}

void Carrinha::clearEncomendas() {
    enconmendas.clear();
}



