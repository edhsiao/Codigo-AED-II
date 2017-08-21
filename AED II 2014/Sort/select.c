#include <stdio.h>
#include <stdlib.h>

void select_sort(long vet[], long tam)
{
    int i, j, min, troca;
    for (i = 0; i < (tam-1); i++)
    {
        min = i;
        for (j = (i+1); j < tam; j++)
        {
            if(vet[j] < vet[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            troca = vet[i];
            vet[i] = vet[min];
            vet[min] = troca;
        }
    }
}

int main()
{
    long *vetor, num;
    int i=0, j;

    while(scanf("%ld ",&num)==1)
    {

        if(i!=0)

            vetor=(long*)realloc(vetor,(i+1)*sizeof(long));

        else

            vetor=(long*)malloc(sizeof(long));

        vetor[i] = num;

        i++;

    }

    select_sort(vetor,i);


    for (j=0; j<i; j++)
    {
        printf("%ld\n", vetor[j]);
    }
}

