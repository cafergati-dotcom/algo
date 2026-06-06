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

void splitEvenOdd(Node* head, Node** evenList, Node** oddList) {
    Node *evenTail = NULL, *oddTail = NULL, *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        temp->next = NULL;

        if (temp->data % 2 == 0) {
            if (*evenList == NULL) {
                *evenList = temp;
                evenTail = temp;
            } else {
                evenTail->next = temp;
                evenTail = temp;
            }
        } else {
            if (*oddList == NULL) {
                *oddList = temp;
                oddTail = temp;
            } else {
                oddTail->next = temp;
                oddTail = temp;
            }
        }
    }
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
    Node* evenList = NULL;
    Node* oddList = NULL;

    Node* n1 = createNode(1);
    Node* n2 = createNode(2);
    Node* n3 = createNode(3);
    Node* n4 = createNode(4);
    Node* n5 = createNode(5);
    Node* n6 = createNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    head = n1;

    splitEvenOdd(head, &evenList, &oddList);

    printf("Even list:\n");
    printList(evenList);

    printf("Odd list:\n");
    printList(oddList);

    return 0;
}