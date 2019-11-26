#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define N 10

struct sum_array {
	int * array;
	int initial_position;
	int final_position;
};


void * addArray(void* arguments){
	struct sum_array *args = (struct sum_array *)arguments;
	int* partialResult = calloc(1, sizeof(int));
	if (partialResult == NULL){
		perror("Fallo al reservar memoria para el resultado parcial");
		exit(EXIT_FAILURE);
	}
	for (int vectorPosition = args -> initial_position; vectorPosition < args -> final_position; vectorPosition++){
		*partialResult = *partialResult + *(args -> array+vectorPosition);
	}
	printf("Thread Array : [");
	for( int i = args -> initial_position; i<args -> final_position; i++){
			printf(" %d ",args -> array[i] );
		}
	printf("]\n");
	printf("partialResult: %d \n", *partialResult);
	pthread_exit(partialResult);
}



int main(int argc, char* argv[]){
	if (argc != 2){
		perror("El uso del programa es: ./a.out <numero de hilos>\nEX: ./a.out 2");
		exit(EXIT_FAILURE);
	}
	// Generate array with argv elements to store partial results
	int** partial_array = calloc(atoi(argv[1]), sizeof(int*));
	if ( partial_array == NULL ){
		perror("Fallo al reservar memoria para el vector de enteros");
		exit(EXIT_FAILURE);
	}
	// Generate random array with N elements
	int* original_vector = calloc(N, sizeof(int));
	if ( original_vector == NULL ){
		perror("Fallo al reservar memoria para el vector de enteros");
		exit(EXIT_FAILURE);
	}
	// Fill original array with random values
	srand(time(NULL))	;
	for(int i=0; i<N;i++){
		original_vector[i] = rand()%9;
	}
		for(int i=0; i<N;i++){
			printf("%d ",original_vector[i]);
		}
		printf("\n");

	// Generate N threads, given by argv[1]
	pthread_t* thread_array = calloc(atoi(argv[1]), sizeof(pthread_t));
	if (thread_array == NULL){
		perror("Fallo al reservar memoria para el vector de threads");
		exit(EXIT_FAILURE);
	}
	int parts = N/atoi(argv[1]); // if use 5 parts, each array should own 2 array
	printf("parts: %d\n",parts );

	struct sum_array * args_array = calloc(atoi(argv[1]), sizeof(struct sum_array ));
	if (args_array == NULL){
			perror("Fallo al reservar memoria para el vector de argumentos");
			exit(EXIT_FAILURE);
	}
	// Need to check if all the values is distributed, if not, the las thread will catch
	int distributed_values = 0;

	for (int i = 0; i<atoi(argv[1]); i++){
		distributed_values =   ((( i * parts ) + parts) - (i * parts))  + distributed_values;
		struct  sum_array thread_number_array = {NULL, 0, 0};
		thread_number_array.array = original_vector ;
		thread_number_array.initial_position = i * parts;
		thread_number_array.final_position = ( i * parts ) + parts;
		// if the last struct don't distribute all values, the final limit must be move to end of array
		if ( (i == atoi(argv[1])-1 )  && (distributed_values != 10)){
				thread_number_array.final_position = 10;
		}
		args_array[i] =thread_number_array;

  }

  for (int i = 0; i<atoi(argv[1]); i++){
    pthread_create(&thread_array[i], NULL, (void*) addArray, (void**)&args_array[i]);
  }

	for( int i = 0; i<atoi(argv[1]); i++){
		pthread_join(thread_array[i], (void*) &partial_array[i]);
	}
	int final_result = 0;
	for (int i = 0; i<atoi(argv[1]); i++){
		final_result = *partial_array[i] + final_result;
	}
	printf("Final result: %d\n", final_result);
	free(args_array);
	free(original_vector);
	free(thread_array);
	exit(EXIT_SUCCESS);
}
