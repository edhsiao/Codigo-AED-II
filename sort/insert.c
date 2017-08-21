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
void insert_sort(long vet[], int tam)
{
        int i, j, troca;

        for(i = 1; i < tam; i++){

                j = i;

                while((j != 0) && (vet[j] < vet[j - 1])) {

                        troca = vet[j];
                        vet[j] = vet[j - 1];
                        vet[j - 1] = troca;
                        j--;
                }
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
    insert_sort(vetor,tam);
    imprime(vetor,tam);
    free(vetor);
    tempo_exe = (clock()-tempo_inicio)/(double)CLOCKS_PER_SEC;
    printf("\nTempo de execucao= %f s\n",tempo_exe);
}
