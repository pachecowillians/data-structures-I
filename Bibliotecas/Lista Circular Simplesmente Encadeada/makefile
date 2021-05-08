all: LCSE

LCSE: main.o LCSE.o
	gcc -o LCSE main.o LCSE.o

main.o: main.c LCSE.h
	gcc -c main.c -Wall

LCSE.o: LCSE.c LCSE.h
	gcc -c LCSE.c -Wall

clean:
	rm LCSE main.o LCSE.o
