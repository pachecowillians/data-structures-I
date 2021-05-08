all: LCDE

LCDE: main.o LCDE.o
	gcc -o LCDE main.o LCDE.o

main.o: main.c LCDE.h
	gcc -c main.c -Wall

LCDE.o: LCDE.c LCDE.h
	gcc -c LCDE.c -Wall

clean:
	rm LCDE main.o LCDE.o
