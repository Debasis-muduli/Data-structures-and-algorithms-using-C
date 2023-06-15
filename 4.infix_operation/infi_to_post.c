#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

void infixToPostfix();
int getPrecedence(char);
void push(char);
char pop();
int isEmpty();
int isFull();

char stack[MAX_SIZE];
char infix[MAX_SIZE];
char postfix[MAX_SIZE];
int top = -1;

int main() {
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix();
    printf("%s\n", postfix);
    return 0;
}

void infixToPostfix() {
    int i, j = 0;
    char currentSymbol, nextSymbol;

    for (i = 0; i < strlen(infix); i++) {
        currentSymbol = infix[i];

        switch (currentSymbol) {
            case '(':
                push(currentSymbol);
                break;

            case ')':
                while ((nextSymbol = pop()) != '(')
                    postfix[j++] = nextSymbol;
                break;

            case '+':
            case '-':
            case '*':
            case '^':
                while (!isEmpty() && getPrecedence(stack[top]) >= getPrecedence(currentSymbol))
                    postfix[j++] = pop();
                push(currentSymbol);
                break;

            default:
                postfix[j++] = currentSymbol;
        }
    }

    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int getPrecedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;

        case '/':
        case '*':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}

void push(char operator) {
    if (isFull()) {
        printf("Stack is full!\n");
    } else {
        top++;
        stack[top] = operator;
    }
}

char pop() {
    char ch;
    if (isEmpty()) {
        return -1;
    } else {
        ch = stack[top];
        top--;
        return ch;
    }
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}
