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
    CelulaLista *p, *aux; 
    Nave n = Nave(-1);

    for (p = this->primeiro; p->prox != NULL;p = p->prox){
		if (p->prox->nave.get_identificador() == identificador){
			n = p->prox->nave;
            aux = p->prox;
            p->prox = aux->prox;
            delete aux;
            return n;
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