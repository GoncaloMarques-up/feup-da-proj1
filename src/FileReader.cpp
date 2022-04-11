//
// Created by goncalo on 08/04/22.
//


#include "../includes/FileReader.h"

FileReader::FileReader() = default;

list<Carrinha> FileReader::GuardaCarrinhas() {
    ifstream loadEstafetas("../data/carrinhas.txt");
    if(!loadEstafetas.is_open())
        exit(EXIT_FAILURE);
    string data;
    int id = 0;
    getline(loadEstafetas, data);
    list<Carrinha> carrinhas;
    while(getline (loadEstafetas, data)){
        istringstream iss(data);
        string token;
        int volMax, pesoMax, custo;
        getline(iss, token, ' ');
        istringstream(token) >> volMax;
        getline(iss, token, ' ');
        istringstream(token) >> pesoMax;
        getline(iss, token, '\n');
        istringstream(token) >> custo;
        carrinhas.emplace_back(id, volMax, pesoMax, custo);
        id++;
    }
    loadEstafetas.close();
    return carrinhas;
}

list<Encomenda> FileReader::GuardaEncomendas() {
    ifstream loadEncomendas("../data/encomendas.txt");
    if(!loadEncomendas.is_open())
        exit(EXIT_FAILURE);
    string data;
    int id = 0;
    getline(loadEncomendas, data);
    list<Encomenda> encomendas;

    while(getline (loadEncomendas, data)){
        istringstream iss(data);
        string token;
        int vol, peso, recompensa, duration;
        getline(iss, token, ' ');
        istringstream(token) >> vol;
        getline(iss, token, ' ');
        istringstream(token) >> peso;
        getline(iss, token, ' ');
        istringstream(token) >> recompensa;
        getline(iss, token, '\n');
        istringstream(token) >> duration;
        encomendas.emplace_back(id, duration, recompensa, vol, peso);
        id++;
    }
    loadEncomendas.close();
    return encomendas;
}
