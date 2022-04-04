//
// Created by goncalo on 04/04/22.
//

#ifndef PROJETO_DA_ESTAFETA_H
#define PROJETO_DA_ESTAFETA_H

#include <iostream>

using namespace std;

class Estafeta {
private:
    string matricula;//talvez mudar para int depois
    unsigned int maxVol, maxPeso, custo;

public:
    Estafeta(string matricula, unsigned int maxVol, unsigned int maxPeso, unsigned int custo);

    const string &getMatricula() const;

    void setMatricula(const string &matricula);

    unsigned int getMaxVol() const;

    void setMaxVol(unsigned int maxVol);

    unsigned int getMaxPeso() const;

    void setMaxPeso(unsigned int maxPeso);

    unsigned int getCusto() const;

    void setCusto(unsigned int custo);
};


#endif //PROJETO_DA_ESTAFETA_H
