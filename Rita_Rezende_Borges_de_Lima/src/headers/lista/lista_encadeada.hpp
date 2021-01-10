#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
 
#include "../nave.hpp"
#include "celula.hpp"

class ListaEncadeada{

    public:
        ListaEncadeada();
        ~ListaEncadeada();
        int getTamanho(){return this->tamanho;};
        bool vazia(){return this->tamanho == 0;};

        void insere_final (Nave nave);
        Nave remove_por_chave(int identificador);
        void imprime();
        void limpa();

    private:
        int tamanho;
        CelulaLista *primeiro;
        CelulaLista *ultimo;
        CelulaLista *posiciona(int pos, bool antes);
};

#endif