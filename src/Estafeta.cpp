//
// Created by goncalo on 04/04/22.
//

#include "../includes/Estafeta.h"

#include <utility>

Estafeta::Estafeta(string matricula, unsigned int maxVol, unsigned int maxPeso, unsigned int custo) : matricula(std::move(
        matricula)), maxVol(maxVol), maxPeso(maxPeso), custo(custo) {}

const string &Estafeta::getMatricula() const {
    return matricula;
}

void Estafeta::setMatricula(const string &matricula) {
    Estafeta::matricula = matricula;
}

unsigned int Estafeta::getMaxVol() const {
    return maxVol;
}

void Estafeta::setMaxVol(unsigned int maxVol) {
    Estafeta::maxVol = maxVol;
}

unsigned int Estafeta::getMaxPeso() const {
    return maxPeso;
}

void Estafeta::setMaxPeso(unsigned int maxPeso) {
    Estafeta::maxPeso = maxPeso;
}

unsigned int Estafeta::getCusto() const {
    return custo;
}

void Estafeta::setCusto(unsigned int custo) {
    Estafeta::custo = custo;
}


