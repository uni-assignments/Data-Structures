#include <stdio.h>

class Civilizacao {
    
    private:
        int distancia;
        int populacao;
        char *nome;
    
    public:
        Civilizacao();
        Civilizacao(char *nome, int dist, int pop);

        int get_distancia();
        int get_populacao();
        char* get_nome();

        void imprime();
};