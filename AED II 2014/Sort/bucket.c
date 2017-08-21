#include <stdio.h>
#include <stdlib.h>
void dec(float *vet,float tam)
{int i;
    for(i=0;i<tam;i++)
    while (vet[i]>1)
        vet[i]=vet[i]/10;
        for (i=0; i<tam; i++)
    {
        printf("%f\n", vet[i]);
    }
}
void bucket_sort(float vet[], long tam)
{
    long  i, j;
    long  bucket[tam];
    for(i=0; i < tam; i++)
    {
        bucket[i] = 0;
    }
    for(i=0; i < tam; i++)
    {
        (bucket[vet[i]])++;
    }
    for(i=0,j=0; i < tam; i++)
    {
        for(; bucket[i]>0; (bucket[i])--)
        {
            vet[j++] = i;
        }
    }
}

int main()
{
    float *vetor, num;
    long i=0, j;

    while(scanf("%e ",&num)==1)
    {

        if(i!=0)

            vetor=(float*)realloc(vetor,(i+1)*sizeof(float));

        else

            vetor=(float*)malloc(sizeof(float));

        vetor[i] = num;

        i++;

    }

    dec(vetor,i);

   bucket_sort(vetor,i);


    for (j=0; j<i; j++)
    {
        printf("%f\n", vetor[j]);
    }
}

