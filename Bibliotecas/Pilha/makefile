all: pilha

pilha: main.o pilha.o LSE.o
	gcc -o pilha main.o pilha.o LSE.o

main.o: main.c pilha.h
	gcc -c main.c -Wall

pilha.o: pilha.c pilha.h
	gcc -c pilha.c -Wall

LSE.o: LSE.c LSE.h
	gcc -c LSE.c -Wall

clean:
	rm pilha main.o pilha.o LSE.o