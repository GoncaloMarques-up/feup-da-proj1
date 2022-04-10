//
// Created by ASUS on 05/04/2022.
//

#ifndef PROJETO_DA_MENU_H
#define PROJETO_DA_MENU_H

#include <iostream>
#include <string>

#include "Armazem.h"

using namespace std;

class Menu {
private:
    Armazem armazem;

public:
    Menu();

    void run();

    void drawMainMenu();
    void mainMenu();

    void drawCenarios();
    void cenarios();

    void drawDevTeam();
    void devTeam();

    void drawLoadFiles();
    void loadFiles();

    void drawExit();
    int exit();

    const Armazem & getArmazem() const;

};


#endif //PROJETO_DA_MENU_H
