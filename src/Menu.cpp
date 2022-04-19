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
    cout << "3 - Escolha de ficheiros" << endl;
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
            case 3:
                chooseFile();
                break;
            case 0:
                input = exit();
                break;
        }
    } while (input);
}

void Menu::drawCenarios() {
    cout << "----------------- Escolha de Cenarios -----------------" << endl;
    cout << "1 - Cenario 1 - Otimizacao do Numero de Estafetas" << endl;
    cout << "2 - Cenario 2 - Otimizacao do Lucro da Empresa" << endl;
    cout << "3 - Cenario 3 - Otimizacao das Entregas Expresso" << endl << endl;
    cout << "0 - Sair" << endl << endl;
}

void Menu::cenarios() {
    int input;
    do{
        if(!teste){
            armazem.setEncomendas(FileReader::GuardaEncomendas("encomendas.txt"));
            armazem.setCarrinhas(FileReader::GuardaCarrinhas("carrinhas.txt"));
        }
        else {
            armazem.setEncomendas(FileReader::GuardaEncomendas("encomendas_teste.txt"));
            armazem.setCarrinhas(FileReader::GuardaCarrinhas("carrinhas_teste.txt"));
        }

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
                int dia = 0;
                do{
                    dia++;
                    Menu::armazem.cenario3(dia);
                    cout << "Pretende continuar?" << endl;
                    cout << "1 - Sim" << endl;
                    cout << "2 - Nao" << endl;
                    cin >> input;
                }while(input!=2 && !armazem.getEncomendas().empty());
                if(armazem.getEncomendas().empty()){
                    cout << "Todas as Encomendas Foram entregues ao fim de " << dia << " dias." << endl;
                }
                break;
        }
    } while (input);
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
    return !input;
}

void Menu::drawFileChooser() {
    cout << "----------------- Escolha de Ficheiros -----------------" << endl;
    cout << "1 - Dataset de Teste (mais pequeno)" << endl;
    cout << "2 - Dataset Principal (maior)" << endl;
    cout << "0 - Sair" << endl << endl;
}

void Menu::chooseFile() {
    int input;
    do{
        drawFileChooser();
        cin >> input;
        switch (input) {
            case 1:
                teste = true;
                break;
            case 2:
                teste = false;
                break;
            case 0:
                input = 0;
    }
    }while(input);
}
