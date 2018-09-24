#Fichero: makefil3.mak
#Construye un ejecutable a partir de tres ficheros fuente, utilizando una libreria


main.x: main.o lib.a
	gcc -o main.x main.o lib.a

main.o: main.c vector.h orden.h
	gcc -c main.c

lib.a: vector.o orden.o
	ar -rsv lib.a vector.o orden.o

vector.o: vector.c vector.h 
	gcc -c vector.c

orden.o: orden.c orden.h
	gcc -c orden.c
