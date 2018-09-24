#Fichero: makefil7.mak
#Makefile con macros predefinidas

destinos: main.x clean

main.x: main.o vector.o orden.o
	gcc -o $@ $^ 

main.o: main.c
	gcc -c main.c
vector.o: vector.c
	gcc -c vector.c
orden.o: orden.c
	gcc -c orden.c
clean:
	rm *.o
