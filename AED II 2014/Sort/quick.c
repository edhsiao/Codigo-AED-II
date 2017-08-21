#include <stdio.h>
#include <stdlib.h>

void troca(long  vet[], long  i, long  j) {
   long  t = vet[i];
   vet[i] = vet[j];
   vet[j] = t;
}

long  part(long  vet[], long  esq,long  dir,long  pivo)
{
    long  pos, i;
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

void quick_sort(long  vet[], long  esq, long  dir)
{
    if (esq < dir)
    {
        long  pivo = (esq+dir)/2;
        long  pos = part(vet,esq,dir,pivo);
        quick_sort(vet,esq,pos-1);
        quick_sort(vet,pos+1,dir);
    }
}

int main()
{
    long *vetor, num;
    int  i=0, j;

    while(scanf("%ld ",&num)==1)
    {

        if(i!=0)

            vetor=(long*)realloc(vetor,(i+1)*sizeof(long));

        else

            vetor=(long*)malloc(sizeof(long));

        vetor[i] = num;

        i++;

    }

    quick_sort(vetor,0,i);

    for (j=0; j<i; j++)
    {
        printf("%ld\n", vetor[j]);
    }
}

