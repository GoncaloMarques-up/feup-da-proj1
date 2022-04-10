//
// Created by goncalo on 08/04/22.
//

#ifndef PROJETO_DA_FILEREADER_H
#define PROJETO_DA_FILEREADER_H

#include <iostream>
#include <fstream>
#include "Armazem.h"

class FileReader {
public:
    FileReader();
    void GuardaCarrinhas(Armazem &armazem);
    void GuardaEncomendas(Armazem &armazem);

};


#endif //PROJETO_DA_FILEREADER_H
