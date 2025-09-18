#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prevlink;
    struct node* nextlink;
};

// void insert(struct node* head,struct node* firstnode)
// {
//   int value;
//   printf("enter the first node");
//   scanf("%d",&value);
  
//   firstnode->data=value;
// }


void insertatbeg(struct node* head,struct node* firstnode)
{
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  
  int value;
  
  printf("enter the first value : ");
  scanf("%d",&value);
  
  head->nextlink=newnode;
  newnode->data=value;
  newnode->prevlink=head;
  newnode->nextlink=firstnode;
  firstnode->prevlink=newnode;
   firstnode->nextlink=NULL;
  
}

void insertatend(struct node* head)
{
struct node* lastnode=(struct node*)malloc(sizeof(struct node));
{
  int value;
  
  printf("enter the first value : ");
  scanf("%d",&value);
  
  struct node* temp=head;

  while(temp!=NULL)
  {
    temp=temp->nextlink;
    printf("[%d]->",temp->data);
  }

  lastnode->data=value;
  
}

}


insertatend()
{}

void display( struct node* head)
{
  struct node* temp= head->nextlink;
  
  while(temp!=NULL)
  {
    printf("[%d]-><-",temp->data);
    temp=temp->nextlink;
  }
  
  
  
}

int main()
{
  
  
  struct node* head=(struct node*)malloc(sizeof(struct node));
  
  struct node* firstnode=(struct node*)malloc(sizeof(struct node));

  int value;
  printf("enter the initial value : ");
  scanf("%d",&value);
  
  head->nextlink=firstnode;
  firstnode->prevlink=head;
  // firstnode->nextlink=NULL;
  firstnode->data=value;

  // head->prevlink=NULL;

  // insert(head,firstnode);
  // display(head);

  insertatbeg(head,firstnode);
  display(head);
   
  return 1;

}


