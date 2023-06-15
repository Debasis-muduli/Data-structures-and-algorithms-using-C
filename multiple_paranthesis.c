#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int top = -1;
char stack[MAX_SIZE];

void push(char item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

int isBalanced(char expression[]) {
    int i = 0;

    while (expression[i] != '\0') {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            push(expression[i]);
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (top == -1 || !isMatchingPair(pop(), expression[i]))
                return 0;
        }
        i++;
    }

    return top == -1;
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", expression);

    if (isBalanced(expression))
        printf("The expression is balanced.\n");
    else
        printf("The expression is not balanced.\n");

    return 0;
}
