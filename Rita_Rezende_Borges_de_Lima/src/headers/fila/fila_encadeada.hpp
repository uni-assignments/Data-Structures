#ifndef FILA_ENCADEADA_H
#define FILA_ENCADEADA_H
 
#include "../nave.hpp"
#include "celula.hpp"

class FilaEncadeada{

    public:
        FilaEncadeada();
        virtual ~FilaEncadeada();
        int get_tamanho(){return this->tamanho;};
        bool vazia(){return this->tamanho == 0;};

        void imprime();
        void enfileira(Nave i);
        Nave desenfileira();
        void limpa();
    
    private:
        CelulaFila* frente;
        CelulaFila* tras;
        
    protected:
        int tamanho;

};

#endif