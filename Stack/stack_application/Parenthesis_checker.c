//Complete - Checking the valid parenthesis using stack

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define max 60

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
            printf("\n %c-> %d\n",str[i],top);
        }
        if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(top==-1){
                return false;
            }
            if((str[i]==')' && ( stack[top]=='{' || stack[top]=='[' ))|| 
                (str[i]=='}' && ( stack[top]=='(' || stack[top]=='[' ))||
                (str[i]==']' && ( stack[top]=='{' || stack[top]=='('))){
                return false;
            }else{
                printf("\n top = %d",top);
                pop();
            }
        }
    }
    if(top>-1){
        return false;
    }
    return true;

}
int main(){
    system("cls");
    char str[]="(a[b{c]d}e)";
    if(isValidParenthesis(str)){
        printf("\n Valid Expression");
    }
    else{
        printf("\n Invalid Expression");
    }
    return 0;
}