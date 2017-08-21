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

TArvBin Carrega()
{
	char c;
	TArvBin No;
	scanf("%c", &c);
	if (c == '(') {
		scanf("%c", &c);
		if (c == 'C') {
			No = (TArvBin) malloc(sizeof(TNo));
			scanf("%d", &No->Item.Chave);
			No->Esq = Carrega();
			No->Dir = Carrega();
			scanf("%c", &c);
		}
		else if (c == ')')
			No = NULL;
	}
	return No;
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

int Altura(TArvBin No)
{
	int hEsq, hDir;

	if (No == NULL)
		return -1;

	hEsq = Altura(No->Esq);
	hDir = Altura(No->Dir);
	if(hEsq > hDir)
		return hEsq + 1;
	else
		return hDir + 1;
}

int FB(TArvBin No)
{
	if(No == NULL)
		return 0;

	return Altura(No->Esq) - Altura(No->Dir);
}

int ArvoreAVL(TArvBin No)
{
	int fb;

	if(No == NULL)
		return 1;

	if(!ArvoreAVL(No->Esq))
		return 0;
	else if(!ArvoreAVL(No->Dir))
		return 0;

	fb = FB(No);
	if((fb > 1) || (fb < -1))
		return 0;
	else
		return 1;
}

void LL(TArvBin *pA)
{
	TArvBin pB;

	pB = (*pA)->Esq;
	(*pA)->Esq = pB->Dir;
	pB->Dir = *pA;
	*pA = pB;
}


void RR(TArvBin *pA)
{
	TArvBin pB;

	pB = (*pA)->Dir;
	(*pA)->Dir = pB->Esq;
	pB->Esq = *pA;
	*pA = pB;
}

void LR(TArvBin *pA)
{
	TArvBin pB, pC;

	pB = (*pA)->Esq;
	pC = pB->Dir;
	pB->Dir = pC->Esq;
	pC->Esq = pB;
	(*pA)->Esq = pC->Dir;
	pC->Dir = *pA;
	*pA = pC;
}

void RL(TArvBin *pA)
{
	TArvBin pB, pC;

	pB = (*pA)->Dir;
	pC = pB->Esq;
	pB->Esq = pC->Dir;
	pC->Dir = pB;
	(*pA)->Dir = pC->Esq;
	pC->Esq = *pA;
	*pA = pC;
}

int BalancaEsquerda(TArvBin *pNo)
{
	int fbe = FB((*pNo)->Esq);

	if (fbe > 0)
	{
		LL(pNo);
		return 1;
	}

	else if(fbe < 0)
	{
		LR(pNo);
		return 1;
	}

	return 0;
}

int BalancaDireita(TArvBin *pNo)
{
	int fbd = FB((*pNo)->Dir);

	if (fbd < 0)
	{
		RR(pNo);
		return 1;
	}

	else if(fbd > 0)
	{
		RL(pNo);
		return 1;
	}

	return 0;
}

int BalancaNo(TArvBin *pNo)
{
	int fb = FB(*pNo);

	if(fb > 1)
		return BalancaEsquerda(pNo);
	else if (fb < -1)
		return BalancaDireita(pNo);
	else
		return 0;

	return 0;
}

void BalancaArvore(TArvBin *pNo)
{
	if (*pNo != NULL) {
		BalancaArvore(&(*pNo)->Esq);
		BalancaArvore(&(*pNo)->Dir);
		BalancaNo(pNo);
	}
}

int main()
{
	TArvBin Raiz;
	TItem x;

	Raiz = Carrega();
	printf("%d\n", Altura(Raiz));
	if (!ArvoreAVL(Raiz)) {
		BalancaArvore(&Raiz);
		printf("%d\n", Altura(Raiz));
		Imprime(Raiz);
	}
	Libera(&Raiz);

	return 0;
}

