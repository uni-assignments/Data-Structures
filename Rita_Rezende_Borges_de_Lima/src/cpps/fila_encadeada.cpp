#include "../headers/fila/fila_encadeada.hpp"


FilaEncadeada::FilaEncadeada(){
    this->tamanho = 0;
    this->frente = new CelulaFila();
    this->tras = frente; 
}

FilaEncadeada::~FilaEncadeada(){
    limpa();
    delete this->frente;
}    

void FilaEncadeada::imprime(){
    CelulaFila *aux = this->frente->prox;
    while(aux !=NULL){
        aux->nave.imprime();
        printf("\n");
        aux = aux->prox;
    }
}

void FilaEncadeada::enfileira(Nave i){
    CelulaFila *nova = new CelulaFila();
    nova->nave = i;
    this->tras->prox = nova;
    this->tras = nova;
    this->tamanho++;
}

Nave FilaEncadeada::desenfileira(){
    CelulaFila *aux;
    if(tamanho == 0)
        throw "Fila está vazia!";
    

    Nave saida = this->frente->prox->nave; 
    aux = this->frente;
    this->frente = frente->prox;
    this->tamanho--;
    delete aux;
    
    return saida;
}    

void FilaEncadeada::limpa(){
    CelulaFila *p = this->frente->prox;
    while(p!=NULL){
        this->frente->prox = p->prox;
        delete p;
        p = this->frente->prox;
    }
    tamanho = 0;
    tras = frente;
}