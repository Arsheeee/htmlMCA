#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int Adjarr[MAX][MAX];
int ind[MAX];
int visited[MAX];


void topo(int n)
{
    int count=0;
    for (int i = 0; i <n; i++)
    {
        visited[i]=0;
        ind[i]=0;
    }
    

 for(int i=0;i<n;i++)  //finding indegree
 {
    for(int j=0;j<n;j++)
    {
        ind[i]+= Adjarr[j][i];
         
    }
 }


    for(int k=0;k<n;k++)  //perform topologycal sort
    {
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0 && !visited[i])
            {
                visited[i]=1;
                printf("%d",i);
                count++;

                //reduse indegree
                for(int j=0;j<n;j++)
                {
                    if(Adjarr[i][j]== 1)
                    {
                        ind[j]--;
                    }
                }
            }
        }
    }

    if(count !=n)
    {
        printf("Cycle ditected topological sorting is not possible");
        }
 }

 


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


    topo(n);
}