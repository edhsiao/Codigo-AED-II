#include <stdio.h>
#include <stdlib.h>

void shell_sort(long vet[], long tam)
{
    long  i , j , valor;
    long  gap = 1;
    do
    {
        gap = 3*gap+1;
    }
    while(gap < tam);
    do
    {
        gap /= 3;
        for(i = gap; i < tam; i++)
        {
            valor = vet[i];
            j = i - gap;
            while (j >= 0 && valor < vet[j])
            {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = valor;
        }
    }
    while ( gap > 1);
}

int main()
{
    long *vetor, num;
    long  i=0, j;

    while(scanf("%ld ",&num)==1)
    {

        if(i!=0)

            vetor=(long*)realloc(vetor,(i+1)*sizeof(long));

        else

            vetor=(long*)malloc(sizeof(long));

        vetor[i] = num;

        i++;

    }

    shell_sort(vetor,i);

    for (j=0; j<i; j++)
    {
        printf("%ld\n", vetor[j]);
    }
}

