#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

// Insert at the beginning
void insertionatbegin(struct node** headdd) {
    int value;
    printf("Enter the value to insert at beginning: ");
    scanf("%d", &value);

    struct node* front_node = (struct node*)malloc(sizeof(struct node));
    front_node->data = value;
    front_node->link = *headdd;
    *headdd = front_node;

    printf("%d inserted at the beginning.\n", value);
}

// Insert at the end
void insertatend(struct node** headd) {
    int value;
    printf("Enter the value to insert at end: ");
    scanf("%d", &value);

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->link = NULL;

    if (*headd == NULL) {  // Empty list
        *headd = new_node;
        printf("%d inserted as the first node.\n", value);
        return;
    }

    struct node* temp = *headd;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = new_node;

    printf("%d inserted at the end.\n", value);
}


void insertrandom(struct node** head) {
    int value, pos;
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    printf("Enter the value after which to insert %d: ", value);
    scanf("%d", &pos);

    struct node* temp = *head;
    while (temp != NULL && temp->data != pos) {
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Value %d not found. Cannot insert %d.\n", pos, value);
        return;
    }

    struct node* rnode = (struct node*)malloc(sizeof(struct node));
    rnode->data = value;
    rnode->link = temp->link;
    temp->link = rnode;

    printf("%d inserted after %d.\n", value, pos);
}


void deleteatbegin(struct node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete at beginning.\n");
        return;
    }

    struct node* temp = *head;
    *head = temp->link;
    printf("%d has been deleted from the beginning.\n", temp->data);
    free(temp);
}


void deleteatend(struct node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete at end.\n");
        return;
    }

    if ((*head)->link == NULL) {
        printf("%d has been deleted from the end.\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct node* temp = *head;
    while (temp->link->link != NULL) {
        temp = temp->link;
    }
    printf("%d has been deleted from the end.\n", temp->link->data);
    free(temp->link);
    temp->link = NULL;
}

// Delete a node by value (middle deletion)
void deleteatrandom(struct node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    int value;
    printf("Enter the value to delete: ");
    scanf("%d", &value);

    struct node* temp = *head;
    struct node* prev = NULL;

    // If head node holds the value
    if (temp->data == value) {
        *head = temp->link;
        printf("%d has been deleted from the list.\n", value);
        free(temp);
        return;
    }

    // Search for the value in the list
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->link = temp->link;
    printf("%d has been deleted from the list.\n", value);
    free(temp);
}


void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;


    insertionatbegin(&head);  
    insertatend(&head);      
    insertatend(&head);       
    insertionatbegin(&head);  
    display(head);

    insertrandom(&head);    
    display(head);

    deleteatbegin(&head);
    display(head);

    deleteatend(&head);
    display(head);

    deleteatrandom(&head);
    display(head);

    return 0;
}
