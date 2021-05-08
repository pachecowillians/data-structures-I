all: fila

fila: main.o LDE.o fila.o
	gcc -o fila main.o LDE.o fila.o

main.o: main.c fila.h
	gcc -c main.c -Wall

LDE.o: LDE.c LDE.h
	gcc -c LDE.c -Wall

fila.o: fila.c fila.h
	gcc -c fila.c -Wall
	
clean:
	rm main.o LDE.o fila.o fila