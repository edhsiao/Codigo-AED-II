
#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem;

typedef struct SNo *TArvBin;

typedef struct SNo {
	TItem Item;
	TArvBin Esq, Dir;
} TNo;

TArvBin Inicializa()
{
	return NULL;
}

TArvBin Pesquisa (TArvBin No, TChave x)
{
    if (No == NULL)
        return NULL;
    else if (No->Item.Chave > x)
        return Pesquisa(No->Esq,x);
    else if (No->Item.Chave < x)
        return Pesquisa(No->Dir,x);
    else
        return No;
}


int Insere(TArvBin *pNo, TItem x)
{
	if (*pNo == NULL)
    {
        *pNo = (TArvBin) malloc (sizeof(TNo));
        (*pNo)->Item = x;
        (*pNo)->Esq = NULL;
        (*pNo)->Dir = NULL;
        return 1;
    }
    else if (x.Chave < (*pNo)->Item.Chave)
        return Insere(&(*pNo)->Esq,x);
    else if (x.Chave > (*pNo)->Item.Chave)
        return Insere(&(*pNo)->Dir,x);
        return 0;
}

void Sucessor (TArvBin *q,TArvBin *r)
{
    if((*r)->Esq != NULL)
        Sucessor(q,&(*r)->Esq);
    else
    {
        (*q)->Item = (*r)->Item;
        *q = *r;
        *r = (*r)->Dir;
    }
}

int Remove(TArvBin *p, TChave x)
{
    TArvBin q;

	if (*p == NULL)
        return 0 ;

    else if (x < (*p)->Item.Chave)
        return Remove(&(*p)->Esq,x);
    else if (x > (*p)->Item.Chave)
        return Remove (&(*p)->Dir,x);
    else
        {
            q = *p;
            if (q->Esq == NULL)
                *p = q->Dir;
            else if (q->Dir == NULL)
                *p = q->Esq;
            else
                Sucessor(&q, q->Dir);
            free(q);
            return 1;
        }
}

void Carrega(TArvBin *pNo)
{
	int i, n;
	TItem x;

	scanf("%d", &n);
	for (i = 0; i < n ; i++) {
		scanf("%d", &x.Chave);
		Insere(pNo, x);
	}
}

void Libera(TArvBin *pNo)
{
	TArvBin No;

	No = *pNo;
	if (No != NULL) {
		Libera(&No->Esq);
		Libera(&No->Dir);
		free(No);
		(*pNo) = NULL;
	}
}

void Imprime(TArvBin No)
{
	if (No != NULL) {
		printf("(C%d", No->Item.Chave);
		Imprime(No->Esq);
		Imprime(No->Dir);
		printf(")");
	}
	else
		printf("()");
}

int main()
{
	TArvBin Raiz;
	TItem x;

	Raiz = Inicializa();
	Carrega(&Raiz);
	scanf("%d", &x.Chave);
	if (Pesquisa(Raiz, x.Chave) == NULL)
		Insere(&Raiz, x);
	else
		Remove(&Raiz, x.Chave);
	Imprime(Raiz);
	Libera(&Raiz);

	return 0;
}
