/* -------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 8: Inclusion condicional de código

  Ejercicio: Ejemplo
             programa principal
 --------------------------------------------------------*/

#include "consultas.h"
#include <stdio.h>

/********************************************************************/
/*
   Nombre: calculaMedia.
   Tipo: float.
   Objetivo: Calcula la nota media de un vector de alumnos.	     
   Parametros de entrada:
      - struct alumno Alumnos[]: Vector de alumnos.
      - int tope: El numuero de alumnos del vector
   Precondiciones: Ninguna.
   Devuelve: La nota media del vector de alumnos
*/
/*******************************************************************/
float calculaMedia(stAlumno Alumnos[], int tope)
{
   int i;
   float suma=0.0;
   
   for(i=0; i<tope; i++)
   {
     suma = suma + Alumnos[i].nota;   	
   } 	  
   return(suma/tope); 	
}
/********************************************************************/
/*
   Nombre: mostrarSuperanNota.
   Tipo: void.
   Objetivo: Muestra los alumnos que superan una determinada nota.	     
   Parametros de entrada:
      - struct alumno Alumnos[]: Vector de alumnos.
      - int tope: El numuero de alumnos del vector
      - float nota: la nota
   Precondiciones: Ninguna.
   Devuelve: void.
*/
/*******************************************************************/
void mostrarSuperanNota(stAlumno Alumnos[], int tope, float nota)
{
   int i;
     
   printf("\n\nMODULO DE LISTADO DE ALUMNOS QUE SUPERAN LA NOTA: %f", nota);	
   printf("\n---------------------------------");
      
   for(i=0; i<tope; i++)
   {
     if(Alumnos[i].nota>=nota)
     {
       printf("\nAlumno: %d", i);
       printf("\n\tDNI: %s", Alumnos[i].DNI);
       printf("\n\tNombre del alumno: %s", Alumnos[i].nombre);
       printf("\n\tNota del alumno: %f", Alumnos[i].nota);   	
     }  
   } 		
}
