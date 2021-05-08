all:TGD

TGD: main.o TGD.o
	gcc -o TGD main.o TGD.o

main.o: main.c TGD.h
	gcc -c main.c -Wall

TGD.o: TGD.c TGD.h
	gcc -c TGD.c -Wall

clean:
	rm TGD main.o TGD.o