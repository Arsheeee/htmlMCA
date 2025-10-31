#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node {
    struct node *leftlink;
    struct node *rightlink;

    int key;
};

struct node *root=NULL;

struct node *createnode(int value)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));

    newnode->key=value;
    newnode->leftlink=NULL;
    newnode->rightlink=NULL;

    return newnode;
}

void insert(int value)
{
   struct node  *newnodee=createnode(value);
   struct node *temp=root;
   struct node *parent=temp;

   if(root==NULL)
   {
    root=newnodee;
   }
   else{
    while(temp!=NULL)
   {
     parent=temp;

     if(temp->key > value)
     {
        temp=temp->leftlink;
     }
     else{
        temp=temp->rightlink;
     }
   }

   if(parent->key > value)
   {
    parent->leftlink=newnodee;
   }
   else{
    parent->rightlink=newnodee;
   }
   }
}

void preorder(struct node * root)
{
  
}


void inorder(struct node *root)
{
  if(root!=NULL)
  {
    inorder(root->leftlink);
    printf("%d",root->key);
    inorder(root->rightlink);
  }
}

void postorder(struct node *root)
{

}


int main()
{
    int choice;
    int value;
    while(1)
    {
     printf("\n 1.Insert 2.Preorder 3.Inorder 4.Postorder 5.Exit \n");
     printf("enter your choice : ");
     scanf("%d",&choice);

     switch(choice)
     {
        case 1:
         printf("enter the value to be inserted : ");
         scanf("%d",&value);
         insert(value);
         break;

         case 2:
         printf("Preorder traversal \n");
         preorder(root);
         break;

         case 3:
         printf("Inorder traversal \n");
         inorder(root);
         break;

         case 4:
         printf("Postorder traversal \n");
         postorder(root);
         break;

         case 5:
         printf("Exiting...\n");
         exit(0);

        default:
          printf("invalid choice");
     }
    }
    
}