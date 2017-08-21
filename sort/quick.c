#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar(long vet[],int tam)
{
    int i;
    for (i=0; i<tam; i++)
        vet[i]=rand()%4000000;
}
void imprime(long vet[],int tam)
{
    int i;
    for (i=0; i<tam; i++)
        printf("%ld\n",vet[i]);
}
void troca(long *vet, long i, long j) {
   long t = vet[i];
   vet[i] = vet[j];
   vet[j] = t;
}

int particao(long *vet, long esq,long dir,long pivo)
{
    long pos, i;
    troca(vet, pivo, dir);
    pos = esq;
    for(i = esq; i < dir; i++)
    {
       if (vet[i] < vet[dir])
       {
          troca(vet, i, pos);
          pos++;
       }
     }
     troca(vet, dir, pos);
     return pos;
}

void quick_sort(long *vet, long esq, long dir)
{
    if (esq < dir)
    {
        long pivo = (esq+dir)/2;
        long pos = particao(vet,esq,dir,pivo);
        quick_sort(vet,esq,pos-1);
        quick_sort(vet,pos+1,dir);
    }
}

int main()
{


    long tam=10000;
    long *vetor;
    clock_t tempo_inicio;
    tempo_inicio=clock();
    double tempo_exe;
    vetor=(long*)malloc(tam*sizeof(long));
    srand(time(NULL));


    gerar(vetor,tam);
    printf("Gerando vetor");
    printf("\n.\n.\n.\n\n");

    tempo_exe = (clock()-tempo_inicio)/(double)CLOCKS_PER_SEC;
    printf("\nTempo de execucao= %f s\n\n",tempo_exe);

    printf("Ordenando vetor...\n\n");
    quick_sort(vetor,tam);
    imprime(vetor,tam);
    free(vetor);
    tempo_exe = (clock()-tempo_inicio)/(double)CLOCKS_PER_SEC;
    printf("\nTempo de execucao= %f s\n\n",tempo_exe);

}

