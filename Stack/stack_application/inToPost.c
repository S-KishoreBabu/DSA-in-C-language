// * completed : Infix to postfix Expresion

// ! suitable for valid expression

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

bool isHighPriority(char,char);


char *infixToPostfix(char *arr){
    char stack[20],*result = (char*)malloc(sizeof(arr+1));
    int top = -1,size = -1;
    for(int i = 0;i<strlen(arr);i++){
        if(isalpha(arr[i])){
            result[++size]=arr[i];
        }
        else if(arr[i]==')'){
            while(stack[top]!='('){
                result[++size]=stack[top--];
            }
            top--;
        }
        else{
            if(arr[i]=='('){
                stack[++top] = arr[i];
            }else{
                while(top != -1 &&  stack[top]!='(' && !isHighPriority(arr[i],stack[top])){
                    result[++size]=stack[top--];
                }
                stack[++top] = arr[i];
            }
        }
    }
    for(int i = top;i>=0;i--){
        result[++size] = stack[i];
    }
    result[++size]='\0';
    return result;
}

void getPriority(char exp, int *num){
    switch(exp){
        case '+':
        case '-':
            *num = 1;
            break;
        case '*':
        case '/':
        case '%':
            *num = 2;
            break;
        case '^':
            *num = 3;
            break;
    }
}

bool isHighPriority(char a,char top){
    int priorityA, priorityTop;
    getPriority(a,&priorityA);
    getPriority(top,&priorityTop);
    return (priorityTop<=priorityA)?true:false;
}

int main(){
    char exp[] = "a-(b/c+(d%e*f)/g)*h";
    printf("\n postfix : %s",infixToPostfix(exp));
    return 0;
}