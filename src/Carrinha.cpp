//
// Created by goncalo on 04/04/22.
//

#include "../includes/Carrinha.h"

#include <utility>

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


