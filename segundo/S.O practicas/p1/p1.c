//p1.c
//It's a tutorial program to explain practice 1 of SO.

#include <sys/ipc.h>
#include <time.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>

#define CHILDREN 3
#define ITER 5
#define ok 10

int main(){


  //creamos las variables que vayamos a usar.
  int localizador,shmid,status, i;
  int* v;
  struct shmid_ds buf;

  //primero creamos una clave para trabajar con ella
  key_t key;
  key = ftok("p1.c",1);

  //reservamos memoria ( memoria compartida)

  if ((shmid = shmget(key, sizeof(int)*100, IPC_CREAT | 0777)) == -1)
  exit(1);

  //Ahora usamos un puntero que nos direccione a la memoria compartida

  v = (int *) shmat(shmid,  NULL, 0);

  //inicializamos la semilla del srand
  srand(time(NULL));

  //rellenamos aleatoriamente el vector.
  for (int i = 0; i < 100; i++) {
    v[i]=rand()%11;
  }

  //Hacemos hijos y hacemos sus funciones secuencialmente

if(!fork()){
  /* Proceso hijo
    Pedir un índice del vector y un valor entero por teclado y almacenar en la posición
    correspondiente el valor leído. Esta operación se ha de repetir 10 veces.
  */
  int indice,valor;
  for(int i = 0 ; i < 10 ;i++){
    printf("Child 1 iniciado\n");
    printf("Introduzca un indice para colocarse en el vector\n");
    scanf("%d\n",&indice);
    printf("Indice introducido correctamente\n");
    printf("Introduzca un valor para asignar\n");
    scanf("%d\n",&valor );
    printf("Valor introducido correctamente\n");
      v[indice]=valor;
}

printf("PID Child 1 = %d\n",getpid());
exit(0);


}
if(!fork()){
  /* proceso hijos
     Cambiar aleatoriamente un elemento del vector y bloquearse durante 1 segundo. Esta
     operación se ha de repetir 100 veces.
  */
printf("Child 2 iniciado\n");
printf("Cambiando aleatoriamente un elemento del vector...\n");
  for(int i = 0 ; i < 100 ; i++){

  v[rand()%100]=rand()%11;

  sleep(1);
  }

printf("PID child 2 = %d\n",getpid());
exit(0);

}

if(!fork()){
  /* proceso hijos
    Sumar todos los elementos del vector, mostrar la suma por pantalla y luego
    bloquearse durante 30 segundos. Esta operación se ha de repetir 5 veces.
  */
printf("Child 3 iniciado\n");
int suma;
  for(int i = 0; i < 5 ; i++){
    suma = 0;
    for(int i = 0; i < 100 ; i++){
      suma = v[i] + suma;
    }
    sleep(30);
    printf("La suma del vector es: %d\n",suma);
  }
printf("PID child 3 = %d\n",getpid());
exit(0);
}

  //Ahora hacemos que espere
  for( i = 0 ; i < CHILDREN ; i++){
    pid_t pid = wait(&status);
    printf("\nChild %d finished with status %d\n", pid, WEXITSTATUS(status));
  }

    //Liberamos memoria
    shmdt(v);

    //Eliminamos
    shmctl(shmid, IPC_RMID, &buf);

    return 0;
}
