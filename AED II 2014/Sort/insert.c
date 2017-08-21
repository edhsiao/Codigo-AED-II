#include <stdio.h>
#include <stdlib.h>

void insert_sort(long vet[], int tam)
{
    long  i, j, troca;

    for(i = 1; i < tam; i++)
    {

        j = i;

        while((j != 0) && (vet[j] < vet[j - 1]))
        {

            troca = vet[j];
            vet[j] = vet[j - 1];
            vet[j - 1] = troca;
            j--;
        }
    }
}

int  main()
{
    long *vetor, num;
    long i=0, j;

    while(scanf("%ld ",&num)==1)
    {

        if(i!=0)

            vetor=(long*)realloc(vetor,(i+1)*sizeof(long));

        else

            vetor=(long*)malloc(sizeof(long));

        vetor[i] = num;

        i++;

    }

    insert_sort(vetor,i);


    for (j=0; j<i; j++)
    {
        printf("%ld\n", vetor[j]);
    }
}

