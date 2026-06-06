#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void push(Node** top, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}


int pop(Node** top) {
    if (*top == NULL) return -1;
    Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}


typedef struct {
    Node* s1; 
    Node* s2; 
} Queue;

void initQueue(Queue* q) {
    q->s1 = NULL;
    q->s2 = NULL;
}


void enqueue(Queue* q, int val) {
    push(&(q->s1), val);
    printf("Enfile (s1): %d\n", val);
}


int dequeue(Queue* q) {
    if (q->s1 == NULL && q->s2 == NULL) {
        printf("Erreur : La file est vide !\n");
        return -1;
    }

    
    if (q->s2 == NULL) {
        while (q->s1 != NULL) {
            push(&(q->s2), pop(&(q->s1)));
        }
    }

    return pop(&(q->s2));
}

void displayStacks(Queue* q) {
    Node* temp;
    printf("s1 : ");
    temp = q->s1;
    while(temp) { printf("%d -> ", temp->data); 
    temp = temp->next; }
    printf("NULL\n");

    printf("s2 : ");
    temp = q->s2;
    while(temp) { printf("%d -> ", temp->data);
     temp = temp->next; }
    printf("NULL\n\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    displayStacks(&q);

    printf("Defile : %d\n", dequeue(&q));
    displayStacks(&q);

    enqueue(&q, 4);
    displayStacks(&q);


    return 0;
}