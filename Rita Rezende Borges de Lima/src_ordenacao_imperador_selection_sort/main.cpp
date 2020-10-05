//Colocar na documentação
//https://stackoverflow.com/questions/38685724/difference-between-ms-and-s-scanf
//https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/

#include "../headers/civilizacao.hpp"
#include <stdlib.h>
#include <string>


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
    
    imprime(civilizacoes, num_civilizacoes);
    printf("\n%.10f\n", time_taken);
    free(civilizacoes);
    return 0;
}
