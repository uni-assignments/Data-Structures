//Colocar na documentação
//https://stackoverflow.com/questions/38685724/difference-between-ms-and-s-scanf
//https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/

#include "../headers/civilizacao.hpp"
#include <stdlib.h>
#include <time.h> 

void imprime(Civilizacao *civ, int num_civilizacoes){
    for (int i = 0; i < num_civilizacoes; i++){
        civ[i].imprime();
    }
}
void heap_sort(Civilizacao *civ, int num_civilizacoes){
    Civilizacao aux;
    
}
void analise_experimental(double tempo){
    FILE *analise = fopen("analise_experimental.txt", "a");

    fprintf(analise, "\n %.2f segundos", tempo);
    fclose(analise); 
}


int main(){
    char *nome;
    int num_civilizacoes, populacao, distancia;
    time_t start, end; 

    scanf("%d", &num_civilizacoes);
    Civilizacao *civilizacoes = (Civilizacao*)malloc(num_civilizacoes*sizeof(Civilizacao));

    for (int i = 0; i < num_civilizacoes; i++){
        scanf("%ms %d %d", &nome, &distancia, &populacao);
        civilizacoes[i] = Civilizacao(nome, distancia, populacao);
    }
    
    time(&start);     
    heap_sort(civilizacoes, num_civilizacoes);
    time(&end); 

    analise_experimental(double(end - start));

    imprime(civilizacoes, num_civilizacoes);
    free(civilizacoes);
    return 0;
}
