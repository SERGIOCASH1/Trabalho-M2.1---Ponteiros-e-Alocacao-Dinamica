// M2.1 - Ponteiros e Alocacao Dinamica.cpp :
// Acadêmico: Sérgio Venturi Pereira

#include <iostream>

struct Inimigos {
    std::string nome;
    int vida;
};

struct Bloco {
    bool bloqueado;
    bool contemInimigo;
    Inimigos inimigo;
};

struct Mapa {
    int altura;
    int largura;
    Bloco blocoMapa[10][10];
};

struct Fase {
    std::string nome;
    Mapa mapaFase;
    int numInimigos;
    Inimigos vetorInimigos[10];
};

Mapa criarMapa(int altura, int largura) {
    Mapa teste;
    int C = 10;
    int L = 10;
    int i, j;
    int matriz[10][10] = {0};

    std::cout << "\t\t\t\t\t\t         ";      
    for(i=0; i<L; i++){
      std::cout << "_ ";
    }

    std::cout << std::endl;
    for(i=0; i<L; i++){
			std::cout << "\t\t\t\t\t\t       " << i << "|" << "";
        for(j=0; j<C; j++){
        if (matriz[i][j] == 1){
        if(matriz[i][j] == 9){
            std::cout << "x ";
                }else
                    std::cout << matriz[i][j] << "|";
            }
            else
                std::cout << "_|";
        }
        std::cout << std::endl;
    }
    return teste;
}

Fase criarFase(int numInimigos, Inimigos* inimigos, int alturaMapa, int larguraMapa) {   
    Fase fasePronta;
    criarMapa(alturaMapa, larguraMapa);
    return fasePronta;

}

void primeiraFase() {
    Fase primeira;

    primeira.numInimigos = 5;
    primeira.mapaFase.altura = 100;
    primeira.mapaFase.largura = 100;
    primeira.nome = "O Condado";

    primeira.vetorInimigos[0].nome = "Orc";
    primeira.vetorInimigos[1].nome = "Outro Orc";
    primeira.vetorInimigos[2].nome = "Mestre Orc";
    primeira.vetorInimigos[3].nome = "Doutor Orc";
    primeira.vetorInimigos[4].nome = "Chefe Orc";
 

    for (int i = 0; i < 5; i++) {
        primeira.vetorInimigos[i].vida = 100 + (rand() % 100);
    }

    criarFase(primeira.numInimigos, primeira.vetorInimigos, primeira.mapaFase.altura, primeira.mapaFase.largura);
}


int main()
{
    primeiraFase();


}

