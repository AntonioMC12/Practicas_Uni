#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>

#define N 10

struct suma_array{
    int * array;
    int posicion_inicial;
    int posicion_final;
};

void * sumaArray(void* argumentos){
    
    struct suma_array *args = (struct suma_array *)argumentos;
    int* resultadoP = calloc(1, sizeof(int));
    if(resultadoP == NULL){
        perror("Fallo al reservar memoria para el resultado parcial");
		exit(EXIT_FAILURE);
    }

    for (int posicionVector = args -> posicion_inicial; posicionVector < args -> posicion_final; posicionVector ++){

        *resultadoP = *resultadoP + *(args -> array + posicionVector);

    }

    printf("Vector Parcial : [");

    for(int i = args -> posicion_inicial ; i < args ->posicion_final; i++){
        printf("%d ,", args->array[i]);
    }
    
    printf("]\n");
    printf("Resultado Parcial: %d \n", *resultadoP);
    pthread_exit(resultadoP);
    
}

int main(int argc, char* argv[1]){

    if (argc != 2){
        perror("El programa se usa ejecutando <  ./a.out [nº de hilos]  >");
        exit(EXIT_FAILURE);
    }
    
    /*    Creamos un vector auxiliar para guardar resultados parciales y un vector de trabajo para llevar a 
    cabo la suma.   */

    int** aux_array = calloc(atoi(argv[1]), sizeof(int*));
    //control de errores
    if (aux_array == NULL){
        printf("fallo al reservar memoria");
        exit(EXIT_FAILURE);
    }

    int* ppal_array = calloc(N, sizeof(int));
    //control de errores
    if (ppal_array == NULL){
        printf("fallo al reservar memoria");
        exit(EXIT_FAILURE);
    }

    /* rellenamos el vector con valores pseudoaleatorios */

    srand(time(NULL));
    for(int i = 0; i < N; i++){
        ppal_array[i] = rand()%9;
    }

    pthread_t* thread_array = calloc(atoi(argv[1]), sizeof(pthread_t));
    if (thread_array == NULL){
        printf("fallo al reservar memoria");
        exit(EXIT_FAILURE);
    }

    int partes = N/atoi(argv[1]);

    struct suma_array * vector_args = calloc(atoi(argv[1]), sizeof(struct suma_array));
    if (vector_args == NULL){
        printf("fallo al reservar memoria");
        exit(EXIT_FAILURE);
    }

    int aux=0;

    for(int i = 0; i<atoi(argv[1]); i++){
        
        aux = (((i * partes)+partes) - (i*partes)) + aux;

        struct suma_array hilo_numero_vector = {NULL, 0, 0};
        hilo_numero_vector.array = ppal_array;
        hilo_numero_vector.posicion_inicial = i * partes;
        hilo_numero_vector.posicion_final = (i*partes)+partes;

        if ((i==atoi(argv[1])-1) && (aux != 10)){
            hilo_numero_vector.posicion_final=10;
        }

        vector_args[i] = hilo_numero_vector;
    }

    for(int i = 0; i < atoi(argv[1]); i++){
        pthread_create(&thread_array[i], NULL, (void*) sumaArray, (void**)&vector_args[i]);
    }

    for(int i = 0; i < atoi(argv[1]) ; i++){
        pthread_join(thread_array[i], (void*) &aux_array[i]);

    }

    int resultadoFinal=0;

    for(int i = 0; i < atoi(argv[1]); i++){
        resultadoFinal = *aux_array[i]+resultadoFinal;
    }

    printf("Resultado final: %d \n",resultadoFinal);
    free(vector_args);
    free(ppal_array);
    free(aux_array);
    exit(EXIT_SUCCESS);
}