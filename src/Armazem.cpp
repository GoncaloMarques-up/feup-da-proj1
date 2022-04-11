//
// Created by ASUS on 02/04/2022.
//

#include "../includes/Armazem.h"

Armazem::Armazem() {
    encomendas = list<Encomenda>();
    carrinhas = list<Carrinha>();
}

list<Encomenda> Armazem::getEncomendas() const {
    return encomendas;
}

void Armazem::setEncomendas(const list<Encomenda> &entregas) {
    Armazem::encomendas = entregas;
}

list<Carrinha> Armazem::getCarrinhas() const {
    return carrinhas;
}

void Armazem::setCarrinhas(const list<Carrinha> &estafetas) {
    Armazem::carrinhas = estafetas;
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
    list<Encomenda> entregas;

    int maxLucro = INT_MIN;

    while(!carrinhas.empty()){
        estafetas.push_back(carrinhas.front());
        carrinhas.pop_front();
         auto it = encomendas.begin();
        unsigned int currPeso = 0, currVol = 0;

        while(!encomendas.empty() && it != encomendas.end()){
           if(currPeso + it->getPeso() <= estafetas.back().getMaxPeso() && currVol + it->getVolume() <= estafetas.back().getMaxVol()){
                currPeso += it->getPeso();
                currVol += it->getVolume();
                entregas.push_back(*it);
                it = encomendas.erase(it);
             }
           else
               it++;
        }
        int currLucro = lucro(estafetas, entregas);
        if(currLucro >= maxLucro)
            maxLucro = currLucro;
        else{
            estafetas.pop_back();
            break;
        }
    }
    for(auto estafeta : estafetas)
        cout << estafeta.getId() << endl;
}

int Armazem::lucro(const list<Carrinha>& custos, const list<Encomenda>& lucros){
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
