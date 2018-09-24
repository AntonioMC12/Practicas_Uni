/* -------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 8: Inclusion condicional de código

  Ejercicio: Ejemplo básico
             programa principal
 --------------------------------------------------------*/
#include <stdio.h>
#define MAX_ALUMNOS 30
#include "consultas_sin.h"
#include "ES_sin.h"

int menu();

/********************************************************************/
/*                       FUNCION PRINCIPAL                          */
/********************************************************************/
int main()
{
   stAlumno Alumnos[MAX_ALUMNOS];
   int tope;
   int salir=0;
   struct alumno* aux;
   
   
   tope=0; //Inicializacion muy importante
   introducirDatos(Alumnos, &tope);
  	      	   
   do
   {
     switch(menu())
     {
     	case 0:salir=1;
     	       break;
     	case 1:introducirDatos(Alumnos, &tope);
     	       break;         	
     	case 2:mostrarAlumnos(Alumnos, tope);
     	       break;
     	case 3:mostrarSuperanNota(Alumnos, tope, calculaMedia(Alumnos, tope));
     	       break;       
     }
   
   }while(!salir);

   return 0;
}


/********************************************************************/
/*
   Nombre: menu.
   Tipo: int.
   Objetivo: Muestra un menu y selecciona una opción.	     
   Parametros de entrada: Ninguno.
   Precondiciones: Ninguna.
   Devuelve:
      - int: la opción seleccionada
*/
/*******************************************************************/
int menu()
{
   int opcion;
   do
   {
     printf("\n-----------------");
     printf("\n\nMENU PRINCIPAL");
     printf("\n-----------------");
     printf("\n\t1. Introducir nuevos alumnos");
     printf("\n\t2. Listar todos los alumnos");
     printf("\n\t3. Mostrar nota media y los alumnos que la superan");    
     printf("\n\t0. Salir\n");
     scanf("%d", &opcion);
   }while((opcion<0)||(opcion>3));	
   return(opcion);
}

