#include  "./headers/civilizacao.hpp" 

Civilizacao::Civilizacao(){}

Civilizacao::Civilizacao(char *nome, int dist, int pop){
    this->nome = nome;
    this->distancia = dist;
    this->populacao = pop;
}

int Civilizacao::get_distancia(){
    return this->distancia;
}

int Civilizacao::get_populacao(){
    return this->populacao;
}

char *Civilizacao::get_nome(){
    return this->nome;
}

void Civilizacao::imprime(){
    printf("%s %d %d\n", this->nome, this->distancia, this->populacao);
}
