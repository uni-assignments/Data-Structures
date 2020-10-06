//Colocar na documentação
//https://stackoverflow.com/questions/38685724/difference-between-ms-and-s-scanf

#include "../headers/civilizacao.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>       /* ceil */

void imprime(Civilizacao *civ, int num_civilizacoes){
    for (int i = 0; i < num_civilizacoes; i++){
        civ[i].imprime();
    }
}
void analise_experimental(double tempo){
    FILE *analise = fopen("analise_experimental.txt", "a");

    fprintf(analise, "\n%.2f segundos", tempo);
    fclose(analise); 
}
int escolhe_pivot(Civilizacao *civ, int esq, int meio, int dir){
    
    if((civ[esq].get_distancia() <= civ[meio].get_distancia() && civ[meio].get_distancia() <= civ[dir].get_distancia()) || 
        (civ[dir].get_distancia() <= civ[meio].get_distancia() && civ[meio].get_distancia() <= civ[esq].get_distancia())) return meio;
    
    else if((civ[meio].get_distancia() <= civ[esq].get_distancia() && civ[esq].get_distancia() <= civ[dir].get_distancia()) || 
        (civ[dir].get_distancia() <= civ[esq].get_distancia() && civ[esq].get_distancia() <= civ[meio].get_distancia())) return esq;
    
    return dir;

}



void quick_sort(Civilizacao *civ, int esq, int dir){
    Civilizacao aux = Civilizacao();
    int i = esq, j = dir;
    
    int index_pivot = escolhe_pivot(civ, esq, ((i+j)/2), dir);
    
    int distancia_pivot = civ[index_pivot].get_distancia();
    int populacao_pivot = civ[index_pivot].get_populacao();

    while(i <= j){
        while((civ[i].get_distancia() < distancia_pivot || (civ[i].get_distancia() == distancia_pivot && civ[i].get_populacao() > populacao_pivot)) && i < dir) i++;
        while((civ[j].get_distancia() > distancia_pivot || (civ[j].get_distancia() == distancia_pivot && civ[j].get_populacao() < populacao_pivot)) && j > esq) j--;
        if(i <= j){
            aux = civ[i];
            civ[i] = civ[j];
            civ[j] = aux;
            i++;
            j--;
        }
    }

    if(j > esq) 
        quick_sort(civ, esq, j);
    if(i < dir) 
        quick_sort(civ, i, dir);
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
    quick_sort(civilizacoes, 0, num_civilizacoes - 1);
    time(&end); 

    time_taken = double(end - start); 
    analise_experimental(time_taken);


    imprime(civilizacoes, num_civilizacoes);
    free(civilizacoes);
    return 0;
}
