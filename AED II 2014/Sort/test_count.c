#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,k = 0, A[15];
    printf("-----------------------------------------------------------\n");
    printf("----------------------Made by C code champ-----------------\n");
    printf("-----------------------------------------------------------\n\n");
    printf("\t\tCOUNTING SORT ALGORITHM\n\n\n\n");
    printf("Enter the number of input : ");
    scanf("%d",&n);
    printf("\n\nEnter the elements to be sorted :\n");
    for ( i = 1; i <= n; i++)
    {
         scanf("%d",&A[i]);
         if(A[i] > k)
         {
            k = A[i];
            printf("\nmaior =%d\n",k);
         }
    }
}
