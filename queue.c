#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Queue structure to manage Head and Tail
struct Queue {
    struct Node *front, *rear;
};

// Initialize an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue: Add to the end
void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue: Remove from the front
int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

void append(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}
void removeValuesUsingQueue(struct Node** head, int target) {
    struct Queue* q = createQueue();
    struct Node* curr = *head;

    // Step 1: Traverse list and Enqueue only "kept" values
    while (curr != NULL) {
        if (curr->data != target) {
            enqueue(q, curr->data);
        }
        curr = curr->next;
    }
    

