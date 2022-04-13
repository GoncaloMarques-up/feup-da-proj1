//
// Created by ASUS on 05/04/2022.
//

#include "../includes/Menu.h"

#include <utility>

Menu::Menu(Armazem armazem) : armazem(std::move(armazem)) {}

void Menu::run() {
    mainMenu();
}

void Menu::drawMainMenu() {
    cout << "-------------- Design de Algoritmos - 2021/22 --------------" << endl;
    cout << "1 - Cenarios" << endl;
    cout << "2 - DevTeam" << endl;
    cout << "0 - Sair" << endl << endl;
}

void Menu::mainMenu() {
    int input;
    do{
        drawMainMenu();
        cin >> input;
        switch (input) {
            case 1:
                cenarios();
                break;
            case 2:
                devTeam();
                break;
            case 0:
                input = exit();
                break;
            default:
                input = 0;
        }
    } while (input!=-1);
}

void Menu::drawCenarios() {
    cout << "----------------- Escolha de Cenarios -----------------" << endl;
    cout << "1 - Cenario 1 - Otimizacao do Numero de Estafetas" << endl;
    cout << "2 - Cenario 2 - Otimizacao do Lucro da Empresa" << endl;
    cout << "3 - Cenario 3 - Otimizacao das Entregas Expresso" << endl << endl;
    cout << "0 - Sair" << endl << endl;
}

void Menu::cenarios() {
    armazem.setEncomendas(fileReader.GuardaEncomendas());
    armazem.setCarrinhas(fileReader.GuardaCarrinhas());
    int input;
    do{
        drawCenarios();
        cin >> input;
        switch (input) {
            case 1:
                Menu::armazem.cenario1();
                break;
            case 2:
                Menu::armazem.cenario2();
                break;
            case 3:
                Menu::armazem.cenario3();
                break;
            case 0:
                input = -1;
                break;
            default:
                input = 0;
        }
    } while (input!=-1);
}

void Menu::drawDevTeam() {
    cout << "----------------- DevTeam -----------------" << endl;
    cout << "201905574 - David Marques" << endl;
    cout << "202006874 - Goncalo Marques" << endl;
    cout << "202103631 - Rui Soares" << endl << endl;
    cout << "Selecione Qualquer Input para Voltar ao Menu Principal" << endl << endl;
}

void Menu::devTeam() {
    drawDevTeam();
    string input;
    cin >> input;
}

void Menu::drawExit() {
    cout << "Pretende Mesmo Sair?" << endl;
    cout << "1 - Sim" << endl;
    cout << "0 - Nao" << endl;
}

int Menu::exit() {
    drawExit();
    int input;
    cin >> input;
    if(input == 0)
        return 1;
    else
        return -1;
}
