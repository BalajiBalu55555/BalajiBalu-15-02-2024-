#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
int isOperator(char c) { 
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int evaluatePostfix(char *postfix) {
    Stack s;
    initStack(&s);
    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(&s, postfix[i] - '0');
        } else if (isOperator(postfix[i])) {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (postfix[i]) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
            }
        }
        i++;
    }
    return pop(&s);
}
int main() {
    char postfix[MAX_SIZE];
    printf("Enter postfix expression: ");
    fgets(postfix, MAX_SIZE, stdin);
    postfix[strlen(postfix) - 1] = '\0';

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
} 
