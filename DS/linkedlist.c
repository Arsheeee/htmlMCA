#include <stdio.h>
#include<stdlib.h>
#define MAX 100

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;


struct node *createnode(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=value;

    return newnode;
}

void insertatbeg(int value) {
    struct node *newnode=createnode(value);
     newnode->next=head;
     head=newnode;
     printf("inserted at begining successfully");
}

void insertatend(int value) {
    struct node* newnode=createnode(value);
    struct node *temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    } 
    temp->next=newnode;
     printf("inserted at end successfully");
}

void insertatpos(int value) {
    int pos;
    struct node *temp=head;
     struct node *newnode=createnode(value);
     printf("enter the position to insert : ");
     scanf("%d",&pos);
     for(int i=0;i<pos;i++){
        temp=temp->next;
     }
     newnode->next=temp->next;
     temp->next=newnode;
     printf("inserted at the position successfully");


}
void deleteatbeg(){
    struct node *temp=head->next;
    printf("/n %d deleted : ",temp->data);
    head->next=temp->next;
}
void deleteatend(){
    struct node *temp=head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    printf("/n %d deleted : ",temp->data);
    temp->next=NULL;
}
void deleteatpos(){
    struct node *temp=head;
    int pos;
    printf("enter the position to delete : ");
    scanf("%d",&pos);
    for(int i=1;i<pos;i++)
    {
        temp=temp->next;
    }
    printf("/n %d deleted : ",temp->data);
    struct node *eldernode=temp->next->next;
    temp->next=eldernode;

}
void display(){
    struct node *temp=head;
    while(temp !=NULL){
        printf("%d-->",temp->data);
        temp=temp->next;
    }
}

int main() {

    int choice;
    int value;
     
    while (1) {
        printf("\n1. insert at begining 2. insert at end 3. insert at position 4.delete at begening 5.delete at end 6.delete at position 7.display 8.exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {          // guard against bad input
            printf("Invalid input. Exiting.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter number to insert at begining : ");
                scanf("%d",&value);
                insertatbeg(value);
                break;
            case 2:
                printf("Enter number to insert at end : ");
                scanf("%d",&value);
                insertatend(value);
                break;
            case 3:
                printf("Enter value to insert : ");
                scanf("%d",&value);
                insertatpos(value);
                break;
            case 4:
                deleteatbeg();
                break;
            case 5:
                deleteatend();
                break;
            case 6:
                deleteatpos();
                break;
            case 7:
                printf("Cuuernt linkedlist : ");
                display();
                 break;    
            case 8:
                printf("exiting...");
                 return 0;
                 break;    
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}