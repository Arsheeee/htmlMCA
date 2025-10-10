#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    // struct node* prevlink;
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
  newnode->nextlink=firstnode;
   firstnode->nextlink=head;
  
}

void insertatend(struct node* head)
{
struct node* lastnode=(struct node*)malloc(sizeof(struct node));
{
  int value;
  
  printf("enter the last value : ");
  scanf("%d",&value);
  
  struct node* temp=head;

  while(temp->nextlink!=head)
  {
    temp=temp->nextlink;
   
  }
  
  temp->nextlink=lastnode;
  lastnode->nextlink=head;
  
  lastnode->data=value;
  
}

}

void insetrandom( struct node * head)
{
   struct node* randomnode=(struct node*)malloc(sizeof(struct node));

   int pos;
   int value;

   printf("enter the position  to be inserted randomly : ");
   scanf("%d",&pos);
   printf("enter the value to be inserted randomly : ");
   scanf("%d",&value);

   struct node* prev=head;
   struct node* temp=head->nextlink;

   int count=1;

   while (temp->nextlink!=head)
   {
     temp=temp->nextlink;
     prev=prev->nextlink;
     count++;

     if(count==pos)
     {
      
       prev->nextlink=randomnode;
       randomnode->nextlink=temp;
      

       randomnode->data=value;
     }
   }
   


}

void deleteatbeg(struct node* head)
{
  struct node* temp=head;

  temp->nextlink=temp->nextlink->nextlink;

  printf("Insertion is done , Now the first node will be deleted . \n");
}

void deleteatend(struct node* head)
{
   struct node* temp=head;

   while(temp->nextlink->nextlink!=head)
   {
    temp=temp->nextlink;
  }
  temp->nextlink=head;
   printf("Now , the last node will be deleted below .");
   printf("\n");
}

void deleteatrandom (struct node* head)
{
  int pos;
  struct node*temp=head->nextlink;
  struct node*prev=head;
  printf("Enter the position to be deleted : ");
  scanf("%d",&pos);

  
  int count=1;

  while(temp!=head)
  {
    temp=temp->nextlink;
    prev=prev->nextlink;
    count++;
    
    if(count==pos)
    {
      prev->nextlink=temp->nextlink;
      
    }
  }
  printf("Now , the deletion is completed.");
  printf("\n");
}



void display( struct node* head)
{
  struct node* temp= head->nextlink;
  
  while(temp!=head)
  {
    printf("[%d]-><-",temp->data);
    temp=temp->nextlink;
  }
  
  printf("\n");
  
}

int main()
{
  
  
  struct node* head=(struct node*)malloc(sizeof(struct node));
  
  struct node* firstnode=(struct node*)malloc(sizeof(struct node));

  int value;
  printf("enter the second value : ");
  scanf("%d",&value);
  
  head->nextlink=firstnode;
  
  // firstnode->nextlink=NULL;
  firstnode->data=value;

  // head->prevlink=NULL;

  // insert(head,firstnode);
  // display(head);

  insertatbeg(head,firstnode);
  display(head);

  insertatend(head);
  display(head);

  insetrandom(head);
  display(head);

  insetrandom(head);
  display(head);

  insetrandom(head);
  display(head);

  deleteatbeg(head);
  display(head);

  deleteatend(head);
  display(head);

  deleteatrandom(head);
  display(head);
   
  return 1;

}


