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

void Armazem::setCarrinhas(const list<Carrinha> &estafetas) {
    Armazem::carrinhas = estafetas;
}


/**
 * bool function to auxiliate the sort of list<Carrinha>
 * @param carrinha1
 * @param carrinha2
 * @return true if MaxVol+MaxPeso of carrinha1 is bigger than MaxVol+MaxPeso of carrinha2 and false otherwise
 */
bool c1SortCarrinhas(const Carrinha &carrinha1, const Carrinha &carrinha2) {
    return carrinha1.getMaxVol() + carrinha1.getMaxPeso() > carrinha2.getMaxVol() + carrinha2.getMaxPeso();
}

/// returns
/**
 * bool function to auxiliate the sort of list<Encomenda>
 * @param encomenda1
 * @param encomenda2
 * @return true if Volume+Peso of encomenda1 is bigger than Volume+Peso of encomenda2 and false otherwise
 */
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

/**
 * bool function to auxilate the sort of list<Carrinha>
 * @param carrinha1
 * @param carrinha2
 * @return true if carrinha2 custo is bigger than carrinha1 custo and returns false if carrinha1 custo is bigger than carrinha2 custo, if the two values are equal it compares the maxPeso+maxVol of the two objects and returns trues if the value of carrinha1 is bigger than the values of carrinha2 else it returns false
 */
bool c2CarrinhaSort(const Carrinha &carrinha1, const Carrinha &carrinha2){
    if(carrinha1.getCusto() == carrinha2.getCusto())
        return carrinha1.getMaxPeso() + carrinha1.getMaxVol() > carrinha2.getMaxPeso() + carrinha2.getMaxVol();
    return carrinha1.getCusto() < carrinha2.getCusto();
}

/**
 * bool function to auxilate the sort of list<Encomenda>
 * @param encomenda1
 * @param encomenda2
 * @return true if encomenda1 recompensa is bigger than encomenda2 recompena and returns false if encomenda2 recompena is bigger than encomenda1 recompensa, if the two values are equal it compares the Peso+Volume of the two objects and returns trues if the value of encomenda1 is smaller than the values of encomenda2 else it returns false
 */
bool c2EncomendasSort(const Encomenda &encomenda1, const Encomenda &encomenda2){
    if(encomenda1.getRecompensa() == encomenda2.getRecompensa())
        return encomenda1.getPeso() + encomenda1.getVolume() < encomenda2.getPeso() + encomenda1.getVolume();
    return encomenda1.getRecompensa() > encomenda2.getRecompensa();
}


/**
 * computes the sum of the custo if all the trucks in the list
 * @param carrinhas
 * @return integer lucro
 */
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


/**
 * computes the sum of the recompensa of all the packages in the truck
 * @param carrinha
 * @return integer lucro
 */
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

/**
 * bool function to auxilate the sort of list<Encomenda>
 * @param encomenda1
 * @param encomenda2
 * @return true if duration of encomenda1 is smller than durationj of encomenda2 and flase otherwise
 */
bool c3Sort(const Encomenda &encomenda1, const Encomenda &encomenda2){
    return encomenda1.getDuration() < encomenda2.getDuration();
}

void Armazem::cenario3(int dia) {
    list<int> time;
    int total = 0, current, workHours = 28800, tempoAcumulado = 0, nTotal = encomendas.size();

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

    auto it1 = time.end();
    for(int i = 1; i <= time.size(); i++){
        tempoAcumulado += i * (*it1);
        it1--;
    }



    cout << "Dia "<< dia << endl;
    cout << "Numero de Encomendas Entregues: " << tam << endl;
    cout << "Numero de Encomendas Total: " << nTotal << endl;
    cout << "Perc. de Encomendas Entregues: " << (double) tam/nTotal * 100 << "%" << endl;
    cout << "Tempo Total: " << total << endl;
    cout << "Tempo Medio: "<< (double) tempoAcumulado/tam << endl << endl;
}
