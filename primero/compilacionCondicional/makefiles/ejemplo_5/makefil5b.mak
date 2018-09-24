#Fichero: makefil5b.mak
#Construye dos ejecutable sin destino simbolico

saludo.exe: saludo.c
	@echo Creando saludo.exe
	gcc -o saludo.exe saludo.c 

saludo2.exe: saludo2.c
	@echo Creando saludo2.exe
	gcc -o saludo2.exe saludo2.c 

clean:
	@echo Borrando ficheros.o ...
	@rm -f *.o
