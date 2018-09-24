/* -------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 8 Inclusion condicional de código

  Ejercicio: Ejemplo
             programa principal
 --------------------------------------------------------*/
#include "ES_sin.h"
#include <stdio.h>

/********************************************************************/
/*
   Nombre: introducirDatos.
   Tipo: void.
   Objetivo: Rellena un vector de alumnos:
      - struct alumno Alumnos[]: Vector de alumnos.
      - int* tope: El numero de alumnos del vector
      - float nota: la nota
   Precondiciones: *tope puede ser mayor de 0. En este caso los alumnos
        se introducirán a partir de la posición tope.
   Devuelve: void.
*/
/*******************************************************************/
void introducirDatos(stAlumno Alumnos[], int* tope)
{
   int salir=0;
   printf("\n\nMODULO DE INTRODUCCION DE DATOS");	
   printf("\n---------------------------------");
   
   while(!salir)
   {
     printf("\nIntroduzca el DNI del alumno ('S' para salir): ");
     scanf("%s", Alumnos[*tope].DNI);
     if(strcmp("S", Alumnos[*tope].DNI)!=0)
     {
       printf("\n\tIntroduzca el nombre del alumno: ");
       scanf("%s", Alumnos[*tope].nombre);
       printf("\n\tIntroduzca la nota del alumno: ");
       scanf("%f", &(Alumnos[*tope].nota));
       (*tope)++;
     } 
     else
     {salir=1;}
   }   
}
/********************************************************************/
/*
   Nombre: mostrarAlumnos.
   Tipo: void.
   Objetivo: Muestra un vector de alumnos:
      - struct alumno Alumnos[]: Vector de alumnos.
      - int tope: El numero de alumnos del vector      
   Precondiciones: ninguna.
   Devuelve: void.
*/
/*******************************************************************/
void mostrarAlumnos(stAlumno Alumnos[], int tope)
{
   int i;
   
   printf("\n\nMODULO DE LISTADO DE ALUMNOS");	
   printf("\n---------------------------------");
   for(i=0; i<tope; i++)
   {
     printf("\nAlumno: %d", i);
     printf("\n\tDNI: %s", Alumnos[i].DNI);
     printf("\n\tNombre del alumno: %s", Alumnos[i].nombre);
     printf("\n\tNota del alumno: %f", Alumnos[i].nota);   	
   } 		
}
