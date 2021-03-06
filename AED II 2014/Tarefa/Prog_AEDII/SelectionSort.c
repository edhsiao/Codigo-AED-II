#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem; 

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

void Metodo(TItem *A, int n)
{
	TItem aux;
	int i, j, menor;

	for(i=0; i<n - 1; i++)
	{
		menor = i;
		for(j= i + 1; j<n; j++)
			if(A[menor].Chave > A[j].Chave)
				menor = j;
		aux = A[i];
		A[i] = A[menor];
		A[menor] = aux;
		Imprime(A,n);
	}
}

int main()
{
	TItem *A;
	int i, n;

	scanf("%d", &n);
	A = (TItem *) malloc(n * sizeof(TItem));
	for (i = 0; i < n ; i++)
		scanf("%d", &A[i].Chave);
		
	Metodo(A, n);
		
	return 0;
}
