#include "../headers/lista/lista_encadeada.hpp"

ListaEncadeada::ListaEncadeada(){
    this->primeiro = new CelulaLista();
    this->ultimo = this->primeiro;
    this->tamanho = 0;
}

ListaEncadeada::~ListaEncadeada(){
    this->limpa();
    delete primeiro;
}

void ListaEncadeada::insere_final(Nave nave){
    CelulaLista *nova = new CelulaLista();
    nova->nave = nave;
    
    this->ultimo->prox = nova;
    this->ultimo = nova;
    this->tamanho++;
}

Nave ListaEncadeada::remove_por_chave(int identificador){
    CelulaLista *ant, *aux; 
    Nave n = Nave(-1);

    ant = this->primeiro;
    aux = ant->prox;
    while(aux!=NULL){
        if(aux->nave.get_identificador() == identificador){
            n = aux->nave;
            ant->prox = aux->prox;
            delete aux;
            break;
        } else {
            ant = ant->prox;
            aux = aux->prox;
        }
    }
    return n;
}

void ListaEncadeada::imprime(){
    CelulaLista *aux = this->primeiro->prox;

    while(aux!=NULL){
        aux->nave.imprime();
        aux = aux->prox;
    }   
}

void ListaEncadeada::limpa(){
    CelulaLista *p = this->primeiro->prox;
    while(p!=NULL){
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}