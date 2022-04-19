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
public:
    Armazem();

    list<Encomenda> getEncomendas() const;
    void setEncomendas(const list<Encomenda> &entregas);

    void setCarrinhas(const list<Carrinha> &estafetas);
    /**
     * prints the arrangement of trucks and packages where the number of trucks is the minimum possible
     * to deliver all of the packages
     * this function uses a greedy algorithm and has a complexity of (n+nlogn+m+m^2logm)
     * where n is the number of trucks and m is the number of packages
     *
     */
    void cenario1();
    /**
     * prints the arrangement of trucks and packages where the profit is the maximum
     * this function uses a greedy algorithm and has a complexity of (n+nlogn+m+m^2logm)
     * where n is the number of trucks and m is the number of packages
     */
    void cenario2();
    /**
     * prints the number of express packages delivered int that day,
     * the total number of expresse packages, the percentege of packages delivered
     * all the time that took to deliver the packages and the average time of each delivery
     * this function uses a greedy algorithm and has a complexity of (n+nlogn)
     * where n is the number packages
     * @param dia an integer that represents the day that the function is computing
     */

    void cenario3(int dia);

};

#endif //PROJETO_DA_ARMAZEM_H
