#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void gerar(long vet[],long tam)
{
    int i;
    for (i=0; i<tam; i++)
        vet[i]=rand()%4000000;
}

void imprime(long vet[], long tam)
{
    int i;
    for (i=0; i<tam; i++)
        printf("%ld ",vet[i]);
}

int main ()
{
    long tam=10;
    long *vetor;
    srand(time(NULL));
    vetor=(long*)malloc(tam*sizeof(long));
    if(!vetor)
    {
        printf("ERRO AO ALOCAR !");
        return(0);
    }
    gerar(vetor, tam);
    imprime(vetor,tam);

}
