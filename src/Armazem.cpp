//
// Created by ASUS on 02/04/2022.
//

#include "../includes/Armazem.h"

const list<int> &Armazem::getEncomendas() const {
    return encomendas;
}

void Armazem::setEncomendas(const list<int> &encomendas) {
    Armazem::encomendas = encomendas;
}

const list<int> &Armazem::getEstafetas() const {
    return estafetas;
}

void Armazem::setEstafetas(const list<int> &estafetas) {
    Armazem::estafetas = estafetas;
}

const float Armazem::getLucroThreshold() const {
    return lucro_threshold;
}

void Armazem::cenario1() {
    cout << "yeet";
}

void Armazem::cenario2() {
    cout << "yeet";
}

void Armazem::cenario3() {
    cout << "yeet";
}
