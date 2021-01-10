#ifndef PILHA_ENCADEADA_H
#define PILHA_ENCADEADA_H

#include "../nave.hpp"
#include "celula.hpp"

class PilhaEncadeada{
    protected:
        int tamanho;
    
    private:
        CelulaPilha *topo;

    public: 
        PilhaEncadeada();
        virtual ~PilhaEncadeada();
        int get_tamanho(){ return tamanho; };
        bool vazia(){ return tamanho == 0; };
        

        void empilha(Nave item);
        Nave desempilha();
        void imprime();

};

#endif