#include "../headers/pilha/pilha_encadeada.hpp"

PilhaEncadeada::PilhaEncadeada(){
    topo = NULL;
    this->tamanho = 0;
}

PilhaEncadeada::~PilhaEncadeada(){
    while(!this->vazia()){
        this->desempilha();
    }
}

void PilhaEncadeada::empilha(Nave nave){
    CelulaPilha *nova = new CelulaPilha();
    
    nova->nave = nave;
    nova->prox = topo;
    this->topo = nova;
    this->tamanho++;
}

Nave PilhaEncadeada::desempilha(){
    if(tamanho == 0)
        throw "A pilha está vazia!";
    
    Nave nave = this->topo->nave;
    CelulaPilha *topo_antigo = this->topo;
    
    this->topo = this->topo->prox;
    delete topo_antigo;
    this->tamanho--;

    return nave;
}

void PilhaEncadeada::imprime(){
    CelulaPilha *aux = this->topo;
    while(aux != NULL){
        aux->nave.imprime();
        printf("\n");
        aux = aux->prox;
    }
    delete aux;
}