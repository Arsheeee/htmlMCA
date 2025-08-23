
#include <stdio.h>
#define max 10

int stack[max];
int top = -1;

int isempty() {
    return (top == -1);
}

int isfull() {
    return (top == max - 1);
}

void push(int value) {
    if (isfull()) {
        printf("stack is full\n");
    } else {
        stack[++top] = value;
        printf("%d pushed into the stack\n", value);
    }
}

void display() {
    if (isempty()) {
        printf("stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    return 0;
}
