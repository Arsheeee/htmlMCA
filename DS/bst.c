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
  if(root!=NULL)
  {
    printf("%d",root->key);
    preorder(root->leftlink);
    preorder(root->rightlink);
  }
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
   if(root!=NULL)
   {
     postorder(root->leftlink);
     postorder(root->rightlink);
     printf("%d",root->key);
   }
}

void delete(struct node *root, int dltvalue)
{
   struct node *temp=root,*parent,*succ;

   while(temp!=NULL && temp->key==dltvalue)
   {
    parent=temp;
    temp=(dltvalue < temp->key) ? temp->leftlink : temp->rightlink;

   }
   if(temp==NULL )
   {
     printf("value not found %d",dltvalue);

   }
   
   //case 1 if o child else 1 child
   if(temp->leftlink == NULL && temp->rightlink==NULL)
   {
     struct node *child = (temp->leftlink) ? temp->leftlink : temp->rightlink;
     if(parent==NULL)
     {
       root=child;
     }

   }


}


int main()
{
    int choice;
    int value;
    int dltvalue;
    while(1)
    {
     printf("\n 1.Insert 2.Preorder 3.Inorder 4.Postorder 5.delete 6.Exit \n");
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
         printf("Enter the element to delete : ");
         scrinf("%d",&dltvalue);
         delete(root,dltvalue);

         case 6:
         printf("Exiting...\n");
         exit(0);

        default:
          printf("invalid choice");
     }
    }
    
}