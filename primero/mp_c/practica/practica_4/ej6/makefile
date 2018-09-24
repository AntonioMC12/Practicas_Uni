#Fichero: makefile
#Este es el makefile del ejercicio 6 de la practica 4.
#Este makefile contruye una biblioteca "libMemoria.a",con "reservarMemoria.c" y "liberaMemoria.c".
#Construye el ejecutable "crucigrama.x" a partir de la biblioteca y los ficheros objeto.
#Permite eliminar los ficheros objeto generados.

libMemoria.a: reservaMemoria.o liberaMemoria.o
	ar -rsv libMemoria.a reservaMemoria.o liberaMemoria.o

crucigrama: libMemoria.a main.o ficheros.o crucigrama.o
	gcc -o crucigrama main.o ficheros.o crucigrama.o libMemoria.a

liberaMemoria.o: liberaMemoria.c
	gcc -c liberaMemoria.c

main.o: main.c
	gcc -c main.c

resevaMemoria.o: reservaMemoria.c
	gcc -c reservaMemoria.c

ficheros.o: ficheros.c
	gcc -c ficheros.c

crucigrama.o: crucigrama.c
	gcc -c crucigrama.c

clean:
	@echo Borrando ficheros.o ...
	@rm *.o
