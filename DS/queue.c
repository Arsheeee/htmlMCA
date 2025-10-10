#include<stdio.h>
#define max 5

int front=-1;
int rear=-1;
int ptr;

int queue[max];

// int isempty()
// {
//     return(front ==-1 && rear==-1);
// }
// int isfull()
// {
//    return(front==max-1 && rear==max-1 ) ;
// }

void enqueue( int value)
{
    if(rear==max-1 )
    {
        printf("que is full");
    }
    else
    {
        front=0;
        rear++;
        queue[rear]=value;
        printf("%d is added",value);
    }
}
void dequeue(){
    if(front==-1)
    {
       printf("queue is empty");

    }
    else{
        printf("%d is deleted",queue[front]);
        front++;
    }
}
void display()
{
    if (front==-1) {
        printf("Queue is empty!\n");
    }
    else{

        for(int i=front;i<=rear;i++)
        {
            printf("%d \n",queue[i]);
        }
    }

}
int main()
{

    enqueue(10);
     enqueue(20);
      enqueue(30);

      dequeue();
      display();

}

