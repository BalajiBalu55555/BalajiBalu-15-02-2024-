#include <stdio.h>  
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;
void initStack(Stack *s) {
    s->top = -1;
}
void push(Stack *s, int data) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1; 
    }
    return s->arr[s->top--];
}
int main() {
    Stack s;
    initStack(&s);

    push(&s, 5);
    push(&s, 15);
    push(&s, 25);

    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s)); 

    return 0;
} 
