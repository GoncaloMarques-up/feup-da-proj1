#include "includes/Menu.h"

int main() {
    //std::cout << "Hello, World!" << std::endl;
//    Menu m;
//    m.run();
    Carrinha *carrinha1 =  new Carrinha(100,250,0);
    Carrinha *carrinha2 =  new Carrinha(150,300,0);
    Carrinha *carrinha3 =  new Carrinha(150,200,0);
    Carrinha *carrinha4 =  new Carrinha(150,230,0);

    Encomenda *encomenda1 = new Encomenda(0,0,0,10);
    Encomenda *encomenda2 = new Encomenda(0,0,0,20);
    Encomenda *encomenda3 = new Encomenda(0,0,0,50);
    Encomenda *encomenda4 = new Encomenda(0,0,0,15);
    Encomenda *encomenda5 = new Encomenda(0,0,0,100);
    Encomenda *encomenda6 = new Encomenda(0,0,0,40);
    Encomenda *encomenda7 = new Encomenda(0,0,0,200);
    Encomenda *encomenda8 = new Encomenda(0,0,0,15);
    Encomenda *encomenda9 = new Encomenda(0,0,0,11);

    Armazem armazem;
    list<Encomenda> encomendas {*encomenda1,*encomenda2,*encomenda3,*encomenda4,*encomenda5,*encomenda6,*encomenda7,*encomenda8,*encomenda9};
    list<Carrinha> carrinhas {*carrinha1,*carrinha2, *carrinha3,*carrinha4};

    armazem.setCarrinhas(carrinhas);
    armazem.setEncomendas(encomendas);
    armazem.cenario1();

    for (auto &carrinha : armazem.getCarrinhas()){
        for (auto &encomenda : carrinha.getEncomendas()){
            cout << carrinha.getMaxPeso() << " " << encomenda.getPeso() << endl;
        }
    }
    return 0;
}
