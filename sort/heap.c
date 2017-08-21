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

    long tam=100;
    long *vetor;
    clock_t tempo_inicio;
    tempo_inicio=clock();
    double tempo_exe;
    vetor=(long*)malloc(tam*sizeof(long));
    srand(time(NULL));

    gerar(vetor,tam);
    printf("\nTamanho do Vetor = %d",tam);
    printf("Gerando vetor");
    printf("\n.\n.\n.\n\n");
    if(!vetor){
            printf("ERRO AO ALOCAR !");
            return(0);
        }
    tempo_exe = (clock() - tempo_inicio) / (double)CLOCKS_PER_SEC;
    printf("\nTempo de execucao= %f s\n\n",tempo_exe);
    printf("Ordenando vetor...\n\n");
    heap_sort(vetor,tam);
    imprime(vetor,tam);
    free(vetor);
    tempo_exe = (clock()-tempo_inicio)/(double)CLOCKS_PER_SEC;
    printf("\nTempo de execucao= %f s\n",tempo_exe);
}
