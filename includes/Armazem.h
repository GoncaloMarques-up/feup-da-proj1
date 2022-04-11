//
// Created by ASUS on 02/04/2022.
//

#ifndef PROJETO_DA_ARMAZEM_H
#define PROJETO_DA_ARMAZEM_H

#include <iostream>
#include <list>
#include <climits>
#include "Encomenda.h"
#include "Carrinha.h"

using namespace std;

class Armazem {
private:
    list<Encomenda> encomendas;
    list<Carrinha> carrinhas;
    int lucro(list<Carrinha> custos, list<Encomenda> lucros);
public:
    Armazem();
    Armazem(list<Encomenda> &encomendas, list<Carrinha> &carrinhas);

    list<Encomenda> getEncomendas() const;
    void setEncomendas(const list<Encomenda> &encomendas);

    list<Carrinha> getCarrinhas() const;
    void setCarrinhas(const list<Carrinha> &carrinhas);

    void cenario1();
    void cenario2();
    void cenario3();


};

#endif //PROJETO_DA_ARMAZEM_H
