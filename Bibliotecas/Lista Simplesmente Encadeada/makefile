all:LSE

LSE: main.o LSE.o
	gcc -o LSE main.o LSE.o

main.o: main.c LSE.h
	gcc -c main.c -Wall

LSE.o: LSE.c LSE.h
	gcc -c LSE.c -Wall

clean:
	rm LSE main.o LSE.o