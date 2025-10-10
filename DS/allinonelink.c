#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>    // For tolower()

struct Node {
    int data;
    struct Node* next;
};

// Create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append node at the end
void appendNode(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Print the linked list
void printList(struct Node* head) {
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Delete first node with given value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", key);
}

// Insert at front
void insertAtFront(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
    printf("Node inserted at the front.\n");
}

// Insert at end
void insertAtEnd(struct Node** head_ref, int data) {
    appendNode(head_ref, data);
    printf("Node inserted at the end.\n");
}

// Insert after a given node value
void insertAfterValue(struct Node* head, int target, int data) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Target value %d not found in the list.\n", target);
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted after value %d.\n", target);
}

int main() {
    struct Node* head = NULL;
    char choice[10];
    int data;

    // Initial creation of linked list
    do {
        printf("Enter data for the node: ");
        scanf("%d", &data);

        appendNode(&head, data);

        printf("Do you want to add another node? (yes/no): ");
        scanf("%s", choice);

        for (int i = 0; choice[i]; i++) {
            choice[i] = tolower(choice[i]);
        }

    } while (strcmp(choice, "yes") == 0);

    printList(head);

    // After creation, allow user to insert/delete nodes
    while (1) {
        printf("\nDo you want to insert, delete, or exit? ");
        scanf("%s", choice);
        for (int i = 0; choice[i]; i++) {
            choice[i] = tolower(choice[i]);
        }

        if (strcmp(choice, "insert") == 0) {
            printf("Enter value to insert: ");
            scanf("%d", &data);

            printf("Where do you want to insert? (front/end/after): ");
            scanf("%s", choice);
            for (int i = 0; choice[i]; i++) {
                choice[i] = tolower(choice[i]);
            }

            if (strcmp(choice, "front") == 0) {
                insertAtFront(&head, data);
            } else if (strcmp(choice, "end") == 0) {
                insertAtEnd(&head, data);
            } else if (strcmp(choice, "after") == 0) {
                int target;
                printf("Enter the value after which to insert: ");
                scanf("%d", &target);
                insertAfterValue(head, target, data);
            } else {
                printf("Invalid insert location.\n");
            }

            printList(head);

        } else if (strcmp(choice, "delete") == 0) {
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            printList(head);

        } else if (strcmp(choice, "exit") == 0) {
            printf("Exiting program.\n");
            break;

        } else {
            printf("Invalid option. Please enter insert, delete, or exit.\n");
        }
    }

    // Free memory before exiting
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
