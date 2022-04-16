//
// Created by goncalo on 04/04/22.
//

#include "../includes/Encomenda.h"

Encomenda::Encomenda(unsigned int duration, unsigned int recompensa, unsigned int volume,
                     unsigned int peso) : duration(duration), recompensa(recompensa), volume(volume),
                     peso(peso) {}
                     
unsigned int Encomenda::getDuration() const {
    return duration;
}

unsigned int Encomenda::getRecompensa() const {
    return recompensa;
}

unsigned int Encomenda::getVolume() const {
    return volume;
}

unsigned int Encomenda::getPeso() const {
    return peso;
}






