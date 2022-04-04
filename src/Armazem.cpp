//
// Created by ASUS on 02/04/2022.
//

#include "../includes/Armazem.h"

Armazem::Armazem(list<Encomenda> &encomendas, list<Carrinha> &carrinhas, float lucroThreshold) : encomendas(
        encomendas), carrinhas(carrinhas), lucro_threshold(lucroThreshold) {}


list<Encomenda> Armazem::getEncomendas() const {
    return encomendas;
}

void Armazem::setEncomendas(const list<Encomenda> &encomendas) {
    Armazem::encomendas = encomendas;
}

const list<Carrinha> &Armazem::getCarrinhas() const {
    return carrinhas;
}

void Armazem::setCarrinhas(const list<Carrinha> &carrinhas) {
    Armazem::carrinhas = carrinhas;
}

float Armazem::getLucroThreshold() const {
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


