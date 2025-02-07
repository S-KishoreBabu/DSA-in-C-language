#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 20

char stack[max];
int top=-1;



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