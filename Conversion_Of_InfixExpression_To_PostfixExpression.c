#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;
void initStack(Stack *s) {
    s->top = -1;
}
void push(Stack *s, char data) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}
char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
} 
int isOperator(char c) { 
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int precedence(char c) {
    if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);

    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (s.top != -1 && s.arr[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            if (s.top != -1 && s.arr[s.top] == '(') {
                pop(&s); 
            }
        } else {
            while (s.top != -1 && precedence(infix[i]) <= precedence(s.arr[s.top])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
        i++;
    }
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; 

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
