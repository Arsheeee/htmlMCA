#include<stdio.h>
#include<conio.h>

#define MAX 100
#define INF 999

int Adjarr[MAX][MAX];
int selected[MAX];
int edge=0;
int totalcost=0;

void prims(int n)
{
    for(int i=0;i<n;i++)
    {
        selected[i]=0;
    }
    selected[0]=1;
    int min=INF;
    int x = -1,y = -1;


    while(edge<n-1)
    {
        //check wether selected
        for(int i=0;i<n;i++)
        {
            if(selected[i])
            {
                for(int j=0;j<n;j++)
                {
                    if(!selected[j] && Adjarr[i][j]<min)
                    {
                        min=Adjarr[i][j];
                        x = i , y= j;
                    }
                }
            }

        }

        printf("%d--%d(cost:%d)",x,y,Adjarr[x][y]);
        totalcost+=min;
        edge++;

    }
    printf("total mincost is : %d",totalcost);

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
            printf("enter the adjecency if no edege enter 0 if edge exist enter the value [%d][%d] : ",i,j);
            scanf("%d",&Adjarr[i][j]);
            if(Adjarr[i][j]==0)
            {
               Adjarr[i][j]=INF;
            }
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


    prims(n);
}