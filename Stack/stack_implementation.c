#include <stdio.h> // Not completed - stack implementation
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

bool isnotempty()
{
    if (top != -1)
    {
        return true;
    }
    return false;
}

bool isnotfull()
{
    if (top == MAXSIZE - 1)
    {
        return false;
    }
    return true;
}

void push(int val)
{
    if (top != MAXSIZE - 1)
    {
        stack[++top] = val;
    }
    else
    {
        printf("\n stack is full");
    }
}

int pop()
{
    if (top!=-1)
    {
        int temp = stack[top];
        top--;
        return temp;
    }
    printf("\n stack is empty");
    return -1;
}

int peek()
{
    if (isnotempty)
    {
        return stack[top];
    }
    printf("\n stack is empty");
}

void posofStack()
{
    printf("\n Top = %d ", top);
}

void display()
{
    if (isnotempty)
    {
        printf("\n\n");
        for (int i = top; i >= 0; i--)
        {
            printf("\n | %d | ", stack[i]);
        }
    }
    else
    {
        printf("\n stack is empty");
    }
}

int main()
{
    int n, x;
    printf("\n Choose the option :-  \n 1) push()  2) pop()  3) peek()  4) display  5) position of top 6) Exit");
    do
    {
        printf("\n Enter option : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter  the value to push in stack :- ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            x = peek();
            if(top != -1){printf("Top value = %d", x);}
            break;
        case 4:
            if (top != -1)
            {
                display();
            }
            else
            {
                printf("Stack is empty");
            }
            break;
        case 5:
            posofStack();
            break;
        default:
            printf("\n You have entered wrong option");
        }
    } while (n!=6);
    return 0;
}
