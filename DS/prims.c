#include <stdio.h>

#define INF 9999
#define MAX 20

prims(){

    while (edges < n - 1) {
        int min = INF;
        int x = -1, y = -1;
        
        // find the smallest edge connecting selected → unselected
        for (int i = 0; i < n; i++) {
            if (selected[i]) { 
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        
        printf("%d -- %d  (cost = %d)\n", x, y, graph[x][y]);
        totalCost += graph[x][y];
        selected[y] = 1;
        edges++;
    }
}


printf("\nTotal Cost of MST = %d\n", totalCost);

return 0;

int main() {
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


    prims(startnode,n);
}