#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    long i=0, j;
    printf("\nEntrando While\n");

    while(scanf("%ld",&num)!=0)
    {

        printf("\nComeco while\n");
        printf("\ni = %ld\n",i);
        if (i>0){
        printf("\nrealocando vetor\n");
        vetor=(long*)realloc(vetor,i*sizeof(long));}
        else{
        printf("\nalocando vetor\n");
        vetor=(long*)malloc(sizeof(long));
        }

        printf("\n Fim alocacao\n");


        vetor[i] = num;
        printf("\ni = %ld\n",i);
        printf("Impriminto vetor [i] = %ld\n", vetor[i]);
        printf("Todo vetor:\n");
        for (j=0; j<=i; j++)
    {

        printf("vetor[%ld]=%ld \n",j, vetor[j]);
    }
        i++;
        printf("\nFim while\n");

    }

    printf("\nSaiu While\n");
    printf("%ld\n", i);

    select_sort(vetor,i);

    printf("\nSaiu sort\n");
    printf("%ld\n", i);

    for (j=0; j<i; j++)
    {
        printf("%ld\n", i);
        printf("%ld\n", vetor[j]);
    }
}

