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
    int volRem;
    int pesRem;
    for (auto &carrinha :carrinhas){
        auto it = encomendas.begin();
        volRem = carrinha.getMaxVol();
        pesRem =carrinha.getMaxPeso();
        for (auto &encomenda : encomendas){
            if (volRem>encomenda.getVolume() && pesRem>encomenda.getPeso()){
                volRem -= encomenda.getVolume();
                pesRem -= encomenda.getPeso();
                encomendas.erase(it);
                carrinha.addEnconmenda(encomenda);
            }
            it++;
        }
    }
    int count =0;
    for (auto &carrinha : carrinhas){
        cout << count << " " << carrinha.getNumEncomendas();
        count++;
    }
}

void Armazem::cenario2() {
    cout << "yeet";
}

void Armazem::cenario3() {
    cout << "yeet";
}


