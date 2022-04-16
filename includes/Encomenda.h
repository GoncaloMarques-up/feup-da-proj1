//
// Created by goncalo on 04/04/22.
//

#ifndef PROJETO_DA_ENCOMENDA_H
#define PROJETO_DA_ENCOMENDA_H


class Encomenda {
//TODO: adicionar remetente e destinario
private:
    unsigned int duration, recompensa, volume, peso;

    //escrevi duration pra n escrever duracao (sounds stupid)
public:
    Encomenda(unsigned int duration, unsigned int recompensa, unsigned int volume, unsigned int peso);

    unsigned int getDuration() const;

    unsigned int getRecompensa() const;

    unsigned int getVolume() const;

    unsigned int getPeso() const;

};


#endif //PROJETO_DA_ENCOMENDA_H
