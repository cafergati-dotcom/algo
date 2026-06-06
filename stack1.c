#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

// push
void push1(int x) {
    s1[++top1] = x;
}

void push2(int x) {
    s2[++top2] = x;
}

// pop
int pop1() {
    return s1[top1--];
}

int pop2() {
    return s2[top2--];
}

// enqueue
void enqueue(int x) {
    push1(x);
}

// dequeue
int dequeue() {
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }
    return pop2();
}

// display الحالة
void display() {
    int i;
    printf("S1: ");
    for (i = 0; i <= top1; i++) printf("%d ", s1[i]);

    printf(" | S2: ");
    for (i = 0; i <= top2; i++) printf("%d ", s2[i]);

    printf("\n");
}

int main() {
    enqueue(10);
    display();

    enqueue(20);
    display();

    enqueue(30);
    display();

    printf("Dequeue: %d\n", dequeue());
    display();

    enqueue(40);
    display();

    printf("Dequeue: %d\n", dequeue());
    display();

    return 0;
}