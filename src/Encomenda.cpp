//
// Created by goncalo on 04/04/22.
//

#include "../includes/Encomenda.h"

Encomenda::Encomenda(unsigned int id, unsigned int duration, unsigned int recompensa, unsigned int volume,
                     unsigned int peso) : id(id), duration(duration), recompensa(recompensa), volume(volume),
                     peso(peso) {}
                     
unsigned int Encomenda::getDuration() const {
    return duration;
}

void Encomenda::setDuration(unsigned int duration) {
    Encomenda::duration = duration;
}

unsigned int Encomenda::getRecompensa() const {
    return recompensa;
}

void Encomenda::setRecompensa(unsigned int recompensa) {
    Encomenda::recompensa = recompensa;
}

unsigned int Encomenda::getVolume() const {
    return volume;
}

void Encomenda::setVolume(unsigned int volume) {
    Encomenda::volume = volume;
}

unsigned int Encomenda::getPeso() const {
    return peso;
}

void Encomenda::setPeso(unsigned int peso) {
    Encomenda::peso = peso;
}






