#include<stdio.h>
#define MAX 100

int visited[MAX];
int front=-1,rear=-1;
int queue[MAX];
int Adjarr[MAX][MAX];

void enqueue(int node)
{
   if(rear==MAX-1)
   {
    printf(" Queue Overflow");
   }
   else{
    if(front==-1)
    {
        front=0;     
    }
    rear++;
    queue[rear]=node;
   }
}

 int dequeue()
 {
    if(front == -1 || front > rear)
    {
        return -1; // qeueu become empty
    }
    else{
        return queue[front++];
    }
 }

 void bfstraverse(int startnode ,int n)
 {
   int pvalue,node;

   for(int i=0; i<n; i++) //making every value not visited
   {
    visited[i]=0;
   }

   //starting node
   printf("starting the traversal from %d",startnode);

   //set astartnode
   enqueue(startnode);
   visited[0]=1;

   //reapeat the checking and traversal process until the queue is empty
   while(pvalue=dequeue() != -1)
   {
     printf("%d",pvalue); //printing current value(vertex)

     for(int i=0; i<n; i++)
     {
        if(Adjarr[pvalue][i]==1 && )
     }
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

    printf("Enter the node to start your traversal(0---%d)",n-1);
    scanf("%d",startnode);


    bfstraverse(startnode,n);

}