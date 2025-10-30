#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node {
    struct node *leftlink;
    struct node *rightlink;

    int key;
};

struct node *root;

void insert(int key)
{
    struct node *temp=root;
    if(root==NULL)
    {
        root=key;
    }

    else{
        if(root>key)
        {
            while(root->leftlink!=NULL)
            {
                r
            }
        }
    }

}


int main()
{
    int choice;
    int key;
    while(1)
    {
     printf("1.Insert 2.display");
     printf("enter your choice");
     scanf("%d",&choice);

     switch(choice)
     {
        case 1:
         printf("enter the value to be inserted : ");
         scanf("%d",&key);
         insert(key);
         break;

         case 2:
         

        default:
          printf("invalid choice");
     }
    }
    
}