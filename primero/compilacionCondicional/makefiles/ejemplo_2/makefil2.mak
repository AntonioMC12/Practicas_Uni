#Fichero: makefil2.mak
#Construye un ejecutable a partir de tres ficheros fuentes


main.x: main.o vector.o orden.o
	gcc -o main.x main.o vector.o orden.o

main.o: main.c vector.h orden.h
	gcc -c main.c

vector.o: vector.c vector.h
	gcc -c vector.c

orden.o: orden.c orden.h
	gcc -c orden.c
