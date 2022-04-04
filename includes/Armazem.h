//
// Created by ASUS on 02/04/2022.
//

#ifndef PROJETO_DA_ARMAZEM_H
#define PROJETO_DA_ARMAZEM_H

#include <iostream>
#include <list>

#include "Encomenda.h"
#include "Carrinha.h"

using namespace std;

class Armazem {
private:
    list<Encomenda> encomendas;
    list<Carrinha> carrinhas;
    const float lucro_threshold = 5.0;

public:
    Armazem(list<Encomenda> &encomendas, list<Carrinha> &carrinhas, float lucroThreshold);

    list<Encomenda> getEncomendas() const;
    void setEncomendas(const list<Encomenda> &encomendas);

    const list<Carrinha> &getCarrinhas() const;
    void setCarrinhas(const list<Carrinha> &carrinhas);

    float getLucroThreshold() const;

    void cenario1();
    void cenario2();
    void cenario3();

};

#endif //PROJETO_DA_ARMAZEM_H
