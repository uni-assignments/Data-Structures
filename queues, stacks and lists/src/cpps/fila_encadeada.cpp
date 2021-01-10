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

void FilaEncadeada::enfileira(Nave nave){
    CelulaFila *nova = new CelulaFila();
    nova->nave = nave;
    this->tras->prox = nova;
    this->tras = nova;
    this->tamanho++;
}
  
Nave FilaEncadeada::desenfileira(){
    CelulaFila *p;
    Nave aux;
    
    if(this->vazia())
        return -1;
    
    aux = this->frente->prox->nave;
    p = this->frente;
    this->frente = this->frente->prox;
    delete p;
    this->tamanho--;

    return aux;
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