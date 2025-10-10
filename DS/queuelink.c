#include<stdio.h>
#include<conio.h>

struct node{
    int data;
    struct node* nextlink;
};
struct queue{

    struct node* rear;
    struct node* front;
};

void emptyque(struct queue* que)
{
   que->rear=NULL;
   que->front=NULL;
}

void display(struct node* que)
{

}

void enque(struct queue* que,int value)
{
   int value;

   struct node* newnode = (struct node*)malloc(sizeof(struct node));

   if(rea)

   
   

}

void deque(struct node* que)
{
    struct node* temp=firstnode->nextlink;
    struct node* tempprev=firstnode;
    while (temp->nextlink!=NULL)
    {
        temp=temp->nextlink;
          
    }

    tempprev->nextlink=NULL;
    front=tempprev;
    printf("dequeue succesfull");

    
}

int main()
{
    struct queue que;
    emptyque(&que);

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
            enque(&que,value);
            break;

           case 2:
            deque(&que);
            break;

          case 3:
           display(&que);
           break;

          case 4:
           while(que.front!=NULL)
           {
            deque(&que);
            break;
           }
        }
    }
    


}