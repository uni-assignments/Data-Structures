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

        Nave get_item(int pos);
        void set_item(Nave nave, int pos);
        void insere_inicio(Nave nave);
        void insere_final (Nave nave);
        void insere_posicao (Nave nave, int pos);
        Nave remove_inicio();
        Nave remove_final ();
        Nave remove_posicao (int pos);
        Nave pesquisa(int chave);
        void imprime();
        void limpa();

    private:
        int tamanho;
        CelulaLista *primeiro;
        CelulaLista *ultimo;
        CelulaLista *posiciona(int pos, bool antes);
};

#endif