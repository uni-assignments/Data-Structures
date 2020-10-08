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
void selection_sort(Civilizacao *civ, int num_civilizacoes){
    Civilizacao aux;
    int menor_index;
    for (int i = num_civilizacoes - 1; i >= 0; i--){
        menor_index = i;
        for (int j = 0; j < i; j++){
            if(civ[menor_index].get_distancia() < civ[j].get_distancia())
                menor_index = j;
            else if(civ[menor_index].get_distancia() == civ[j].get_distancia() && civ[menor_index].get_populacao() > civ[j].get_populacao())
                menor_index = j;
        }
        aux = civ[i];
        civ[i] = civ[menor_index];
        civ[menor_index] = aux;
    }
}
void analise_experimental(double tempo){
    FILE *analise = fopen("analise_experimental.txt", "a");

    fprintf(analise, "\n%.2f segundos", tempo);
    fclose(analise); 
}


int main(){
    char *nome;
    int num_civilizacoes, populacao, distancia;
    time_t start, end; 
    double time_taken;     
    scanf("%d", &num_civilizacoes);

    Civilizacao *civilizacoes = (Civilizacao*)malloc(num_civilizacoes*sizeof(Civilizacao));

    for (int i = 0; i < num_civilizacoes; i++){
        scanf("%ms %d %d", &nome, &distancia, &populacao);
        civilizacoes[i] = Civilizacao(nome, distancia, populacao);
    }
    
    time(&start);     
    selection_sort(civilizacoes, num_civilizacoes);
    time(&end); 

    time_taken = double(end - start); 
    analise_experimental(time_taken);

    imprime(civilizacoes, num_civilizacoes);
    free(civilizacoes);
    return 0;
}
