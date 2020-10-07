CC=g++ 
CFLAGS=-Wall -Wextra
EXEC=./heapsort
TMPOUT=heapsort.testresult

$(EXEC): main.cpp civilizacao.o
	$(CC) $(CFLAGS) main.cpp civilizacao.o -o $(EXEC)

civilizacao.o: ../headers/civilizacao.cpp 
	$(CC) $(CFLAGS) -c ../headers/civilizacao.cpp -o civilizacao.o

test: $(EXEC)
	@bash ../run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf civilizacao.o
	rm -rf heapsort.testresult
	rm -rf heapsort
