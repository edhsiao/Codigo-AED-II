#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct
{
    TChave Chave;
    /* outros compomentes */
} TItem;

int Carrega(TItem **A)
{
    int i, n;

    scanf("%d", &n);

    if (n > 0)
    {
        (*A) = (TItem *) malloc(n * sizeof(TItem));
        for (i = 0; i < n ; i++)
            scanf("%d", &(*A)[i].Chave);
    }
    else
        (*A) = NULL;

    return n;
}

void Libera(TItem **A)
{
    if ((*A) != NULL)
    {
        free(*A);
        (*A) = NULL;
    }
}

void Imprime(TItem *A, int n)
{
    int i;
    if (n > 0)
    {
        printf("%d", A[0].Chave);
        for (i = 1; i < n; i++)
            printf(" %d", A[i].Chave);
        printf("\n");
    }
}

void mergeSort_intercala(TItem *v, int esq, int meio, int dir)
{
    int i, j, k;
    int a_tam = meio-esq+1;
    int b_tam = dir-meio;
    TItem *a = (TItem*) malloc(sizeof(TItem) * a_tam);
    TItem *b = (TItem*) malloc(sizeof(TItem) * b_tam);

    for (i = 0; i < a_tam; i++)
        a[i] = v[i+esq];
    for (i = 0; i < b_tam; i++)
        b[i] = v[i+meio+1];

    for (i = 0, j = 0, k = esq; k <= dir; k++)
    {
        if (i == a_tam)
            v[k] = b[j++];
        else
        if (j == b_tam)
            v[k] = a[i++];
        else
        if (a[i].Chave < b[j].Chave)
            v[k] = a[i++];
        else
            v[k] = b[j++];
    }
    free(a);
    free(b);
}

void mergeSort_ordena(TItem *v, int esq, int dir)
{
    if (esq < dir)
    {
        int meio = (esq + dir) / 2;
        mergeSort_ordena(v, esq, meio);
        mergeSort_ordena(v, meio+1, dir);
        mergeSort_intercala(v, esq, meio, dir);
    }
}



void mergeSort(TItem *v, int n)
{
    mergeSort_ordena(v, 0, n-1);
}




int main()
{
    TItem *A;
    int n;

    n = Carrega(&A);
    mergeSort(A, n);
    Imprime(A, n);
    Libera(&A);

    return 0;
}
