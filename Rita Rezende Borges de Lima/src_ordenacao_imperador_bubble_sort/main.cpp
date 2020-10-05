//Colocar na documentação
//https://stackoverflow.com/questions/38685724/difference-between-ms-and-s-scanf

#include "../headers/civilizacao.hpp"
#include <stdlib.h>
#include <string>


void imprime(Civilizacao *civ, int num_civilizacoes){
    for (int i = 0; i < num_civilizacoes; i++){
        civ[i].imprime();
    }
}
void bubble_sort(Civilizacao *civ, int num_civilizacoes){
    Civilizacao aux;
    for (int i = num_civilizacoes - 1; i >= 0; i--){
        for (int j = 0; j < i; j++){
            if(civ[j].get_distancia() > civ[j+1].get_distancia()){
                aux = civ[j];
                civ[j] = civ[j+1];
                civ[j+1] = aux;
            } 
            else if (civ[j].get_distancia() == civ[j+1].get_distancia() && civ[j].get_populacao() < civ[j+1].get_populacao()){
                aux = civ[j];
                civ[j] = civ[j+1];
                civ[j+1] = aux;
            }
        }
    }
}
int main(){
    char *nome;
    int num_civilizacoes, populacao, distancia;
    
    scanf("%d", &num_civilizacoes);

    Civilizacao *civilizacoes = (Civilizacao*)malloc(num_civilizacoes*sizeof(Civilizacao));

    for (int i = 0; i < num_civilizacoes; i++){
        scanf("%ms %d %d", &nome, &distancia, &populacao);
        civilizacoes[i] = Civilizacao(nome, distancia, populacao);
    }
    bubble_sort(civilizacoes, num_civilizacoes);
    imprime(civilizacoes, num_civilizacoes);
    free(civilizacoes);
    return 0;
}
