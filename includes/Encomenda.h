//
// Created by goncalo on 04/04/22.
//

#ifndef PROJETO_DA_ENCOMENDA_H
#define PROJETO_DA_ENCOMENDA_H


class Encomenda {
//TODO: adicionar remetente e destinario
private:
    unsigned int duration, recompensa, volume, peso;//escrevi duration pra n escrever duracao (sounds stupid)
public:
    Encomenda(unsigned int duration, unsigned int recompensa, unsigned int volume, unsigned int peso);

    unsigned int getDuration() const;

    void setDuration(unsigned int duration);

    unsigned int getRecompensa() const;

    void setRecompensa(unsigned int recompensa);

    unsigned int getVolume() const;

    void setVolume(unsigned int volume);

    unsigned int getPeso() const;

    void setPeso(unsigned int peso);

};


#endif //PROJETO_DA_ENCOMENDA_H
