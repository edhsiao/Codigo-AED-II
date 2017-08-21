#include <stdio.h>
#include <stdlib.h>

#define M 2
#define MM (2 * M)

typedef int TChave;

typedef struct
{
    TChave Chave;
    /* outros compomentes */
} TItem;

typedef int TIndice;

typedef struct SNo *TArvoreB;

typedef struct SNo
{
    TItem Item[MM];
    TArvoreB Pagina[MM + 1];
    TIndice n;
} TNo;

int EhInterno(TArvoreB No)
{
    return (No != NULL) && (No->Pagina[0] != NULL);
}

int EhExterno(TArvoreB No)
{
    return (No != NULL) && (No->Pagina[0] == NULL);
}

TArvoreB Inicializa()
{
    return NULL;
}

TArvoreB Pesquisa(TArvoreB Raiz, TChave x)
{
   int i;

  i = 1;
  while (i < Raiz->n && x > Raiz->Item[i - 1].Chave)
    i++;
  if (x == Raiz->Item[i - 1].Chave)
  {
    x = Raiz->Item[i - 1].Chave;
    return;
  }
  if (x < Raiz->Item[i - 1].Chave)
    Pesquisa(x, Raiz->Pagina[i - 1]);
  else
    Pesquisa(x, Raiz->Pagina[i]);
}

void Insere(TArvoreB *pRaiz, TItem x)
{

}

void Carrega(TArvoreB *pNo)
{
    int i, n;
    TItem x;

    scanf("%d", &n);
    for (i = 0; i < n ; i++)
    {
        scanf("%d", &x.Chave);
        Insere(pNo, x);
    }
}

void Libera(TArvoreB *pNo)
{
    TArvoreB No;
    TIndice i;

    No = *pNo;
    if (No != NULL)
    {
        for (i = 0; i <= No->n; i++)
            Libera(&No->Pagina[i]);
        free(No);
        (*pNo) = NULL;
    }
}

void Imprime(TArvoreB No)
{
    TIndice i;

    if (No != NULL)
    {
        printf("(");
        for (i = 0; i < No->n; i++)
        {
            Imprime(No->Pagina[i]);
            printf("C%d", No->Item[i].Chave);
        }
        Imprime(No->Pagina[No->n]);
        printf(")");
    }
    else
        printf("()");
}

int main()
{
    TArvoreB Raiz;
    TItem x;

    Raiz = Inicializa();
    Carrega(&Raiz);
    scanf("%d", &x.Chave);
    if (Pesquisa(Raiz, x.Chave) == NULL)
        Insere(&Raiz, x);
    Imprime(Raiz);
    Libera(&Raiz);

    return 0;
}
