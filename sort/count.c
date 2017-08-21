#include <stdio.h>
#include <stdlib.h>

long maiorValor(long *vet,long tam)
{
    long i;
    long m = 0;

    for (i=0;i<tam;i++)
    {
        if (vet[i] > vet[tam])
            tam = i;
    }
    return vet[tam];
}
void count_sort(long *vet, long  tam)
{
    long  i;
    long  B[tam];
    long  maior;
    maior = maiorValor(vet,tam);

    long  C[maior+1];

    for(i=0;i<maior+1;i++)
        C[i] = 0;
        printf("\n");
    for(i=0;i<tam;i++)
        C[vet[i]]++;
    for(i=1;i<=maior+1;i++)
        C[i] += C[i-1];
    for (i=0;i<tam;i++){
        B[C[vet[i]]-1] = vet[i];
        C[vet[i]]--;
    }
    for(i=0;i<tam;i++)
        vet[i] = B[i];
}

int main()
{
    long *vetor, num;
    long i=0, j;

    while(scanf("%ld ",&num)==1)
    {

        if(i!=0){

            vetor=(long*)realloc(vetor,(i+1)*sizeof(long));}

        else{

            vetor=(long*)malloc(sizeof(long));
        }

        vetor[i] = num;

        i++;

    }

    count_sort(vetor,i);


    for (j=0; j<i; j++)
    {
        printf("%ld\n", vetor[j]);
    }
}
