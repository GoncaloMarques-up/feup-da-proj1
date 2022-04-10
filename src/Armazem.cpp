//
// Created by ASUS on 02/04/2022.
//

#include "../includes/Armazem.h"

Armazem::Armazem(list<Encomenda> &encomendas, list<Carrinha> &carrinhas) : encomendas(
        encomendas), carrinhas(carrinhas) {}


list<Encomenda> Armazem::getEncomendas() const {
    return encomendas;
}

void Armazem::setEncomendas(const list<Encomenda> &encomendas) {
    Armazem::encomendas = encomendas;
}

list<Carrinha> Armazem::getCarrinhas() const {
    return carrinhas;
}

void Armazem::setCarrinhas(const list<Carrinha> &carrinhas) {
    Armazem::carrinhas = carrinhas;
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


