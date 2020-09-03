#include "../headers/lista/lista_encadeada.hpp"
#include "../headers/lista/exception.hpp"

ListaEncadeada::ListaEncadeada(){
    this->primeiro = new CelulaLista();
    this->ultimo = this->primeiro;
    this->tamanho = 0;
}

ListaEncadeada::~ListaEncadeada(){
    this->limpa();
    delete primeiro;
}

CelulaLista *ListaEncadeada::posiciona(int pos, bool antes){
    CelulaLista *p; int i;
    if((pos > tamanho) || (pos <= 0)){
        throw MyException();
    }
    p = this->primeiro;
    for(int i = 1; i < pos; i++)
        p = p->prox;
    
    if(!antes)
        p = p->prox;

    return p;    
}

Nave ListaEncadeada::get_item(int pos){
    try{
        return this->posiciona(pos, false)->nave;
    } catch(MyException& e){
        printf("%s", e.what());
    }
}

void ListaEncadeada::set_item(Nave nave, int pos){
    try{
        this->posiciona(pos, false)->nave = nave;

    } catch(MyException& e){
        printf("%s", e.what());
    }
}

void ListaEncadeada::insere_inicio(Nave nave){
    CelulaLista *nova = new CelulaLista();
    nova->nave = nave;
    nova->prox = this->primeiro->prox;
    this->primeiro->prox = nova;
    this->tamanho++;

    if(nova->prox == NULL)
        ultimo = nova;
}

void ListaEncadeada::insere_final(Nave nave){
    CelulaLista *nova = new CelulaLista();
    nova->nave = nave;
    
    this->ultimo->prox = nova;
    this->ultimo = nova;
    this->tamanho++;
}

void ListaEncadeada::insere_posicao(Nave nave, int pos){
    try{ 
        CelulaLista *c = this->posiciona(pos, true), *nova = new CelulaLista();
        nova->nave = nave;
        nova->prox = c->prox;
        c->prox = nova;
        tamanho++;

        if(nova->prox == NULL)
            ultimo = nova;
    } catch(MyException& e){
        printf("%s", e.what());
    }
    
}

Nave ListaEncadeada::remove_inicio(){
    
    if(tamanho == 0)
        throw "A lista está vazia!";
    
    CelulaLista *p = this->primeiro->prox->prox;
    Nave i = Nave(this->primeiro->prox->nave);

    delete this->primeiro->prox;
    this->primeiro->prox = p;
    this->tamanho--;

    if(primeiro->prox == NULL)
        ultimo = primeiro;
    
    return i;
}

Nave ListaEncadeada::remove_final(){
    if(tamanho == 0)
        throw "A lista está vazia!";
    
    Nave i = Nave(this->ultimo->nave);
    CelulaLista *p = posiciona(tamanho, true);
    p->prox = NULL;
    delete ultimo;
    this->ultimo = p;
    this->tamanho--;
    return i;

}

Nave ListaEncadeada::remove_posicao(int pos){
    
    try{
        CelulaLista *p = this->posiciona(pos,true), *q;
        Nave i = p->prox->nave;
        
        q = p->prox;
        p->prox = q->prox;   
        if(primeiro->prox == NULL)
            ultimo = primeiro;
        
        this->tamanho--;
        delete q;
        return i;

    }catch (MyException& e) {
        printf("%s", e.what());
    }  
    return -1; 
}

Nave ListaEncadeada::pesquisa(int chave){
    CelulaLista *aux = this->primeiro;
    while(aux!=NULL){
        if(aux->nave.get_identificador() == chave){
            return aux->nave;
            break;
        }
        aux = aux->prox;
    }   
    return -1;
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