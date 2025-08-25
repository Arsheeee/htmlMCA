#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node* link;
};


void insertatend( struct node** headd,int value)
{
   struct node* new_node=(struct node*)malloc(sizeof(struct node));
   
   new_node->data=value;
   new_node->link=NULL;
   
   
   struct node* temp=*headd;
   
   while(temp->link!=NULL)
   {
       temp=temp->link;
    }
    
    temp->link=new_node;


   } 

   void insertionatbegin(struct node** headdd, int value)
   {
     struct node *front_node=(struct node*)malloc(sizeof(struct node));

     struct node *temp=*headdd;

     front_node->link=*headdd;
     *headdd=front_node;

     front_node->data=value;
   }



void display(struct node* head)
{
    // printf("%d",head->data);

    struct node*tempp=head;

    while (tempp!=NULL)
    {
        printf("[%d]\n",tempp->data);
        tempp=tempp->link;
    }
    printf("\n");
    
} 

void insertrandom(struct node** head,int value)
{
    struct node* rnode=(struct node*)malloc(sizeof(struct node));

   struct node* temp=*head;

   while(temp!=NULL)
   {
       if(temp->data==5)
       {
           rnode->link=temp->link;
           temp->link=rnode;
           
           rnode->data=value;
        //    printf("success");
        }
        // else{
        //     printf("failed");
            
        // }
        temp=temp->link;

   }
}

void deleteatend(struct node** head)
{
   struct node* temp=*head;
   struct node* temp2=*head;

   while(temp->link!=NULL)
   {
       printf("first loop");
       temp=temp->link;            //sking one node at begining

       if(())
       {
        
       }
     
   }
}

int main()
{
    
    struct node* head=NULL;
    
    head=(struct node*)malloc(sizeof(struct node));

    
    head->data=10;
    head->link=NULL;

    insertatend(&head,20);
    display(head);

    insertionatbegin(&head,5);
    display(head);

    insertrandom(&head,7);
    display(head);

    deleteatend(&head);
    display(head);

    
    return 0;
    
}