//
// Created by goncalo on 04/04/22.
//

#include "../includes/Carrinha.h"

#include <utility>

Carrinha::Estafeta(string matricula, unsigned int maxVol, unsigned int maxPeso, unsigned int custo) : matricula(std::move(
        matricula)), maxVol(maxVol), maxPeso(maxPeso), custo(custo) {}

const string &Carrinha::getMatricula() const {
    return matricula;
}

void Carrinha::setMatricula(const string &matricula) {
    Carrinha::matricula = matricula;
}

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


