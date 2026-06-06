#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* append(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

Node* removeAll(Node* head, int x) {
    Node *temp, *prev;

    while (head != NULL && head->data == x) {
        temp = head;
        head = head->next;
        free(temp);
    }

    prev = head;
    temp = head;

    while (temp != NULL) {
        if (temp->data == x) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 2);
    head = append(head, 4);
    head = append(head, 2);

    printList(head);

    head = removeAll(head, 2);

    printList(head);

    return 0;
}