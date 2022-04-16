//
// Created by goncalo on 04/04/22.
//

#include "../includes/Carrinha.h"


Carrinha::Carrinha(unsigned int id, unsigned int maxVol, unsigned int maxPeso, unsigned int custo) : id(id),
                    maxVol(maxVol),maxPeso(maxPeso),custo(custo) {}

unsigned int Carrinha::getMaxVol() const {
    return maxVol;
}

void Carrinha::setMaxVol(unsigned int maxVol) {
    Carrinha::maxVol = maxVol;
}

unsigned int Carrinha::getMaxPeso() const {
    return maxPeso;
}

void Carrinha::setMaxPeso(unsigned int maxPeso) {
    Carrinha::maxPeso = maxPeso;
}

unsigned int Carrinha::getCusto() const {
    return custo;
}

void Carrinha::setCusto(unsigned int custo) {
    Carrinha::custo = custo;
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

void Carrinha::setId(unsigned int id) {
    Carrinha::id = id;
}

void Carrinha::clearEncomendas() {
    enconmendas.clear();
}



