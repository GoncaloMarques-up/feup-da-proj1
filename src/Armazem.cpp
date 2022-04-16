//
// Created by ASUS on 02/04/2022.
//

#include <algorithm>
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

void Armazem::setCarrinhas(const list<Carrinha> &estafetas) {
    Armazem::carrinhas = estafetas;
}

bool c1SortCarrinhas(const Carrinha &carrinha1, const Carrinha &carrinha2) {
    return carrinha1.getMaxVol() + carrinha1.getMaxPeso() > carrinha2.getMaxVol() + carrinha2.getMaxPeso();
}

bool c1SortEncomendas(const Encomenda &encomenda1, const Encomenda &encomenda2) {
    return encomenda1.getVolume() + encomenda1.getPeso() < encomenda2.getVolume() + encomenda2.getPeso();
}

void Armazem::cenario1(){
    unsigned int volRem;
    unsigned int pesoRem;
    unsigned int numCarrinhas = 0;
    carrinhas.sort(c1SortCarrinhas);
    encomendas.sort(c1SortEncomendas);
    for(auto &carrinha : carrinhas){
        if(encomendas.empty())
            break;

        volRem = carrinha.getMaxVol();
        pesoRem = carrinha.getMaxPeso();
        auto it = encomendas.begin();
        while(!encomendas.empty() && it != encomendas.end()){
            if(!volRem || !pesoRem)
                break;
            if(it->getPeso() <= pesoRem && it->getVolume() <= volRem){
                carrinha.addEnconmenda(*it);
                pesoRem -= it->getPeso();
                volRem -= it->getVolume();
                it = this->encomendas.erase(it);
            }
            else
                it++;
        }
        numCarrinhas++;
    }
    cout << "Foram necessárias " << numCarrinhas << " Carrinhas" << endl;
    cout << "id's das carrinhas: " << endl;
    for (auto carrinha : carrinhas){
        if (!carrinha.getEncomendas().empty()){
            volRem = carrinha.getMaxVol();
            pesoRem = carrinha.getMaxPeso();
            for(auto encomenda : carrinha.getEncomendas()){
                volRem -= encomenda.getVolume();
                pesoRem -= encomenda.getPeso();
            }
            cout << carrinha.getId() << " - " << carrinha.getNumEncomendas() << " encomendas - ";
            cout << "eficiencia de peso: " <<  (double) (carrinha.getMaxPeso()-pesoRem)/carrinha.getMaxPeso() * 100 << "%" << " - eficiencia de volume: " <<  (double) (carrinha.getMaxVol()-volRem)/carrinha.getMaxVol() * 100 << "%" << endl << endl;
        }
        else  break;
    }
    cout << endl;
}

bool c2CarrinhaSort(const Carrinha &carrinha1, const Carrinha &carrinha2){
    if(carrinha1.getCusto() == carrinha2.getCusto())
        return carrinha1.getMaxPeso() + carrinha1.getMaxVol() > carrinha2.getMaxPeso() + carrinha2.getMaxVol();
    return carrinha1.getCusto() < carrinha2.getCusto();
}

bool c2EncomendasSort(const Encomenda &encomenda1, const Encomenda &encomenda2){
    if(encomenda1.getRecompensa() == encomenda2.getRecompensa())
        return encomenda1.getPeso() + encomenda1.getVolume() < encomenda2.getPeso() + encomenda1.getVolume();
    return encomenda1.getRecompensa() > encomenda2.getRecompensa();
}

int lucro(const list<Carrinha>& carrinhas){
    int lucro = 0;
    for(auto carrinha : carrinhas){
        if(carrinha.getEncomendas().empty())
            break;
        lucro -= carrinha.getCusto();
        for(auto encomenda : carrinha.getEncomendas())
            lucro += encomenda.getRecompensa();
    }

    return lucro;
}

int lucroPorCarrinha(Carrinha carrinha){
    int lucro = 0;
    lucro -= carrinha.getCusto();
    for(auto encomenda : carrinha.getEncomendas())
        lucro += encomenda.getRecompensa();

    return lucro;
}

void Armazem::cenario2() {
    carrinhas.sort(c2CarrinhaSort);
    encomendas.sort(c2EncomendasSort);

    int maxLucro = INT_MIN;

    for(auto &carrinha : carrinhas){
        unsigned int volRem = carrinha.getMaxVol(), pesoRem = carrinha.getMaxPeso();
        auto it = encomendas.begin();
        while(!encomendas.empty() && it != encomendas.end()){
           if(it->getPeso() <= pesoRem && it->getVolume() <= volRem){
                pesoRem -= it->getPeso();
                volRem -= it->getVolume();
                carrinha.addEnconmenda(*it);
                it = encomendas.erase(it);
             }
           else
               it++;
        }
        int currLucro = lucro(carrinhas);
        if(currLucro >= maxLucro)
            maxLucro = currLucro;
        else{
            carrinha.clearEncomendas();
            break;
        }
    }
    cout << "lucro máximo: " << maxLucro << "€" << endl;
    cout << "id's das carrinhas:" << endl;
    for(auto carrinha : carrinhas){
        if(!carrinha.getEncomendas().empty()){
            cout << "Carrinha " << carrinha.getId() <<  " - " << lucroPorCarrinha(carrinha)<< "€" << endl;
            continue;
        }
        cout << endl << endl;
        break;
    }
}

bool c3Sort(const Encomenda &encomenda1, const Encomenda &encomenda2){
    return encomenda1.getDuration() < encomenda2.getDuration();
}

void Armazem::cenario3(int dia) {
    list<int> time;
    int total = 0, current, workHours = 28800, tempoAcumulado = 0;

    encomendas.sort(c3Sort);
    auto it = encomendas.begin();

    while(total <= workHours && it != encomendas.end()){
        current = it->getDuration();
        if(total + current > workHours)
            break;
        total += current;
        time.push_back(current);
        it = encomendas.erase(it);
    }

    int tam = time.size();

    for(auto it1 = time.begin(); it1!=time.end(); it1++)
        for(auto it2 = it1; it2!=time.begin(); it2--)
            tempoAcumulado += *it2;

    cout << "Dia "<< dia << endl;
    cout << "Numero de Encomendas Entregues: " << tam << endl;
    cout << "Numero de Encomendas Total: " << encomendas.size() << endl;
    cout << "Perc. de Encomendas Entregues: " << (double) tam/encomendas.size() * 100 << "%" << endl;
    cout << "Tempo Acumulado: " << tempoAcumulado << endl;
    cout << "Tempo Medio: "<< (double) tempoAcumulado/tam << endl << endl;
}
