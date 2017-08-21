#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100000
int main()
{
    long num;
    char* nome = (char*)malloc(sizeof(char)*15);
    char **vetor1,**vetor2;

    int i,j;

   printf("\nDigite a quantidade de número de nomes:\n");
   scanf("%ld",&num);


   for (i=0;i<num;i++)
   {
       scanf("%s",nome);
       if(i!=0){
            vetor1=(char**)realloc(vetor1,(i+1)*sizeof(char*));

            vetor1[i]=(char*)malloc(strlen(nome)*sizeof(char));
            }
        else{

            vetor1=(char**)malloc(sizeof(char*));

            vetor1[i]=(char*)malloc(strlen(nome)*sizeof(char));
        }
        strcpy(vetor1[i],nome);
        printf("--%s\n",nome);
        printf("%ld\n",strlen(nome));
    }
}
