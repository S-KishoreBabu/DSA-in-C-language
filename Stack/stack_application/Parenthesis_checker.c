#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

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

void pop(){
        top--;
}


bool isValidParenthesis(char *str){
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            push(str[i]);
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            pop();
        }
    }

    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    system("cls");
    char str[]="(A+(B-C)))";
    if(isValidParenthesis(str)){
        printf("\n Valid Expression");
    }
    else{
        printf("\n Invalid Expression");
    }
    return 0;
}