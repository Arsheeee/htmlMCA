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
    printf("%d ",root->key);
    preorder(root->leftlink);
    preorder(root->rightlink);
  }
}



void inorder(struct node *root)
{
  if(root!=NULL)
  {
    inorder(root->leftlink);
    printf("%d ",root->key);
    inorder(root->rightlink);
  }
}

void postorder(struct node *root)
{
   if(root!=NULL)
   {
     postorder(root->leftlink);
     postorder(root->rightlink);
     printf("%d ",root->key);
   }
}

struct node* findsucc(struct node* succ) //finding inorder succseccor >> here dlt nodes right subtrees min value is the inorder succseror
{
  struct node *temp=succ;
  while(temp!=NULL && temp->leftlink!=NULL)
  {
    temp=temp->leftlink;
  }
  return temp;

}

struct node* delete(struct node *root, int dltvalue)
{
 if(root==NULL)
 {
  return root;
 }
 //traverse
 if(dltvalue < root->key)
 {
    root->leftlink=delete(root->leftlink,dltvalue);
 }
 else if (dltvalue > root->key)
 {
  root->rightlink=delete(root->rightlink,dltvalue);
 }
 //case 1 : no child
 else{
     if(root->leftlink==NULL && root->rightlink==NULL)
     {
      free(root);
      return NULL;
     }

     //case 2 : one child (node have a right child)
     else if (root->leftlink==NULL && root->rightlink!=NULL)
     {
      struct node * temp=root->rightlink;
      free(root);
      return temp;

     }
     // one child (node have a left child)
     else if(root->rightlink==NULL && root->leftlink!=NULL)
     {
      struct node* temp=root->leftlink;
      free(root);
      return temp;
     }
     //case 3 : Two childeren
     else
     {
       struct node* temp=findsucc(root->rightlink);
       root->key=temp->key;
       root->rightlink=delete(root->rightlink,temp->key);
     }
 }
 return root;
 
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
         printf("\n");
         break;

         case 3:
         printf("Inorder traversal \n");
         inorder(root);
         printf("\n");
         break;

         case 4:
         printf("Postorder traversal \n");
         postorder(root);
         printf("\n");
         break;

         case 5:
         printf("Enter the element to delete : ");
         scanf("%d",&dltvalue);
         root=delete(root,dltvalue);
         break;

         case 6:
         printf("Exiting...\n");
         exit(0);

        default:
          printf("invalid choice");
     }
    }
    
}