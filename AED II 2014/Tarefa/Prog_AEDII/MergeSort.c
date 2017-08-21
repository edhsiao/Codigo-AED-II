#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem; 

int Carrega(TItem **A)
{
	int i, n;
	
	scanf("%d", &n);
	
	if (n > 0) {
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
	if ((*A) != NULL) {
		free(*A);
		(*A) = NULL;
	}
}

void Imprime(TItem *A, int n)
{
	int i;
	if (n > 0) {
		printf("%d", A[0].Chave);
		for (i = 1; i < n; i++)
			printf(" %d", A[i].Chave);
		printf("\n");
	}
}

void mergeSort_intercala(TItem *A, TItem *B, int p, int q, int r)//Ordena essa parte do vetor A do menor para o maior
{
	int i, j, k;
	
	if(A[q].Chave > A[q+1])
	{
	for(i = p; i<=q; i++)//Copia a primeira metade para o vetor B
		B[i-p] = A[i];
	
	for(j = q + 1; j <= r; j++)//Copia a segunda metade de tras para frente para B
		B[r+q+1-j-p] = A[j];

	i=p;//Percorrera a primeira metade de B
	j=r;//Percorrera a segunda metade de B
		
	for(k=p; k<=r; k++)//Ordena do menor para o maior
		if(B[i-p].Chave <= B[j-p].Chave)
		{
			A[k] = B[i-p];
			i++;
		}
		else
		{
			A[k] = B[j-p];
			j--;
		}
	}
}

void mergeSort_ordena(TItem *A, TItem*B, int p, int r)//Divide para depois passar para a funcao intercalo juntar
{
	int q;

	if (p < r)
	{
		q = (r + p) / 2;
		mergeSort_ordena(A, B, p, q);//Ordena a primeira metade
		mergeSort_ordena(A, B, q+1, r);//Ordena a segunda metade
		mergeSort_intercala(A, B, p, q, r);//Junta as metades ordenadas
	}
}

void mergeSort(TItem *A, int n)//Serve para criar o vetor auxiliar so uma vez ( ¬¬ )
{
	TItem *B;//Vetor auxiliar
	B=(TItem *)malloc(sizeof(TItem)* r - p + 1);	
	mergeSort_ordena(A, B, 0, n - 1);
	free(B);
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
