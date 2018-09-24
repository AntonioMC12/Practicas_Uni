#include <stdio.h>

struct punto
{
  float x; //Coordenada x del punto
  float y; //Coordenada y del punto	
};

void funcion1(struct punto p);
void funcion2(struct punto* p);

void main()
{
  //Definicion de variable de tipo punto
  struct punto punto1, punto2, *ptrpunto;
  
  //OPERADOR . Lectura de la estructura.
  printf("\n1.OPERADOR .");
  printf("\nCoordenada X: ");
  scanf("%f", &punto1.x);
  printf("\nCoordenada Y: ");
  scanf("%f", &punto1.y);  
  
  printf("\npunto1.x: %f  punto1.y: %f", punto1.x, punto1.y);
  
  //OPERADOR ->
  ptrpunto = &punto2;
  printf("\n2.OPERADOR ->");
  printf("\nCoordenada X: ");
  scanf("%f", &ptrpunto->x); //ptrpunto->x equivale a (*ptrpunto).x
  printf("\nCoordenada Y: ");
  scanf("%f", &ptrpunto->y);   
  printf("\nptrpunto->x: %f  ptrpunto->y: %f", ptrpunto->x, ptrpunto->y);
  
  //ASIGNACION
  punto2 = punto1;
  printf("\n3.ASIGNACION");
  printf("\npunto2.x: %f  punto2.y: %f", punto2.x, punto2.y); 
  
  //PASO POR VALOR
  funcion1(punto1);  
  printf("\n4.PASO POR VALOR");
  printf("\npunto1.x: %f  punto1.y: %f", punto1.x, punto1.y);
  
  //PASO POR REFERENCIA
  funcion2(&punto1);  
  printf("\n5.PASO POR REFERENCIA");
  printf("\npunto1.x: %f  punto1.y: %f", punto1.x, punto1.y); 
}

/*La estructura se recibe en una variable local de tipo
  "struct punto" llamada p
*/
void funcion1(struct punto p)
{
  p.x = -3;
  p.y=-3;
}

/*La estructura se recibe en una variable local de tipo
  puntero a"struct punto" llamada p. Cualquier modificacion
  de "*p" (mejor "p->") hace que se modifique en realidad
  punto1: PASO POR REFERENCIA
*/
void funcion2(struct punto* p)
{
   p->x=-2; //(*p).x=-2;
   p->y=-2; //(*p).y=-2;
}
