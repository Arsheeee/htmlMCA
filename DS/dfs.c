#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int visited[MAX];
int top=-1;
int stack[MAX];
int Adjarr[MAX][MAX];

void push(int node)
{
   if(top==MAX-1)
   {
    printf(" Stack Overflow");
   }
   else{
    if(top==-1)
    {
        top=0;     
    }
    top++;
    stack[top]=node;
   }
}

 int pop()
 {
    if(top == -1)
    {
        return -1; // qeueu become empty
    }
    else{
        return stack[top--];
    }
 }

 void dfstraverse(int startnode ,int n)
 {
   int curr,node;

   for(int i=0; i<n; i++) //making every value not visited
   {
    visited[i]=0;
   }

   //starting node
   printf("starting the traversal from %d",startnode);

   //set astartnode
   push(startnode);
   visited[startnode]=1;

   //reapeat the checking and traversal process until the stack is empty
   while( top != -1)
   {
    int flag=0;

     for(int i=0; i<n; i++)
     {
        if(Adjarr[curr][i]==1 && !visited[i])
        {
            push(i);
            printf("%d\t",i);
            visited[i]=1;
            curr=i;
            flag=1;
            break;
            

        }
     }
     if(flag==0)

     {
        pop();
        if(top !=-1){
        curr=stack[top];
        }
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
    scanf("%d",&startnode);


    dfstraverse(startnode,n);

}