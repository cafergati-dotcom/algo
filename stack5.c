#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

void removeValues(int* list, int size, int target) {
    struct Stack* stack = createStack(size);

    // Push only elements that ARE NOT the target
    for (int i = 0; i < size; i++) {
        if (list[i] != target) {
            push(stack, list[i]);
        }
    }

    // Print the results from the stack
    printf("Updated List: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");

    // Clean up memory
    free(stack->array);
    free(stack);
}

int main() {
    int myList[] = {10, 20, 30, 20, 40, 20, 50};
    int n = sizeof(myList) / sizeof(myList[0]);
    int target;

    printf("Original List: 10 20 30 20 40 20 50\n");
    printf("Enter value to remove: ");
    scanf("%d", &target);

    removeValues(myList, n, target);

    return 0;
}