#Fichero: makefil4.mak
#Incorpora una regla sin lista de dependencias

saludo.exe: saludo.o
	@echo Creando saludo.exe
	@gcc -o saludo.exe saludo.o 


#Esta regla especifica un destino que no es
#un ejecutable
saludo.o: saludo.c
	@echo Creando saludo.o solamente
	@gcc -c saludo.c


#Esta regla especifica un destino sin lista de
#dependencias
clean:
	@echo Borrando ficheros.o ...
	@rm -f *.o
