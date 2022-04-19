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
    bool teste = false;

public:
    explicit Menu(Armazem armazem);


    /**
     * starts the menu
     */
    void run();

    /**
     * draws the main menu
     */
    static void drawMainMenu();
    /**
     * the computation for the main menu
     */
    void mainMenu();

    /**
     * draws cenarios
     */
    static void drawCenarios();
    /**
     * the computation for cenarios
     */
    void cenarios();

    /**
     * draws the dev team
     */
    static void drawDevTeam();
    /**
     * the computation for the dev team
     */
    static void devTeam();

    /**
     * draws file options
     */
    static void drawFileChooser();
    /**
     * the computation for the file chooser
     */
    void chooseFile();

    /**
     * draws the exit
     */
    static void drawExit();
    /**
     * the computation for the exit
     */
    static int exit();

};


#endif //PROJETO_DA_MENU_H
