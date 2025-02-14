// * Complete - Checking the valid parenthesis using stack

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

#define max 60

char stack[max];
int top = -1;

void push(char ch) {
    if (top != max - 1) {
        stack[++top] = ch;
    } else {
        printf("Stack is full\n");
    }
}

char pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return '\0'; // Return a null character or handle error appropriately
    }
    char temp = stack[top];
    top--;
    return temp;
}

bool isValidParenthesis(char *str) { // @param str: string containing parenthesis
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
        }
        if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1) {
                return false; // Return false if stack is empty
            }

            if ((str[i] == ')' && (stack[top] == '{' || stack[top] == '[')) ||
                (str[i] == '}' && (stack[top] == '(' || stack[top] == '[')) ||
                (str[i] == ']' && (stack[top] == '{' || stack[top] == '('))) {
                return false;
            } else {
                pop();
            }
        }
    }
    if (top > -1) {
        top = -1;
        return false;
    }
    top = -1;
    return true;
}

char postfix[100]; // Increased size to handle larger expressions
int pj = -1;

void addstr(char ch) {
    postfix[++pj] = ch;
}

char *getstr() {
    return postfix;
}

int getPrecidence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '/' || ch == '*' || ch == '%') {
        return 2;
    } else if (ch == '^') {
        return 3;
    } else {
        return 0;
    }
}

bool checkpriority(char ch) {
    int a = getPrecidence(ch);
    int b = getPrecidence(stack[top]);
    if (top == -1) return true; // Check if stack is empty
    if (a > b) {
        return true;
    } else if (a == b && (ch == '+' || ch == '-' || ch == '*' || ch == '/')) {
        return true; // Handle left associative operators
    }
    return false;
}

char *infixToPostfix(char *s) { // @param s: string containing infix expression
    memset(postfix, 0, sizeof(postfix)); // Clear the postfix array

    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (!isalpha(s[i])) {
            if (top == -1 || s[i] == '(') {
                push(s[i]);
            } else if (s[i] == ')') {
                while (top != -1 && stack[top] != '(') {
                    addstr(pop());
                }
                pop();
            } else {
                if (checkpriority(s[i])) {
                    push(s[i]);
                } else {
                    while (top != -1 && !checkpriority(s[i]) && stack[top] != '(') {
                        addstr(pop());
                    }
                    if (stack[top] == '(') pop();
                    if (checkpriority(s[i])) push(s[i]);
                }
            }
        } else {
            addstr(s[i]);
        }
    }
    while (top > -1) {
        addstr(pop());
    }

    return getstr();
}

int main() {
    system("cls"); // clear the console
    char str[100]; // Declare a string to hold user input
    printf("Enter an infix expression: ");
    fgets(str, sizeof(str), stdin); // Get user input

    if (isValidParenthesis(str)) {
        printf("\n Postfix : %s", infixToPostfix(str));
    } else {
        printf("\n Invalid Expression");
    }
    return 0;
}
