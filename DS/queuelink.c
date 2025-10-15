#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int data;
    struct node* nextlink;
    struct node* prevlink;
};
struct queue{

    struct node* rear;
    struct node* front;
};

void emptyque(struct queue* que)
{
    que->front=NULL;
    que->rear=NULL;
}



void display(struct queue* que)
{
    printf("Queue: ");
    while(que->rear->nextlink!=NULL){
        
        struct node* temp=que->front;
        printf("[%d]->",temp->data);
        temp=temp->nextlink;
    }

    printf("\n");
}

void enque(struct queue* que ,int value)
{
   struct node* newnode = (struct node*)malloc(sizeof(struct node));
   
   newnode->prevlink=NULL;
   newnode->nextlink=NULL;
   newnode->data=value;

   if(que->rear==0)
   {
    que->rear=newnode;
    que->front=newnode;
   }
   else
   {
    que->rear->nextlink=newnode;
    newnode->prevlink=que->rear;
    que->rear=newnode;
   }

   printf("enque Succesfull\n");

}

void deque(struct queue* que)
{
    if(que->front==0)
    {
        printf("nothing to delete");
    }

    else{
        que->front=que->front->nextlink;
        que->front->prevlink=NULL;
    
    }
    printf("dequeue succesfull");

    
}

int main()
{
    struct queue* que=NULL;
    emptyque(que);
    //struct node* front = struct node* rear = NULL;
    

    int choice;
    int value;

    while (1)
    {
        printf("1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");
        printf("enter your choice ");
        scanf("%d",choice);
        
        switch(choice)
        {
           case 1:
            printf("enter the value to enqueue");
            scanf("%d",value);
            enque(que,value);
            break;

           case 2:
            deque(que);
            break;

          case 3:
           display(que);
           break;

          case 4:
           while(que->front!=NULL)
           {
            deque(que);
            free(que);
            printf("Exiting...");
            break;
           }

           default:
           printf("Invalid Choice");
        }
    }
    


}
