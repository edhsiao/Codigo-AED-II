#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar(long vet[],int tam)
{
    int i;
    for (i=0; i<tam; i++)
        vet[i]=rand()%4000000;
}
void imprime_cres(long vet[],int tam)
{
    int i;
    for (i=0; i<tam; i++)
        printf("%ld\n",vet[i]);
}
void imprime_decres(long vet[],int tam)
{
    int i;
    for (i=tam-1; i>=0; i--)
        printf("%ld\n",vet[i]);
}

void select_sort(long vet[], long tam)
{
    int i, j, min, troca;
    for (i = 0; i < (tam-1); i++)
    {
        min = i;
        for (j = (i+1); j < tam; j++)
        {
            if(vet[j] < vet[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            troca = vet[i];
            vet[i] = vet[min];
            vet[min] = troca;
        }
    }
}
void insert_sort(long vet[], int tam)
{
    int i, j, troca;

    for(i = 1; i < tam; i++)
    {

        j = i;

        while((j != 0) && (vet[j] < vet[j - 1]))
        {

            troca = vet[j];
            vet[j] = vet[j - 1];
            vet[j - 1] = troca;
            j--;
        }
    }
}
void shell_sort(long vet[], long tam)
{
    int i , j , valor;
    int gap = 1;
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

    int op;
    long tam;
    long *vetor;
    clock_t tempo_inicio;
    double tempo_exe;
    srand(time(NULL));
    vetor=(long*)malloc(tam*sizeof(long));
    if(!vetor)
    {
        printf("ERRO AO ALOCAR !");
        return(0);
    }
    printf("\nDigite tamanho do vetor a ser gerado: \n\n");
    scanf("%ld",&tam);
    printf("\nTamanho do Vetor = %ld\n",tam);
    printf("\nGerando vetor");
    printf("\n.\n.\n.\n\n");
    gerar(vetor,tam);
    imprime_cres(vetor,tam);



    printf("\nEscolha um tipo de ordennacao:\n\n");
    printf("1 - Select Sort \n");
    printf("2 - Insertion Sort \n");
    printf("3 - Shell Sort \n");
    printf("4 - Heap Sort \n");
    printf("5 - Quick Sort \n");
    printf("6 - Sair\n\n");

    scanf("%d",&op);
    switch(op)
    {
    case(1):
        printf("Ordenando vetor...\n\n");
        tempo_inicio=clock();
        select_sort(vetor,tam);
        imprime_cres(vetor,tam);
        printf("\n");
        imprime_decres(vetor,tam);
        tempo_exe = (clock()-tempo_inicio)/(double)CLOCKS_PER_SEC;
        printf("\nTempo de execucao= %f s\n\n",tempo_exe);
        break;
    case(2):
        printf("Ordenando vetor...\n\n");
        tempo_inicio=clock();
        insert_sort(vetor,tam);
        imprime_cres(vetor,tam);
        printf("\n");
        imprime_decres(vetor,tam);
        tempo_exe = (clock()-tempo_inicio)/(double)CLOCKS_PER_SEC;
        printf("\nTempo de execucao= %f s\n\n",tempo_exe);
        break;
    case (3):
        printf("Ordenando vetor...\n\n");
        tempo_inicio=clock();
        shell_sort(vetor,tam);
        imprime_cres(vetor,tam);
        printf("\n");
        imprime_decres(vetor,tam);
        tempo_exe = (clock()-tempo_inicio)/(double)CLOCKS_PER_SEC;
        printf("\nTempo de execucao= %f s\n\n",tempo_exe);
        break;
    case(4):
        printf("Ordenando vetor...\n\n");
        tempo_inicio=clock();
        heap_sort(vetor,tam);
        imprime_cres(vetor,tam);
        printf("\n");
        imprime_decres(vetor,tam);
        tempo_exe = (clock()-tempo_inicio)/(double)CLOCKS_PER_SEC;
        printf("\nTempo de execucao= %f s\n\n",tempo_exe);
        break;
//    case(5):
//        printf("Ordenando vetor...\n\n");
//        tempo_inicio=clock();
//        quick_sort(vetor,tam);
//        imprime_cres(vetor,tam);
//        printf("\n");
//        imprime_decres(vetor,tam);
//        tempo_exe = (clock()-tempo_inicio)/(double)CLOCKS_PER_SEC;
//        printf("\nTempo de execucao= %f s\n\n",tempo_exe);
//        break;

    case(6):
        return 0;
        break;

    }
    free(vetor);

}

