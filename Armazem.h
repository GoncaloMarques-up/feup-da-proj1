//
// Created by ASUS on 02/04/2022.
//

#ifndef PROJETO_DA_ARMAZEM_H
#define PROJETO_DA_ARMAZEM_H

#include <iostream>
#include <list>

using namespace std;

class Armazem {
private:
    list<int> encomendas;
    list<int> estafetas;
    const float lucro_threshold = 5.0;

public:
    const list<int> &getEncomendas() const;
    void setEncomendas(const list<int> &encomendas);

    const list<int> &getEstafetas() const;
    void setEstafetas(const list<int> &estafetas);

    const float getLucroThreshold() const;

    void cenario1();
    void cenario2();
    void cenario3();

};


#endif //PROJETO_DA_ARMAZEM_H
