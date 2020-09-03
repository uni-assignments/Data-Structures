#include <cstdio> // em C substituir por #include <stdio.h>
#include "./headers/pilha/pilha_encadeada.hpp"
#include "./headers/lista/lista_encadeada.hpp"

void operacao_pedida(int operacao, PilhaEncadeada *p, ListaEncadeada *l){
	Nave n;
	switch (operacao){
		case 0:
			n = p->desempilha();
			l->insere_final(n);
			printf("nave %d em combate\n", n.get_identificador());
			break;
		case -1:
			break;
		case -2:
			break;
		case -3:
			break;
		default
			break;
	}
}


int main() {
	int num_frotas, id_nave;
	PilhaEncadeada *p = new PilhaEncadeada();
	ListaEncadeada *l = new ListaEncadeada();
	Nave n;

	scanf("%d",&num_frotas);

	for(int i=0; i < num_frotas; i++){
		scanf("%d",&id_nave);
		n = Nave(id_nave);
		p->empilha(n);
	}
	int operacao;
	while(scanf("%d", &operacao) != EOF) {
		operacao_pedida(operacao, p, l);
	}
	delete p;
	return 0;
	
}
