CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp1 # nome do executavel que sera gerado, nao troque
TMPOUT=tp1.testresult

$(EXEC): main.cpp pilha.o lista.o fila.o
	$(CC) $(CFLAGS) main.cpp pilha.o lista.o fila.o -o $(EXEC)

pilha.o: cpps/pilha_encadeada.cpp 
	$(CC) $(CFLAGS) -c cpps/pilha_encadeada.cpp -o pilha.o

lista.o: cpps/lista_encadeada.cpp 
	$(CC) $(CFLAGS) -c cpps/lista_encadeada.cpp -o lista.o

fila.o: cpps/fila_encadeada.cpp 
	$(CC) $(CFLAGS) -c cpps/fila_encadeada.cpp -o fila.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf fila.o
	rm -rf lista.o
	rm -rf pilha.o
	rm -rf tp1
