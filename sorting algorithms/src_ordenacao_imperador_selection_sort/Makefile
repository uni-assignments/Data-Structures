CC=g++ 
CFLAGS=-Wall -Wextra
EXEC=./tp2 
TMPOUT=tp2.testresult

$(EXEC): main.cpp civilizacao.o
	$(CC) $(CFLAGS) main.cpp civilizacao.o -o $(EXEC)

civilizacao.o: civilizacao.cpp 
	$(CC) $(CFLAGS) -c civilizacao.cpp -o civilizacao.o

test: $(EXEC)
	@bash ./run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf civilizacao.o
	rm -rf tp2.testresult
	rm -rf tp2
