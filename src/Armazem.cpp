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

list<Carrinha> Armazem::getCarrinhas() const {
    return carrinhas;
}

void Armazem::setCarrinhas(const list<Carrinha> &estafetas) {
    Armazem::carrinhas = estafetas;
}


//bool sortCarrinhasPeso(const Carrinha &carrinha1, const Carrinha &carrinha2) {
//    return carrinha1.getMaxPeso()>carrinha2.getMaxPeso();
//
//}
//
//bool sortEnconmendasPeso(const Encomenda &encomenda1, const Encomenda &encomenda2) {
//    return encomenda1.getPeso()>encomenda2.getPeso();
//}

bool sortCarrinhasVolume(const Carrinha &carrinha1, const Carrinha &carrinha2) {
    return carrinha1.getMaxVol()>carrinha2.getMaxPeso();
}

bool sortEnconmendasVolume(const Encomenda &encomenda1, const Encomenda &encomenda2) {
    return encomenda1.getVolume()>encomenda2.getVolume();
}

void Armazem::cenario1() {
    int volRem;
    int pesRem;
    carrinhas.sort(sortCarrinhasVolume);
    encomendas.sort(sortEnconmendasVolume);
    list<Carrinha> carrinhas1 = carrinhas;
    list<Encomenda> encomendas1 = encomendas;
    for (auto &carrinha :carrinhas1){
        auto it = encomendas1.begin();
        volRem = carrinha.getMaxVol();
        pesRem =carrinha.getMaxPeso();
        for (auto &encomenda : encomendas1){
            if (volRem == 0 || pesRem == 0) break;
            if (volRem>=encomenda.getVolume() && pesRem>=encomenda.getPeso()){
                volRem -= encomenda.getVolume();
                pesRem -= encomenda.getPeso();
                carrinha.addEnconmenda(encomenda);
                encomendas1.erase(it);
            }
            it++;
        }
    }
    int res1 =0;
    for (auto &carrinha :carrinhas1){
        if (!carrinha.getEncomendas().empty()) res1++;
        else break;
    }
//    carrinhas.sort(sortCarrinhasPeso);
//    encomendas.sort(sortEnconmendasPeso);
//    list<Carrinha> carrinhas2 = carrinhas;
//    list<Encomenda> encomendas2 = encomendas;
//
//    for (auto &carrinha :carrinhas2){
//        auto it = encomendas2.begin();
//        volRem = carrinha.getMaxVol();
//        pesRem =carrinha.getMaxPeso();
//        for (auto &encomenda : encomendas2){
//            if (volRem == 0 || pesRem == 0) break;
//            if (volRem>=encomenda.getVolume() && pesRem>=encomenda.getPeso()){
//                volRem -= encomenda.getVolume();
//                pesRem -= encomenda.getPeso();
//                carrinha.addEnconmenda(encomenda);
//                encomendas2.erase(it);
//            }
//            it++;
//        }
//    }
//    int res2 =0;
//    for (auto &carrinha :carrinhas2){
//        if (!carrinha.getEncomendas().empty()) res2 ++;
//        else break;
//    }

//    if (res1 < res2){
//        for (auto &carrinha :carrinhas1){
//            if (!carrinha.getEncomendas().empty()) cout << carrinha.getId() << endl;
//            else  break;
//        }
//    } else {
//        for (auto &carrinha :carrinhas2){
//            if (!carrinha.getEncomendas().empty()) cout << carrinha.getId() << endl;
//            else  break;
//        }
//    }

    for (auto &carrinha : carrinhas1){
        if (!carrinha.getEncomendas().empty()) cout << carrinha.getId() << endl;
        else  break;
    }


}

bool c2CarrinhaSort(const Carrinha &carrinha1, const Carrinha &carrinha2){
    if(carrinha1.getCusto() == carrinha2.getCusto())
        return carrinha1.getMaxPeso() < carrinha2.getMaxPeso();
    return carrinha1.getCusto() < carrinha2.getCusto();
}

bool c2EncomendasSort(const Encomenda &encomenda1, const Encomenda &encomenda2){
    if(encomenda1.getRecompensa() == encomenda2.getRecompensa())
        return encomenda1.getPeso() < encomenda2.getPeso();
    return encomenda1.getRecompensa() > encomenda2.getRecompensa();
}

void Armazem::cenario2() {
    /* ideias:
     * "greedy": ordenar encomendas por recompensa(descendente) e estafetas por custo(ascendente) e inserir até alcançar o lucro maximo.
     * outras possibilidades por definir.
     */
    carrinhas.sort(c2CarrinhaSort);
    encomendas.sort(c2EncomendasSort);

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


bool c3Sort(const Encomenda &encomenda1, const Encomenda &encomenda2){
    return encomenda1.getDuration() < encomenda2.getDuration();
}

void Armazem::cenario3(int dia) {
    // 8 horas = 480 min = 28800 seg
    list<int> time;
    int total = 0, current, workHours = 28800, totalEncomendas = encomendas.size(), tempoAcumulado = 0;

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
    cout << "Numero de Encomendas Total: " << totalEncomendas << endl;
    cout << "Perc. de Encomendas Entregues: " << (double) tam/totalEncomendas * 100 << "%" << endl;
    cout << "Tempo Acumulado: " << tempoAcumulado << endl;
    cout << "Tempo Medio: "<< (double) tempoAcumulado/tam << endl << endl;
}
