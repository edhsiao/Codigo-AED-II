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

int quickSort_particao(TItem *A, int p, int r)
{
    TItem pivo,aux;
    int i,j;
    pivo = A[r];
    i = p - 1;
    j = p;
    do
    {
        if(A[j].Chave < pivo.Chave)
        {
            i = i+1;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    j++;
    }
    while (j <= r-1);
    aux = A[i+1];
        A[i+1] = A[r];
        A[r] = aux;
        return i+1;
}

void quickSort_ordena(TItem *A, int p, int r)
{
    int x;
    if ( p < r)
    {
        x = quickSort_particao(A,p,r);
        quickSort_ordena(A,p,x - 1);
        quickSort_ordena(A,x+1,r);
    }
}

void quickSort(TItem *A, int n)
{
    quickSort_ordena(A,0,n-1);
}


int main()
{
    TItem *A;
    int n;

    n = Carrega(&A);
    quickSort_particao(A, 0, n-1);
    Imprime(A, n);
    quickSort(A, n);
    Imprime(A, n);
    Libera(&A);

    return 0;
}
