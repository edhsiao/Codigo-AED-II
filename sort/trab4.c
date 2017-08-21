#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100000
#define M 100000

//void ordena_quick(char* vet, int esq, int dir){
//    if(esq < dir){
//        int esquerda = esq;
//        int direita = dir;
//        char x = *vet;
//        while(esquerda < direita){
//            while(esquerda < direita && *(vet+direita) > x)
//                direita--;
//            if(esquerda < direita)
//                *(vet+(esquerda++)) = *(vet+direita);
//            while(esquerda < direita && *(vet+esquerda) < x)
//                esquerda++;
//            if(esquerda < direita)
//                *(vet+(direita--)) = *(vet+esquerda);
//        }
//        *(str+esquerda) = x;
//        ordena_quick(vet, esq, esquerda-1);
//        ordena_quick(vet, direita+1, dir);
//    }
//}

//int pesquisa(char *chave, char *vetor[])
//{
//    int i;
//    for(i= 0; i < N; i++)
//        if(!strcmp(chave, vetor))
//        return (i);
//    return(-1);
//}

int main()
{
    long num;
    char* str = (char*)malloc(sizeof(char)*100);
    char **vetor1,**vetor2,nome[15];
    int i,j;

   printf("\nDigite a quantidade de número de nomes:\n");
   scanf("%ld",&num);
   if((num>N)||(num<=0))
   {
      printf("\nQuantidade Inválida!!\nDigite a quantidade de número de nomes novamente:\n");
   scanf("%ld",&num);
   }



    while(scanf("%s",&nome)==1)
    {

        if(i!=0){

            vetor1=(char*)realloc(vetor1,(i+1)*sizeof(char));
            vetor1[i]=(char*)malloc(15*sizeof(char));
            }

        else{

            vetor1=(char*)malloc(sizeof(char));
            vetor1[i]=(char*)malloc(15*sizeof(char));
        }
        strcpy(vetor1[i],nome);
        i++;
    }

    orderna_quick(vetor,0,strlen()-1);

//    vetor=(long*)malloc(i*sizeof(long));
//    if(!vetor)
//    {
//        printf("ERRO AO ALOCAR !");
//        exit(1);
//    }




    while((scanf("%ld",&vetor[i]))==1)
    {
        i++;

    }




    for (j=0; j<i; j++)
    {

        printf("%ld\n", vetor[j]);
    }


    return 0;
}
