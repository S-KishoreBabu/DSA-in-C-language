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

bool isValidParentheses(char *str) { 
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
        }
        if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1) {
                return false; // Return false if stack is empty
            }

            if ((str[i] == ')' && (stack[top] !='(')) ||
                (str[i] == '}' && (stack[top] != '{')) ||
                (str[i] == ']' && (stack[top] != '['))) {
                return false;
            } else {
                pop();
            }
        }
    }
    if (top > -1) {
        return false;
    }
    return true;
}

int main() {
    char exp[]="]";
    if(isValidParentheses(exp)){
        printf("Valid");
    }
    else{
        printf("Not Valid");
    }
    return 0;
}
