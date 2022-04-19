//
// Created by goncalo on 08/04/22.
//

#ifndef PROJETO_DA_FILEREADER_H
#define PROJETO_DA_FILEREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "Armazem.h"
#include "Encomenda.h"
#include "Carrinha.h"

class FileReader {
public:
    FileReader();

    /**
     * loads the trucks from the file carrinhas.txt into a list
     * @return a list of the object Carrinha with the trucks from the file carrinhas.txt
     */
    static list<Carrinha> GuardaCarrinhas();
    /**
     * loads the packages from the file encomendas.txt into a list
     * @return a list of the object Encomenda with the trucks from the file encomendas.txt
     */
    static list<Encomenda> GuardaEncomendas();


};


#endif //PROJETO_DA_FILEREADER_H
