OBJECTS = main.o crucigrama.o ficheros.o  liberaMemoria.o reservaMemoria.o
CFLAGS = -c -g -ansi -Wall

main.exe: $(OBJECTS)
	gcc $(OBJECTS) -o main.exe

main.o: main.c ficheros.h memoria.h crucigrama.h
	gcc $(CFLAGS) main.c

crucigrama.o: crucigrama.c crucigrama.h
	gcc $(CFLAGS) crucigrama.c

ficheros.o: ficheros.c ficheros.h
	gcc $(CFLAGS) ficheros.c

liberaMemoria.o:  liberaMemoria.c memoria.h
	gcc $(CFLAGS) liberaMemoria.c

reservaMemoria.o: reservaMemoria.c memoria.h
	gcc $(CFLAGS) reservaMemoria.c
