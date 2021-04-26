// M2.1 - Ponteiros e Alocacao Dinamica.cpp :
// Acadêmico: Sérgio Venturi Pereira

#include <iostream>
#include <time.h>

struct Inimigos {
    std::string nome;
    int vida;
};

struct Bloco {
    bool bloqueado;
    bool contemInimigo;
    Inimigos *inimigo;
};

struct Mapa {
    int altura;
    int largura;
    Bloco **blocoMapa;
};

struct Fase {
    std::string nome;
    Mapa mapaFase;
    int x;
    int *numInimigos = &x;
    Inimigos* inimigoFase = new Inimigos[*numInimigos];
};

Mapa criarMapa(int alturaMapa, int larguraMapa) {
    Mapa mapa;

    mapa.altura = alturaMapa;
    mapa.largura = larguraMapa;
    
    mapa.blocoMapa = new Bloco * [alturaMapa];

    return mapa;
}

Fase criarFase(int numInimigos, Inimigos* inimigos, int alturaMapa, int larguraMapa) {   
    Fase fasePronta;

    fasePronta.mapaFase = criarMapa(alturaMapa, larguraMapa);

    return fasePronta;

}

void primeiraFase() {
    Fase primeira;

    *primeira.numInimigos = 5;

    primeira.mapaFase.altura = 1000;
    primeira.mapaFase.largura = 1000;
    primeira.nome = "O Condado";


    primeira.inimigoFase[0].nome = "Orc";
    primeira.inimigoFase[1].nome = "Outro Orc";
    primeira.inimigoFase[2].nome = "Mestre Orc";
    primeira.inimigoFase[3].nome = "Doutor Orc";
    primeira.inimigoFase[4].nome = "Chefe Orc";
 

    for (int i = 0; i < *primeira.numInimigos; i++) {
        primeira.inimigoFase[i].vida = 100 + (rand() % 100);
    }

    criarFase(*primeira.numInimigos, primeira.inimigoFase, primeira.mapaFase.altura, primeira.mapaFase.largura);
    
    std::cout << "----------Primeira Fase------------" << std::endl << "\t\t" << primeira.nome << std::endl;



    delete[] primeira.inimigoFase;
    primeira.inimigoFase = NULL;
}


int main()
{
    primeiraFase();
    

}

