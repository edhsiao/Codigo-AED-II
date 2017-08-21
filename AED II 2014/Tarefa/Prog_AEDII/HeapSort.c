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

void heapRefaz(TItem *A, int esq, int dir)
{ 
	TItem aux;	
	int i, j;
	
	i = esq;
	aux = A[esq];//Recebe o local que nao respeita o heap
	j = i * 2 + 1;//Recebe o filho, por exemplo, o primeiro nó sempre igual a 0, logo o primeiro filho sera 2*0+1=1
	
	while(j <= dir)
	{
		if((j < dir) && (A[j].Chave < A[j+1].Chave))//faz o j apontar para o maior filho
			j++;
		if (aux.Chave >= A[j].Chave)//Caso, o maior filho for menor que o aux acaba o while e o aux fica como pai dele
			break;
		A[i] = A[j];//Caso, ainda nao tenha achado o lugar do aux
		i = j;
		j = i * 2 + 1;
	}
	A[i] = aux;//Coloca o aux no local que respeite o heap (o pai sempre maior que os filhos, caso eles existam)
}

void heapConstroi(TItem *A, int n)//O pai sempre tem que ser maior que os filhos, caso eles existam!!!!
{ 
	int esq;
	esq = (n/2) -1;
	while(esq >= 0)//Começa de traz para frente(obs.: transforma um vetor em um vetor que satisfaz as condicoes de heap)
	{
		heapRefaz(A, esq, n-1);//Vai verificando se o vetor forma uma subavore que satisfaz a condicao de heap ate chegar na arvore
		esq--;//Vai decrementando
	}
}

void heapSort(TItem *A, int n)//Ordena o heap de forma crescente
{ 
	TItem aux;
	int m;

	heapConstroi(A,n);//Constroi primeiramente o heap

	m = n-1;

	while(m > 0)
	{
		aux = A[m];//Troca de lugar o maior com o menor, para o maior ficar por ultimo
		A[m] = A[0];
		A[0] = aux;
		m--;
		heapRefaz(A,0,m);//Agora ordena o heap sem contar com o maior
	}
}

int main()
{
	TItem *A;
	int n;

	n = Carrega(&A);
	heapRefaz(A, 0, n-1);
	Imprime(A, n);
	heapConstroi(A, n);
	Imprime(A, n);	
	heapSort(A, n);
	Imprime(A, n);
	Libera(&A);
		
	return 0;
}
