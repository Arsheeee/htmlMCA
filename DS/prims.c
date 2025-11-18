
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int Adjarr[MAX][MAX];



int main()
{
    int vertex,n;
    int startnode;
    

    printf("enter the no of elemenents : ");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("enter the adjecency value on the position Adjarr[%d][%d] : ",i,j);
            scanf("%d",&Adjarr[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d\t",Adjarr[i][j]);
            
        }
        printf("\n");
    }

    printf("Enter the node to start your traversal(0---%d)",n-1);
    scanf("%d",&startnode);


    bfstraverse(startnode,n);

}
