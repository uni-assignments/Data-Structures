#include <cstdio> // em C substituir por #include <stdio.h>
#include "./headers/pilha/pilha_encadeada.hpp"
#include "./headers/lista/lista_encadeada.hpp"
#include "./headers/fila/fila_encadeada.hpp"

void operacao_pedida(int operacao, PilhaEncadeada *preparacao, ListaEncadeada *combate, FilaEncadeada *avariada){
	Nave n;
	switch (operacao){
		case 0:
			n = preparacao->desempilha();
			combate->insere_final(n);
			printf("nave %d em combate\n", n.get_identificador());
			break;
		case -1:
			n = avariada->desenfileira();
			preparacao->empilha(n);
			printf("nave %d consertada\n", n.get_identificador());
			break;
		case -2:
			preparacao->imprime();
			break;
		case -3:
			avariada->imprime();
			break;
		default:
			n = combate->remove_por_chave(operacao);
			if(n.get_identificador() != -1)
				avariada->enfileira(n);
			printf("nave %d avariada\n", n.get_identificador());
			break;
	}
}


int main() {
	int num_frotas, id_nave;
	PilhaEncadeada *preparacao = new PilhaEncadeada();
	ListaEncadeada *combate = new ListaEncadeada();
	FilaEncadeada *avariada = new FilaEncadeada();

	Nave n;

	scanf("%d",&num_frotas);

	for(int i=0; i < num_frotas; i++){
		scanf("%d",&id_nave);
		n = Nave(id_nave);
		preparacao->empilha(n);
	}
	int operacao;
	while(scanf("%d", &operacao) != EOF) {
		operacao_pedida(operacao, preparacao, combate, avariada);
	}
	delete preparacao;
	delete combate;
	delete avariada;
	return 0;
}
