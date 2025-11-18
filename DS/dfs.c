#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int Adjarr[MAX][MAX];
int visited[MAX];
int n;

void dfs(int crnode)
{
    printf("%d ", crnode);
    visited[crnode]=1;

   for(int i=0;i<n;i++)
   {

       if(Adjarr[crnode][i]==1 && !visited[i])
       {
         dfs(i);
       }
   }
}

int main()
{
    int vertex;
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


    dfs(startnode);

}