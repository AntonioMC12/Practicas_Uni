/* -------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 8: Inclusion condicional de código

  Ejercicio: Ejemplo
 --------------------------------------------------------*/
#define MAX_NOMBRE 20
typedef struct alumno{
   char nombre[MAX_NOMBRE];
   char DNI[10];
   float nota;
} stAlumno;

float calculaMedia(stAlumno Alumnos[], int tope);
void mostrarSuperanNota(stAlumno Alumnos[], int tope, float nota);

