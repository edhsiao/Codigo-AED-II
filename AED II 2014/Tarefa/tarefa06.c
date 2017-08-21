#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct
{
    TChave Chave;
    /* outros compomentes */
} TItem;

typedef int TIndice;

typedef struct
{
    TItem *Item;
    TIndice n, max;
} TTabela;

/* inicializa uma tabela */
TTabela *Inicializa()
{
    TTabela *T;
    T = (TTabela *) malloc(sizeof(TTabela));
    T->n = 0;
    T->max = 10;
    T->Item = (TItem *) malloc(T->max * sizeof(TItem));
    return T;
}

TIndice Binaria(TTabela *T, TIndice esq, TIndice dir, TChave x)
{
    TIndice meio;

    meio = (esq+dir)/2;

    if((T->Item[meio].Chave !=x) && (esq == dir))
        return -1;
    else if(T->Item[meio].Chave < x)
        return Binaria(T, esq, meio-1, x);
    else if(T->Item[meio].Chave > x)
        return Binaria(T, meio+1, dir, x);
    else return meio;


}

TIndice Pesquisa(TTabela *T, TChave x)
{
    int i, esq, dir;
    if (T->n == 0) return -1;

    esq = 0;
    dir = T->n-1;
    do
    {
        i = (esq + dir) / 2;
        if (x > T->Item[i].Chave) esq = i + 1;
        else dir = i - 1;
    }
    while (x != T->Item[i].Chave && esq <= dir);

    if (x == T->Item[i].Chave) return i;
    else return -1;

}

/* insere um registro na tabela */
void Insere(TTabela *T, TItem x)
{
    if (T->n == T->max)
    {
        T->max *= 2;
        T->Item = (TItem *) realloc(T->Item, T->max * sizeof(TItem));
    }

    T->Item[T->n++] = x; // n eh o tamanho
}

void Carrega(TTabela *T)
{
    int i, n;
    TItem x;

    scanf("%d", &n);
    for (i = 0; i < n ; i++)
    {
        scanf("%d", &x.Chave);
        Insere(T, x);
    }
}

void Libera(TTabela **T)
{
    TTabela *aux;

    aux = *T;
    if (aux != NULL)
    {
        if (aux->Item != NULL) free(aux->Item);
        free(aux);
        (*T) = NULL;
    }
}

void Imprime(TTabela *T)
{
    int i;
    if (T->n > 0)
    {
        printf("%d", T->Item[0].Chave);
        for (i = 1; i < T->n; i++)
            printf(" %d", T->Item[i].Chave);
        printf("\n");
    }
}

int main()
{
    TTabela *T;
    TIndice i;
    TChave x;

    T = Inicializa();
    Carrega(T);
    scanf("%d", &x);
    i = Pesquisa(T, x);
    printf("%d\n", i);
    Libera(&T);

    return 0;
}
