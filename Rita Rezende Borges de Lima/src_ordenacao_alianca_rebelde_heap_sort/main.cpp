//Colocar na documentação
//https://stackoverflow.com/questions/38685724/difference-between-ms-and-s-scanf
//https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/

#include "./headers/civilizacao.hpp"
#include <stdlib.h>
#include <time.h> 

void imprime(Civilizacao *civ, int num_civilizacoes){
    for (int i = 1; i < num_civilizacoes; i++){
        civ[i].imprime();
    }
}

void refaz(Civilizacao *civ, int esq, int dir){
    int i = esq, j = i*2;
    Civilizacao x = civ[i];
    while(j <= dir){
        if(j < dir){
            if(civ[j].get_distancia() < civ[j+1].get_distancia()) j++;
            else if(civ[j].get_distancia() == civ[j+1].get_distancia() && civ[j].get_populacao() > civ[j+1].get_populacao()) j++;
        } 
        if(x.get_distancia() > civ[j].get_distancia()) break;
        else if(x.get_distancia() == civ[j].get_distancia() && x.get_populacao() < civ[j].get_populacao()) break;

        civ[i] = civ[j];
        i = j;
        j = i*2;
    
    }
    civ[i] = x;
}

void controi_heap(Civilizacao *civ, int num_civ){
    int esq = num_civ/2 + 1;
    while(esq > 1){
        esq--;
        refaz(civ, esq, num_civ);
    }
}

void heap_sort(Civilizacao *civ, int num_civilizacoes){
    Civilizacao aux;
    int esq = 1, dir = num_civilizacoes;
    controi_heap(civ, num_civilizacoes);
    while(dir > 1){
        aux = civ[1];
        civ[1] = civ[dir];
        civ[dir] = aux;
        dir--;
        refaz(civ, esq, dir);
    }
    
}
void analise_experimental(double tempo){
    FILE *analise = fopen("analise_experimental.txt", "a");

    fprintf(analise, "\n%.2f segundos", tempo);
    fclose(analise); 
    
    free(analise);
}

int main(){
    char *nome;
    int num_civilizacoes, populacao, distancia;
    time_t start, end; 

    scanf("%d", &num_civilizacoes);
    num_civilizacoes++;
    Civilizacao *civilizacoes = (Civilizacao*)malloc(num_civilizacoes*sizeof(Civilizacao));

    for (int i = 1; i < num_civilizacoes; i++){
        scanf("%ms %d %d", &nome, &distancia, &populacao);
        civilizacoes[i] = Civilizacao(nome, distancia, populacao);
    }

    time(&start);     
    heap_sort(civilizacoes, num_civilizacoes - 1);
    time(&end); 

    analise_experimental(double(end - start));

    imprime(civilizacoes, num_civilizacoes);
    
    free(nome);
    free(civilizacoes);
    
    return 0;   
}
