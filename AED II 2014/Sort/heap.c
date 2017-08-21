#include <stdio.h>
#include <stdlib.h>

void heap_sort(long vet[], long tam)
{
    int i = tam/2, pai, filho, t;

    for (;;)
    {
        if (i > 0)
        {
            i--;
            t = vet[i];
        }
        else
        {
            tam--;
            if (tam == 0)
                return;
            t = vet[tam];
            vet[tam] = vet[0];
        }

        pai = i;
        filho = i*2 + 1;

        while (filho < tam)
        {
            if ((filho + 1 < tam)  &&  (vet[filho + 1] > vet[filho]))
                filho++;
            if (vet[filho] > t)
            {
                vet[pai] = vet[filho];
                pai = filho;
                filho = pai*2 + 1;
            }
            else
                break;
        }
        vet[pai] = t;
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

    heap_sort(vetor,i);

    for (j=0; j<i; j++)
    {
        printf("%ld\n", vetor[j]);
    }
}

