#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include<stdlib.h> 
#include "bubblesortvetor.h"

int main ()
{
    long int n ;
    printf("insira a quantidade de elementos do array:\n");
    scanf("%ld",&n);
    int tamanho = n, i;
    long int *arr;
    long int *arr2;
    arr = malloc(sizeof(long int)*n);
    arr2 = malloc(sizeof(long int)*n);
    


    for(i = 0; i<n; i++)
    {
        arr[i] = rand()*rand()%n;
        arr2[i] = arr[i];
    }
	
	
    /*comeco como a lista encadeada vazia.*/
    struct no*comeco = NULL;

    //criar lista encadeada pelo array arr[]
    for(i=0; i<tamanho; i++)
    {
        inserirnocomecoEnc(&comeco, arr[i]);
    }


    //Print lista antes de ordenar.
    printf("\n Lista antes de ordenar.");
    printListEnc(comeco);

    clock_t t;
    t = clock();
    
	criaarquivo (arr2,n);
    //ordenando a lista encadeada
    bubbleSortEnc(comeco);

    //Print lista depois de ordenar.
	  printf("\n Lista depois de ordenar encadeada.");
    printListEnc(comeco);
    t =clock() -t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    printf("\n\n Tempo gasto: %f ms.", time_taken);

    clock_t t2;
    t2 = clock();

    //ordenando a lista encadeada
    bubbleSortSeq(arr2, n);
	criaarquivoordenado (arr2, n );
    //Print lista depois de ordenar.
	  printf("\n Lista depois de ordenar sequencial.\n");
    printVetorSeq(arr2, n);
    
    t2 =clock() -t2;
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC;
    printf("\n\n Tempo gasto: %f ms.", time_taken2);
	free(arr);
	free(arr2);
    getchar();
    return 0;
 
}
