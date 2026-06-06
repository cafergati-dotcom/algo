#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void init(Stack* s) {
    s->top = NULL;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (isEmpty(s)) return -1;
    Node* temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);
    return val;
}

void printStack(Node* top) {
    Node* temp = top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void visualize(Stack* s1, Stack* s2, char* msg) {
    printf("\n=== %s ===\n", msg);
    printf("Stack1: ");
    printStack(s1->top);
    printf("\nStack2: ");
    printStack(s2->top);
    printf("\n");
}

void enqueue(Stack* s1, Stack* s2, int x) {
    push(s1, x);
    char msg[50];
    sprintf(msg, "Enqueue(%d)", x);
    visualize(s1, s2, msg);
}

int dequeue(Stack* s1, Stack* s2) {
    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            push(s2, pop(s1));
            visualize(s1, s2, "Transferring");
        }
    }

    if (isEmpty(s2)) return -1;

    int val = pop(s2);
    char msg[50];
    sprintf(msg, "Dequeue() → %d", val);
    visualize(s1, s2, msg);

    return val;
}

int main() {
    Stack s1, s2;
    init(&s1);
    init(&s2);

    enqueue(&s1, &s2, 10);
    enqueue(&s1, &s2, 20);
    enqueue(&s1, &s2, 30);

    dequeue(&s1, &s2);
    enqueue(&s1, &s2, 40);
    dequeue(&s1, &s2);
    dequeue(&s1, &s2);

    return 0;
}