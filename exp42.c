#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int is_empty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int is_full(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++(stack->top)] = value;
}

int pop(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

int peek(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->items[stack->top];
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Top element: %d\n", peek(&stack));

    printf("Popping elements:\n");
    while (!is_empty(&stack)) {
        printf("%d\n", pop(&stack));
    }

    return 0;
}
