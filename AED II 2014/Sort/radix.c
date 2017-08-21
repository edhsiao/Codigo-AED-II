#include <stdio.h>
#include <stdlib.h>


void radix_sort(long vet[], long tam)
{
    long  i, b[tam], maior = vet[0], exp = 1;
    for (i = 0; i < tam; i++)
    {
        if (vet[i] > maior)
            maior = vet[i];
    }

    while (maior / exp > 0)
    {
        long  box[10] = {0};
        for (i = 0; i < tam; i++)
            box[vet[i] / exp % 10]++;
        for (i = 1; i < 10; i++)
            box[i] += box[i - 1];
        for (i = tam - 1; i >= 0; i--)
            b[--box[vet[i] / exp % 10]] = vet[i];
        for (i = 0; i < tam; i++)
            vet[i] = b[i];
        exp *= 10;
    }
}

int main()
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

    radix_sort(vetor,i);

    for (j=0; j<i; j++)
    {
        printf("%ld\n", vetor[j]);
    }

}
