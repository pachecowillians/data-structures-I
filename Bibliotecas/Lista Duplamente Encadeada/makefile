all: LDE

LDE: main.o LDE.o
	gcc -o LDE main.o LDE.o

main.o: main.c LDE.h
	gcc -c main.c -Wall

LDE.o: LDE.c LDE.h
	gcc -c LDE.c -Wall

clean:
	rm main.o LDE.o LDE