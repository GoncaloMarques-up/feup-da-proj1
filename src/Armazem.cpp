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


list<Carrinha> Armazem::sortCarrinhasPeso(list<Carrinha> carrinhas) {
    //using mergeSort
//    if (carrinhas.size() == 1) return carrinhas;
//    int mid = carrinhas.size()/2;
//    list<Carrinha> final;
//    list<Carrinha> listCarr1;
//    list<Carrinha> listCarr2;
//
//    for (int i =0;i<mid;i++){
//        listCarr1.push_back(carrinhas.front());
//        carrinhas.pop_front();
//    }
//
//    for (int i =mid;i<mid*2;i++){
//        listCarr2.push_back(carrinhas.front());
//        carrinhas.pop_back();
//    }
//
//    listCarr1=this->sortCarrinhasPeso(listCarr1);
//    listCarr2=this->sortCarrinhasPeso(listCarr2);
//    auto it1 = listCarr1.begin();
//    auto it2 = listCarr2.begin();
//
//    while(!listCarr1.empty() || !listCarr2.empty()){
//        if (it1->getMaxPeso()>it2->getMaxPeso()){
//            final.push_back(*it1);
//            listCarr1.erase(it1);
//            it1 = listCarr1.begin();
//        } else {
//            final.push_back(*it2);
//            listCarr2.erase(it2);
//            it2 = listCarr2.begin();
//        }
//    }
//
//    return final;

// naive
    list<Carrinha> final;

    while (!carrinhas.empty()) {
        int count =0;
        int mcount = 0;
        Carrinha max = carrinhas.front();
        for (auto &carrinha: carrinhas) {
            if (carrinha.getMaxPeso() > max.getMaxPeso()) {
                max = carrinha;
                mcount = count;
            }
            count++;
        }
        auto it = carrinhas.begin();
        advance(it,mcount);
        carrinhas.erase(it);
        final.push_back(max);
    }
    return final;
}

list<Encomenda> Armazem::sortEnconmendasPeso(list<Encomenda> encomendas) {
    list<Encomenda> final;

    while (!encomendas.empty()) {
        int count =0;
        int mcount = 0;
        Encomenda max = encomendas.front();
        for (auto &encomenda: encomendas) {
            if (encomenda.getPeso() > max.getPeso()) {
                max = encomenda;
                mcount = count;
            }
            count++;
        }
        auto it = encomendas.begin();
        advance(it,mcount);
        encomendas.erase(it);
        final.push_back(max);
    }
    return final;
}

void Armazem::cenario1() {
    int volRem;
    int pesRem;
    carrinhas = this->sortCarrinhasPeso(carrinhas);
    encomendas =  this->sortEnconmendasPeso(encomendas);
    for (auto &carrinha :carrinhas){
        auto it = encomendas.begin();
        volRem = carrinha.getMaxVol();
        pesRem =carrinha.getMaxPeso();
        for (auto &encomenda : encomendas){
            if (volRem>=encomenda.getVolume() && pesRem>=encomenda.getPeso()){
                volRem -= encomenda.getVolume();
                pesRem -= encomenda.getPeso();
                encomendas.erase(it);
                carrinha.addEnconmenda(encomenda);
            }
            it++;
        }
    }
}

void Armazem::cenario2() {
    cout << "yeet";
}

void Armazem::cenario3() {
    cout << "yeet";
}
