#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 20

char stack[max];
int top=-1;

void push(char ch){
    if(top!=max-1){
        stack[++top]=ch;
    }
    else{
        printf("Stack is full\n");
    }
}

int main(){
    system("cls");
    char str[]="(A+(B-C))";
    if(isValidParenthesis(str)){
        printf("\n Valid Expression");
    }
    else{
        printf("\n Invalid Expression");
    }
    return 0;
}