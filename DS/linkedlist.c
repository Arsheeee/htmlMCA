#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create new node
struct node* createnode(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// 1. Insert at beginning
void insertatbeg(int value) {
    struct node *newnode = createnode(value);
    newnode->next = head;
    head = newnode;
    printf("%d inserted at beginning\n", value);
}

// 2. Insert at end
void insertatend(int value) {
    struct node *newnode = createnode(value);
    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("%d inserted at end\n", value);
}

// 3. Insert at position (1-based)
void insertatpos(int value) {
    int pos;
    printf("Enter position (1-based): ");
    scanf("%d", &pos);
    if (pos == 1) {
        insertatbeg(value);
        return;
    }
    
    struct node *newnode = createnode(value);
    struct node *temp = head;
    for (int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
        printf("%d inserted at position %d\n", value, pos);
    }
}

// 4. Delete at beginning
void deleteatbeg() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    printf("%d deleted from beginning\n", temp->data);
    free(temp);
}

// 5. Delete at end
void deleteatend() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        printf("%d deleted from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("%d deleted from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// 6. Delete at position
void deleteatpos() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    
    if (pos == 1) {
        deleteatbeg();
        return;
    }
    
    struct node *temp = head;
    for (int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
    } else {
        struct node *todelete = temp->next;
        temp->next = temp->next->next;
        printf("%d deleted from position %d\n", todelete->data, pos);
        free(todelete);
    }
}

// 7. Display
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n1. Insert Begin  2. Insert End  3. Insert Pos  4. Delete Begin  5. Delete End  6. Delete Pos  7. Display  8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); insertatbeg(value); break;
            case 2: printf("Enter value: "); scanf("%d", &value); insertatend(value); break;
            case 3: printf("Enter value: "); scanf("%d", &value); insertatpos(value); break;
            case 4: deleteatbeg(); break;
            case 5: deleteatend(); break;
            case 6: deleteatpos(); break;
            case 7: display(); break;
            case 8: printf("Bye!\n"); return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}