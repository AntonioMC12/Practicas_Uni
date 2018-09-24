//p1.c
//It's a tutorial program to explain practice 1 of SO.

#include <sys/ipc.h>
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
  int localizador,shmid, i;
  int *contador;
  void adder(int);
  struct shmid_ds buf;

  //primero creamos una clave para trabajar con ella
  key_t key;
  key = ftok("shmemory.c",1);

  //reservamos memoria para el puntero ( memoria compartida)

  if ((shmid = shmget(key, sizeof(int), IPC_CREAT | 0777)) == -1)
  exit(1);

  //Ahora usamos un puntero que nos direccione a la memoria compartida

  contador = (int *) shmat(shmid,  NULL, 0);

  //Ahora podemos usar el puntero *contador tal como cualquier otro.
  //Lo inicializamos a 0.
  counter = 0;

  //llamamaos la funcion para hacer los hijos
  for (i = 1 ; i < CHILDREN ; i++){
    if (!fork()) {
      contador(i);
      exit(0);
    }
  }

  //Ahora hacemos que espere
  for( i = 0 ; i < CHILDREN ; i++){
    pid_t pid = wait(&status);
    printf("\nChild %d finished with status %d\n", pid, WEXITSTATUS(status));
  }

  //Imprimimos por pantalla el resultado
  printf("contador = %ls\n",*contador);


    //Liberamos memoria
    shmdt(contador);

    //Eliminamos
    shmctl(shmid, IPC_RMID, &buf);

    return 0;
}


void contador(int localizador){
  //Funcion para sumar numero al proceso.
  int num = 1,i ,num2;
  int *contador;

  //primero creamos una clave para trabajar con ella
  key_t key;
  key = ftok("shmemory.c",1);

  //reservamos memoria para el puntero ( memoria compartida)

  if ((shmid = shmget(key, sizeof(int), IPC_CREAT | 0777)) == -1)
  exit(1);

  //Ahora usamos un puntero que nos direccione a la memoria compartida

  int *contador = (int *) shmat(shmid,  NULL, 0);

  for (i = 0, i < ITER ; i++){
    num2 = *contador;
    printf("Proceso %d -> %lf \n",localizador,*contador );
    *contador += num;
    *contador = num2;
  }
    printf("Proceso %d -> %lf \n",localizador, *contador);
    shmdt(counter);
    exit(ok)

}
