//
// Created by ASUS on 05/04/2022.
//

#ifndef PROJETO_DA_MENU_H
#define PROJETO_DA_MENU_H

#include <iostream>
#include <string>

#include "Armazem.h"
#include "FileReader.h"

using namespace std;

class Menu {
private:
    Armazem armazem;
    FileReader fileReader;

public:
    Menu(Armazem armazem);

    void run();

    static void drawMainMenu();
    void mainMenu();

    static void drawCenarios();
    void cenarios();

    static void drawDevTeam();
    static void devTeam();

    static void drawExit();
    static int exit();

};


#endif //PROJETO_DA_MENU_H
