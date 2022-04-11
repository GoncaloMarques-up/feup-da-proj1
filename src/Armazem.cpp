//
// Created by ASUS on 02/04/2022.
//

#include "../includes/Armazem.h"

Armazem::Armazem() {
    encomendas = list<Encomenda>();
    carrinhas = list<Carrinha>();
}

Armazem::Armazem(list<Encomenda> &encomendas, list<Carrinha> &carrinhas){
    this->encomendas = encomendas;
    this->carrinhas = carrinhas;
}

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
    /* ideias:
     * "greedy": ordenar encomendas por recompensa(descendente) e estafetas por custo(ascendente) e inserir até alcançar o lucro maximo.
     * outras possibilidades por definir.
     */
    carrinhas.sort([](const Carrinha &carrinha1, const Carrinha &carrinha2){
        if(carrinha1.getCusto() == carrinha2.getCusto())
            return carrinha1.getMaxPeso() < carrinha2.getMaxPeso();
        return carrinha1.getCusto() < carrinha2.getCusto();
    }); //lambda function (duvidas perguntem)


    encomendas.sort([](const Encomenda &encomenda1, const Encomenda &encomenda2){
        if(encomenda1.getRecompensa() == encomenda2.getRecompensa())
            return encomenda1.getPeso() < encomenda2.getPeso();
        return encomenda1.getRecompensa() > encomenda2.getRecompensa();
    });

    list<Carrinha> estafetas;
    unsigned int currPeso = 0, currVol = 0;
    int maxLucro = INT_MIN;


}

int Armazem::lucro(list<Carrinha> custos, list<Encomenda> lucros){
    int positives = 0, negatives = 0;
    for(auto custo : custos)
        negatives += custo.getCusto();

    for(auto lucro : lucros)
        positives+= lucro.getRecompensa();

    return positives-negatives;
}

void Armazem::cenario3() {
    cout << "yeet";
}
