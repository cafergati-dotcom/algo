#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) q->rear = NULL;
    
    free(temp);
    return data;
}

void filterListWithQueue(struct Node** head, int target) {
    struct Queue* q = createQueue();
    struct Node* curr = *head;

    // 1. Traverse list and enqueue items that ARE NOT the target
    while (curr != NULL) {
        if (curr->data != target) {
            enqueue(q, curr->data);
        }
        curr = curr->next;
    }

    // 2. Free the old list to prevent memory leaks
    while (*head != NULL) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    // 3. Rebuild the list from the Queue
    struct Node* tail = NULL;
    while (q->front != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = dequeue(q);
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Free the queue structure itself
    free(q);
}

void display(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int toRemove;

    // Fixed the manual list creation logic
    int vals[] = {20, 5, 15, 5, 10, 5};
    for(int i=0; i<6; i++) {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = vals[i]; 
        n->next = head; 
        head = n;
    }

    printf("Original List: ");
    display(head);

    printf("Enter value to delete: ");
    if(scanf("%d", &toRemove) != 1) return 1;

    filterListWithQueue(&head, toRemove);

    printf("Filtered List: ");
    display(head);

    return 0;
}
